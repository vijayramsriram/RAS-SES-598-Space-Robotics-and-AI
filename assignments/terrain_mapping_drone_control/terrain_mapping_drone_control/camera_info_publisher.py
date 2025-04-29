#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CameraInfo
from builtin_interfaces.msg import Time

class CameraInfoPublisher(Node):
    def __init__(self):
        super().__init__('camera_info_publisher')
        self.publisher = self.create_publisher(CameraInfo, '/rgb_camera/camera_info', 10)
        timer_period = 0.1  # Publish at 10 Hz
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = CameraInfo()
        now = self.get_clock().now().to_msg()
        msg.header.stamp = now
        msg.header.frame_id = "camera_link"
        msg.height = 1080
        msg.width = 1920
        msg.k = [525.0, 0.0, 960.0,
                 0.0, 525.0, 540.0,
                 0.0, 0.0, 1.0]
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = CameraInfoPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

