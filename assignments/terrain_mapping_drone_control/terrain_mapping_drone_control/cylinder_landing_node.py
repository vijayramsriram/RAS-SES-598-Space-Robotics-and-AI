#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from px4_msgs.msg import VehicleCommand, VehicleControlMode, OffboardControlMode, TrajectorySetpoint
from nav_msgs.msg import Odometry
import math
import time
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy

class CylinderLandingNode(Node):
    def __init__(self):
        super().__init__('cylinder_landing_node')

        # Initialize CV bridge for image conversion
        self.cv_bridge = CvBridge()
        
        # Create debug image publisher
        self.debug_pub = self.create_publisher(Image, '/debug/detection', 10)
        
        # Create PX4 publishers with appropriate QoS
        qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            durability=QoSDurabilityPolicy.TRANSIENT_LOCAL,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10
        )
        
        self.vehicle_command_publisher = self.create_publisher(
            VehicleCommand, '/fmu/in/vehicle_command', qos_profile)
        self.offboard_control_mode_publisher = self.create_publisher(
            OffboardControlMode, '/fmu/in/offboard_control_mode', qos_profile)
        self.trajectory_setpoint_publisher = self.create_publisher(
            TrajectorySetpoint, '/fmu/in/trajectory_setpoint', qos_profile)
        
        # Create subscribers
        self.depth_subscriber = self.create_subscription(
            Image, '/drone/camera/depth', self.depth_callback, 10)
        self.vehicle_odometry_subscriber = self.create_subscription(
            Odometry, '/model/x500_gimbal_0/odometry_with_covariance', self.vehicle_odometry_callback, qos_profile)

        # Initialize state variables
        self.current_position = None
        self.current_orientation = None
        self.flight_state = 'INIT'
        self.start_position = None
        self.cylinder_position = [5.0, 0.0, 5.0]  # Cylinder is 5m in front and centered at z=5
        self.spiral_start_time = None
        self.spiral_radius = 1.5  # 3m diameter spiral
        self.spiral_height = 11.0  # Target height
        self.spiral_speed = 0.3  # rad/s - Reduced for smoother motion
        self.spiral_vertical_speed = 0.3  # m/s - Reduced for smoother ascent
        self.state_transition_time = None
        self.position_hold_duration = 2.0  # seconds to hold position before state transition
        
        # Timer for control loop
        self.create_timer(0.1, self.control_loop)

    def vehicle_odometry_callback(self, msg):
        """Store vehicle position and orientation from odometry."""
        self.current_position = [
            float(msg.pose.pose.position.x),
            float(msg.pose.pose.position.y),
            float(msg.pose.pose.position.z)
        ]
        self.current_orientation = [
            float(msg.pose.pose.orientation.x),
            float(msg.pose.pose.orientation.y),
            float(msg.pose.pose.orientation.z),
            float(msg.pose.pose.orientation.w)
        ]
        
        # Store start position on first callback
        if self.start_position is None:
            self.start_position = self.current_position.copy()

    def publish_offboard_control_mode(self):
        """Publish offboard control mode."""
        msg = OffboardControlMode()
        msg.position = True
        msg.velocity = False
        msg.acceleration = False
        msg.attitude = False
        msg.body_rate = False
        msg.timestamp = int(self.get_clock().now().nanoseconds / 1000)
        self.offboard_control_mode_publisher.publish(msg)

    def publish_vehicle_command(self, command, param1=0.0, param2=0.0):
        """Publish vehicle command."""
        msg = VehicleCommand()
        msg.command = command
        msg.param1 = float(param1)
        msg.param2 = float(param2)
        msg.target_system = 1
        msg.target_component = 1
        msg.source_system = 1
        msg.source_component = 1
        msg.from_external = True
        msg.timestamp = int(self.get_clock().now().nanoseconds / 1000)
        self.vehicle_command_publisher.publish(msg)

    def publish_trajectory_setpoint(self, x, y, z, yaw):
        """Publish trajectory setpoint."""
        msg = TrajectorySetpoint()
        msg.position = [float(x), float(y), float(z)]
        msg.yaw = float(yaw)
        msg.timestamp = int(self.get_clock().now().nanoseconds / 1000)
        self.trajectory_setpoint_publisher.publish(msg)

    def arm(self):
        """Send arm command."""
        # Send the command multiple times to ensure it's received
        for _ in range(3):
            self.publish_vehicle_command(VehicleCommand.VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0)
            time.sleep(0.1)
        self.get_logger().info('Arm command sent')

    def start_offboard_mode(self):
        """Start offboard control mode."""
        # Send the command multiple times to ensure it's received
        for _ in range(3):
            self.publish_vehicle_command(VehicleCommand.VEHICLE_CMD_DO_SET_MODE, 1.0, 6.0)
            time.sleep(0.1)
        self.get_logger().info('Offboard mode enabled')

    def calculate_spiral_position(self, t):
        """Calculate position on spiral trajectory."""
        angle = float(self.spiral_speed * t)
        
        # Gradually increase radius from 0 to target radius
        radius_ramp_time = 5.0  # seconds to reach full radius
        current_radius = float(min(self.spiral_radius, (t / radius_ramp_time) * self.spiral_radius))
        
        # Calculate position relative to cylinder center
        x = float(self.cylinder_position[0] + current_radius * math.cos(angle))
        y = float(self.cylinder_position[1] + current_radius * math.sin(angle))
        
        # Smooth height transition
        height_ramp_time = 3.0  # seconds to start ascending
        if t < height_ramp_time:
            target_z = float(self.current_position[2])  # Hold current height initially
        else:
            ascent_t = t - height_ramp_time
            target_z = float(min(self.spiral_height, 
                               self.current_position[2] + self.spiral_vertical_speed * ascent_t))
        
        # Calculate yaw to always point towards cylinder
        dx = self.cylinder_position[0] - x
        dy = self.cylinder_position[1] - y
        yaw = float(math.atan2(dy, dx))
        
        return x, y, target_z, yaw

    def is_position_reached(self, target_x, target_y, target_z, threshold=0.3):
        """Check if drone has reached target position within threshold."""
        if not self.current_position:
            return False
        dx = self.current_position[0] - target_x
        dy = self.current_position[1] - target_y
        dz = self.current_position[2] - target_z
        return (math.sqrt(dx*dx + dy*dy) < threshold and 
                abs(dz) < threshold)

    def control_loop(self):
        """Main control loop state machine."""
        if not self.current_position:
            return

        # Publish offboard control mode
        self.publish_offboard_control_mode()

        if self.flight_state == 'INIT':
            # Hold position while transitioning to offboard mode
            self.publish_trajectory_setpoint(
                self.current_position[0],
                self.current_position[1],
                self.current_position[2],
                0.0
            )
            if self.state_transition_time is None:
                self.start_offboard_mode()
                self.arm()
                self.state_transition_time = time.time()
            elif time.time() - self.state_transition_time > self.position_hold_duration:
                self.flight_state = 'TAKEOFF'
                self.state_transition_time = None
                self.get_logger().info('Initiating takeoff')

        elif self.flight_state == 'TAKEOFF':
            # Takeoff to 5m
            target_x = self.start_position[0]
            target_y = self.start_position[1]
            target_z = 5.0
            
            self.publish_trajectory_setpoint(target_x, target_y, target_z, 0.0)
            
            if self.is_position_reached(target_x, target_y, target_z):
                if self.state_transition_time is None:
                    self.state_transition_time = time.time()
                elif time.time() - self.state_transition_time > self.position_hold_duration:
                    self.flight_state = 'APPROACH'
                    self.state_transition_time = None
                    self.get_logger().info('Approaching cylinder')

        elif self.flight_state == 'APPROACH':
            # Move to cylinder position at 5m height
            target_x = self.cylinder_position[0]
            target_y = self.cylinder_position[1]
            target_z = 5.0
            
            self.publish_trajectory_setpoint(target_x, target_y, target_z, 0.0)
            
            if self.is_position_reached(target_x, target_y, target_z):
                if self.state_transition_time is None:
                    self.state_transition_time = time.time()
                elif time.time() - self.state_transition_time > self.position_hold_duration:
                    self.flight_state = 'SPIRAL'
                    self.spiral_start_time = time.time()
                    self.state_transition_time = None
                    self.get_logger().info('Starting spiral trajectory')

        elif self.flight_state == 'SPIRAL':
            t = time.time() - self.spiral_start_time
            x, y, z, yaw = self.calculate_spiral_position(t)
            self.publish_trajectory_setpoint(x, y, z, yaw)
            
            if z >= self.spiral_height:
                if self.state_transition_time is None:
                    self.state_transition_time = time.time()
                elif time.time() - self.state_transition_time > self.position_hold_duration:
                    self.flight_state = 'RETURN'
                    self.state_transition_time = None
                    self.get_logger().info('Returning to start position')

        elif self.flight_state == 'RETURN':
            # Return to start position at current height
            target_x = self.start_position[0]
            target_y = self.start_position[1]
            target_z = self.current_position[2]
            
            self.publish_trajectory_setpoint(target_x, target_y, target_z, 0.0)
            
            if self.is_position_reached(target_x, target_y, target_z):
                if self.state_transition_time is None:
                    self.state_transition_time = time.time()
                elif time.time() - self.state_transition_time > self.position_hold_duration:
                    self.flight_state = 'LAND'
                    self.state_transition_time = None
                    self.get_logger().info('Starting landing')

        elif self.flight_state == 'LAND':
            # Land at start position
            target_x = self.start_position[0]
            target_y = self.start_position[1]
            target_z = 0.0
            
            self.publish_trajectory_setpoint(target_x, target_y, target_z, 0.0)
            
            if self.current_position[2] < 0.2:
                if self.state_transition_time is None:
                    self.state_transition_time = time.time()
                elif time.time() - self.state_transition_time > self.position_hold_duration:
                    self.flight_state = 'LANDED'
                    self.get_logger().info('Landing complete')
                    # Disarm
                    self.publish_vehicle_command(
                        VehicleCommand.VEHICLE_CMD_COMPONENT_ARM_DISARM, 0.0)

    def detect_lines(self, depth_image, visualization_image):
        """Detect lines in depth image and draw on visualization."""
        # Create edge image for line detection
        edges = cv2.Canny(
            cv2.convertScaleAbs(depth_image, alpha=50), 
            threshold1=50, 
            threshold2=150
        )
        
        # Detect lines using probabilistic Hough transform
        lines = cv2.HoughLinesP(
            edges,
            rho=1,
            theta=np.pi/180,
            threshold=50,
            minLineLength=50,
            maxLineGap=10
        )
        
        if lines is not None:
            # Draw detected lines in red
            for line in lines:
                x1, y1, x2, y2 = line[0]
                # Calculate line length and angle
                length = np.sqrt((x2 - x1)**2 + (y2 - y1)**2)
                angle = np.arctan2(y2 - y1, x2 - x1) * 180 / np.pi
                
                # Draw line in red
                cv2.line(visualization_image, (x1, y1), (x2, y2), (0, 0, 255), 2)
                
                # Add text with line properties
                cv2.putText(visualization_image,
                    f'L:{length:.1f} A:{angle:.1f}',
                    (x1, y1 - 10),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    0.5,
                    (0, 0, 255),  # Red text
                    1
                )
            
            # Add number of detected lines
            cv2.putText(visualization_image,
                f'Lines: {len(lines)}',
                (10, 60),  # Position below rectangle info
                cv2.FONT_HERSHEY_SIMPLEX,
                1,
                (0, 0, 255),  # Red text
                2
            )
        
        return lines

    def depth_callback(self, msg):
        """Process depth camera image and fit rectangle and lines."""
        try:
            # Convert ROS Image message to OpenCV format
            depth_image = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='32FC1')
            
            # Create a binary mask for valid depth values
            valid_mask = np.logical_and(
                np.isfinite(depth_image),
                np.logical_and(depth_image > 0.5, depth_image < 10.0)
            )
            valid_mask = valid_mask.astype(np.uint8) * 255
            
            # Find contours in the binary mask
            contours, _ = cv2.findContours(valid_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            
            # Create colored depth image for visualization
            visualization = cv2.applyColorMap(
                cv2.convertScaleAbs(depth_image, alpha=0.08), 
                cv2.COLORMAP_JET
            )
            
            # Draw rectangle detection in green
            if contours:
                # Find the largest contour
                largest_contour = max(contours, key=cv2.contourArea)
                
                # Fit a rectangle to the largest contour
                rect = cv2.minAreaRect(largest_contour)
                box = cv2.boxPoints(rect)
                box = box.astype(np.intp)  # Use intp instead of int0
                
                # Draw the rectangle in green
                cv2.drawContours(visualization, [box], 0, (0, 255, 0), 2)
                
                # Calculate and display rectangle properties
                center, (width, height), angle = rect
                cv2.putText(visualization, 
                    f'Rectangle: W:{width:.1f} H:{height:.1f} A:{angle:.1f}',
                    (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            
            # Detect and draw lines in red
            self.detect_lines(depth_image, visualization)
            
            # Add flight state to visualization
            cv2.putText(visualization,
                f'State: {self.flight_state}',
                (10, 90),  # Position below other info
                cv2.FONT_HERSHEY_SIMPLEX,
                1,
                (255, 255, 255),  # White text
                2
            )
            
            # Publish combined debug image
            debug_msg = self.cv_bridge.cv2_to_imgmsg(visualization, encoding='bgr8')
            debug_msg.header = msg.header
            self.debug_pub.publish(debug_msg)
            
        except Exception as e:
            self.get_logger().error(f'Error processing depth image: {str(e)}')

def main():
    rclpy.init()
    node = CylinderLandingNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 