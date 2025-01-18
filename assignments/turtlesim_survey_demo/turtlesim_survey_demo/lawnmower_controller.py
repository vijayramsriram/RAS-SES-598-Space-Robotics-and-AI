import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import numpy as np
import math
from collections import deque


class LawnmowerController(Node):
    def __init__(self):
        super().__init__('lawnmower_controller')
        
        # Create publisher and subscriber
        self.velocity_publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.pose_subscriber = self.create_subscription(Pose, '/turtle1/pose', self.pose_callback, 10)
        
        # Controller parameters
        self.Kp_linear = 10.0  # Proportional gain for linear velocity
        self.Kd_linear = 0.1   # Derivative gain for linear velocity
        self.Kp_angular = 5.0  # Proportional gain for angular velocity
        self.Kd_angular = 0.2  # Derivative gain for angular velocity
        
        # Lawnmower pattern parameters
        self.spacing = 1.0  # Spacing between lines
        self.waypoints = self.generate_waypoints()
        self.current_waypoint = 0
        
        # Cross-track error calculation
        self.cross_track_errors = deque(maxlen=1000)  # Store last 1000 errors
        
        # State variables
        self.pose = Pose()
        self.prev_linear_error = 0.0
        self.prev_angular_error = 0.0
        self.prev_time = self.get_clock().now()
        
        # Create control loop timer
        self.timer = self.create_timer(0.1, self.control_loop)
        
        self.get_logger().info('Lawnmower controller started')
        self.get_logger().info(f'Following waypoints: {self.waypoints}')

    def generate_waypoints(self):
        waypoints = []
        # Start higher up in the window (around y=8) and work down to y=3
        y = 8.0  # Start higher in the window
        
        while y >= 3.0:  # End higher than before to use middle space
            # Add points for current line
            if len(waypoints) % 2 == 0:
                waypoints.append((2.0, y))  # Left to right, but not too close to edge
                waypoints.append((9.0, y))  # Not too close to right edge
            else:
                waypoints.append((9.0, y))  # Right to left
                waypoints.append((2.0, y))
            
            y -= self.spacing  # Move down instead of up
        
        return waypoints

    def calculate_cross_track_error(self):
        if self.current_waypoint < 1:
            return 0.0
            
        # Get current line segment endpoints
        start = self.waypoints[self.current_waypoint - 1]
        end = self.waypoints[self.current_waypoint]
        
        # Calculate cross track error (distance from point to line segment)
        x1, y1 = start
        x2, y2 = end
        x0, y0 = self.pose.x, self.pose.y
        
        # Vector from start to end
        dx = x2 - x1
        dy = y2 - y1
        
        # Length of line segment squared
        d2 = dx*dx + dy*dy
        
        if d2 == 0:  # If points are the same
            return math.sqrt((x0 - x1)**2 + (y0 - y1)**2)
            
        # Calculate projection point parameter
        t = max(0, min(1, ((x0 - x1)*dx + (y0 - y1)*dy) / d2))
        
        # Calculate projection point
        proj_x = x1 + t*dx
        proj_y = y1 + t*dy
        
        # Calculate distance to projection point (cross-track error)
        error = math.sqrt((x0 - proj_x)**2 + (y0 - proj_y)**2)
        
        # Store error and calculate statistics
        self.cross_track_errors.append(error)
        current_avg = sum(self.cross_track_errors) / len(self.cross_track_errors)
        current_max = max(self.cross_track_errors)
        current_min = min(self.cross_track_errors)
        
        # Log statistics every update
        self.get_logger().info(
            f'Cross-track error - Current: {error:.3f}, '
            f'Avg: {current_avg:.3f}, '
            f'Min: {current_min:.3f}, '
            f'Max: {current_max:.3f}, '
            f'Segment: ({x1:.1f},{y1:.1f})->({x2:.1f},{y2:.1f})'
        )
        
        return error

    def pose_callback(self, msg):
        self.pose = msg

    def get_distance(self, x1, y1, x2, y2):
        return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

    def get_angle(self, x1, y1, x2, y2):
        return math.atan2(y2 - y1, x2 - x1)

    def control_loop(self):
        if self.current_waypoint >= len(self.waypoints):
            # Pattern complete
            self.get_logger().info('Lawnmower pattern complete')
            if self.cross_track_errors:
                final_avg_error = sum(self.cross_track_errors) / len(self.cross_track_errors)
                self.get_logger().info(f'Final average cross-track error: {final_avg_error:.3f}')
            self.timer.cancel()
            return

        # Calculate cross-track error
        cross_track_error = self.calculate_cross_track_error()

        target_x, target_y = self.waypoints[self.current_waypoint]
        current_time = self.get_clock().now()
        dt = (current_time - self.prev_time).nanoseconds / 1e9  # Convert to seconds

        # Calculate errors
        distance = self.get_distance(self.pose.x, self.pose.y, target_x, target_y)
        target_angle = self.get_angle(self.pose.x, self.pose.y, target_x, target_y)
        angular_error = target_angle - self.pose.theta

        # Normalize angular error to [-pi, pi]
        while angular_error > math.pi:
            angular_error -= 2 * math.pi
        while angular_error < -math.pi:
            angular_error += 2 * math.pi

        # Calculate error derivatives
        linear_error_derivative = (distance - self.prev_linear_error) / dt
        angular_error_derivative = (angular_error - self.prev_angular_error) / dt

        # PD control
        linear_velocity = self.Kp_linear * distance + self.Kd_linear * linear_error_derivative
        angular_velocity = self.Kp_angular * angular_error + self.Kd_angular * angular_error_derivative

        # Create and publish velocity command
        vel_msg = Twist()
        vel_msg.linear.x = min(linear_velocity, 2.0)  # Limit maximum speed
        vel_msg.angular.z = angular_velocity
        self.velocity_publisher.publish(vel_msg)

        # Update previous errors and time
        self.prev_linear_error = distance
        self.prev_angular_error = angular_error
        self.prev_time = current_time

        # Check if we've reached the current waypoint
        if distance < 0.1:  # Within 0.1 units of target
            self.current_waypoint += 1
            self.get_logger().info(f'Reached waypoint {self.current_waypoint}')


def main(args=None):
    rclpy.init(args=args)
    controller = LawnmowerController()
    
    try:
        rclpy.spin(controller)
    except KeyboardInterrupt:
        pass
    finally:
        controller.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
