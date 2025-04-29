#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist
from px4_msgs.msg import VehicleCommand

class ArucoLandingController(Node):
    def __init__(self):
        super().__init__('aruco_landing_controller')

        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.vehicle_command_pub = self.create_publisher(VehicleCommand, '/fmu/in/vehicle_command', 10)

        self.subscription = self.create_subscription(
            String,
            '/aruco/marker_pose',
            self.marker_pose_callback,
            10
        )

        self.takeoff_altitude = 2.0  # meters
        self.landing_started = False
        self.arm_and_takeoff_sent = False

        self.timer = self.create_timer(1.0, self.takeoff)

        self.get_logger().info('Aruco Landing Controller Node Started')

    def takeoff(self):
        if not self.arm_and_takeoff_sent:
            self.publish_vehicle_command(400, 1)  # ARM
            self.publish_vehicle_command(22, self.takeoff_altitude)  # TAKEOFF
            self.arm_and_takeoff_sent = True
            self.get_logger().info('Sent Arm and Takeoff commands')

    def marker_pose_callback(self, msg):
        try:
            data = msg.data
            # Example: "Marker 0 detected at x:1.25m, y:0.45m, z:2.34m"
            parts = data.split(' ')
            x = float(parts[5][2:-1])
            y = float(parts[6][2:-1])
            z = float(parts[7][2:-1])

            self.get_logger().info(f"Tracking Marker: x={x:.2f}, y={y:.2f}, z={z:.2f}")

            cmd = Twist()
            kp = 0.5

            cmd.linear.x = -kp * y  # Swap axes depending on your setup
            cmd.linear.y = -kp * x

            self.cmd_vel_pub.publish(cmd)

            # If drone is very close to center, start landing
            if abs(x) < 0.1 and abs(y) < 0.1:
                if not self.landing_started:
                    self.get_logger().info("Centered above marker. Sending LAND command...")
                    self.publish_vehicle_command(21)  # LAND
                    self.landing_started = True

        except Exception as e:
            self.get_logger().error(f"Error parsing marker pose: {str(e)}")

    def publish_vehicle_command(self, command, param7=0.0):
        msg = VehicleCommand()
        msg.param7 = float(param7)
        msg.command = command
        msg.target_system = 1
        msg.target_component = 1
        msg.source_system = 1
        msg.source_component = 1
        msg.from_external = True
        msg.timestamp = int(self.get_clock().now().nanoseconds / 1000)
        self.vehicle_command_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = ArucoLandingController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

