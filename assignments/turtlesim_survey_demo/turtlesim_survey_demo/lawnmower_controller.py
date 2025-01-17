import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import numpy as np
import math


class LawnmowerController(Node):
    def __init__(self):
        super().__init__('lawnmower_controller')
        
        # Create publisher and subscriber
        self.velocity_publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.pose_subscriber = self.create_subscription(Pose, '/turtle1/pose', self.pose_callback, 10)
        
        # Controller parameters
        self.Kp_linear = 1.0  # Proportional gain for linear velocity
        self.Kd_linear = 0.5  # Derivative gain for linear velocity
        self.Kp_angular = 3.0  # Proportional gain for angular velocity
        self.Kd_angular = 0.5  # Derivative gain for angular velocity
        
        # Lawnmower pattern parameters
        self.width = 5.0  # Width of the pattern
        self.spacing = 1.0  # Spacing between lines
        self.current_line = 0
        self.waypoints = self.generate_waypoints()
        self.current_waypoint = 0
        
        # State variables
        self.pose = Pose()
        self.prev_linear_error = 0.0
        self.prev_angular_error = 0.0
        self.prev_time = self.get_clock().now()
        
        # Create control loop timer
        self.timer = self.create_timer(0.1, self.control_loop)
        
        self.get_logger().info('Lawnmower controller started')

    def generate_waypoints(self):
        waypoints = []
        y = 1.0  # Start at y = 1.0
        
        while y <= 10.0:  # Stay within turtlesim bounds
            # Add points for current line
            if len(waypoints) % 2 == 0:
                waypoints.append((1.0, y))  # Left to right
                waypoints.append((10.0, y))
            else:
                waypoints.append((10.0, y))  # Right to left
                waypoints.append((1.0, y))
            
            y += self.spacing
        
        return waypoints

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
            self.timer.cancel()
            return

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
