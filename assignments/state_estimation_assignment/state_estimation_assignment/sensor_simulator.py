#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, TwistStamped
from nav_msgs.msg import Odometry
import numpy as np
from math import sin, cos

class SensorSimulator(Node):
    def __init__(self):
        super().__init__('sensor_simulator')
        
        # Publishers
        self.gps_pub = self.create_publisher(PoseStamped, 'gps/pose', 10)
        self.imu_pub = self.create_publisher(TwistStamped, 'imu/velocity', 10)
        self.true_pose_pub = self.create_publisher(Odometry, 'ground_truth', 10)
        
        # Parameters
        self.declare_parameter('gps_noise_std', 0.5)  # meters
        self.declare_parameter('imu_noise_std', 0.1)  # m/s
        self.declare_parameter('update_rate', 10.0)  # Hz
        
        # Timer
        self.timer = self.create_timer(1.0/self.get_parameter('update_rate').value, self.timer_callback)
        
        # Initialize true state
        self.t = 0.0
        self.true_x = 0.0
        self.true_y = 0.0
        self.true_vx = 0.0
        self.true_vy = 0.0
        
    def timer_callback(self):
        # Update true state (circular motion with varying radius)
        dt = 1.0/self.get_parameter('update_rate').value
        self.t += dt
        
        # True trajectory: figure-8 pattern
        r = 5.0  # base radius
        omega = 0.2  # angular velocity
        
        # Update true position and velocity
        self.true_x = r * sin(omega * self.t)
        self.true_y = r * sin(omega * self.t) * cos(omega * self.t)
        self.true_vx = r * omega * cos(omega * self.t)
        self.true_vy = r * omega * (cos(omega * self.t)**2 - sin(omega * self.t)**2)
        
        # Get noise parameters
        gps_std = self.get_parameter('gps_noise_std').value
        imu_std = self.get_parameter('imu_noise_std').value
        
        # Create messages
        now = self.get_clock().now().to_msg()
        
        # GPS measurement (noisy position)
        gps_msg = PoseStamped()
        gps_msg.header.stamp = now
        gps_msg.header.frame_id = 'map'
        gps_msg.pose.position.x = self.true_x + np.random.normal(0, gps_std)
        gps_msg.pose.position.y = self.true_y + np.random.normal(0, gps_std)
        gps_msg.pose.position.z = 0.0
        
        # IMU measurement (noisy velocity)
        imu_msg = TwistStamped()
        imu_msg.header.stamp = now
        imu_msg.header.frame_id = 'base_link'
        imu_msg.twist.linear.x = self.true_vx + np.random.normal(0, imu_std)
        imu_msg.twist.linear.y = self.true_vy + np.random.normal(0, imu_std)
        imu_msg.twist.linear.z = 0.0
        
        # Ground truth
        true_msg = Odometry()
        true_msg.header.stamp = now
        true_msg.header.frame_id = 'map'
        true_msg.child_frame_id = 'base_link'
        true_msg.pose.pose = gps_msg.pose
        true_msg.pose.pose.position.x = self.true_x
        true_msg.pose.pose.position.y = self.true_y
        true_msg.twist.twist = imu_msg.twist
        
        # Publish messages
        self.gps_pub.publish(gps_msg)
        self.imu_pub.publish(imu_msg)
        self.true_pose_pub.publish(true_msg)

def main(args=None):
    rclpy.init(args=args)
    node = SensorSimulator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main() 