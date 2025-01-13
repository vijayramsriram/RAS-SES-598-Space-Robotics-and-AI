#!/usr/bin/env python3

import numpy as np
from geometry_msgs.msg import PoseWithCovarianceStamped
from sensor_msgs.msg import Imu
import rclpy
from rclpy.node import Node

class SensorSimulator(Node):
    def __init__(self):
        super().__init__('sensor_simulator')
        
        # True robot state [x, y, theta]
        self.true_state = np.zeros(3)
        
        # Motion parameters
        self.velocity = 0.5  # m/s
        self.angular_velocity = 0.2  # rad/s
        
        # Noise parameters
        self.gps_noise_std = np.array([0.5, 0.5])
        self.imu_noise_std = 0.1
        
        # Publishers
        self.true_state_pub = self.create_publisher(
            PoseWithCovarianceStamped,
            'ground_truth',
            10
        )
        
        self.gps_pub = self.create_publisher(
            PoseWithCovarianceStamped,
            'gps',
            10
        )
        
        self.imu_pub = self.create_publisher(
            Imu,
            'imu',
            10
        )
        
        # Timer for simulation updates
        self.create_timer(0.1, self.timer_callback)
        self.last_time = self.get_clock().now()

    def update_true_state(self, dt):
        """Update the true robot state using motion model"""
        self.true_state[0] += self.velocity * np.cos(self.true_state[2]) * dt
        self.true_state[1] += self.velocity * np.sin(self.true_state[2]) * dt
        self.true_state[2] += self.angular_velocity * dt

    def generate_gps_measurement(self):
        """Generate noisy GPS measurement"""
        noise = np.random.normal(0, self.gps_noise_std)
        measurement = self.true_state[:2] + noise
        return measurement

    def generate_imu_measurement(self):
        """Generate noisy IMU measurement"""
        noise = np.random.normal(0, self.imu_noise_std)
        measurement = self.true_state[2] + noise
        return measurement

    def timer_callback(self):
        """Periodic update and publish measurements"""
        current_time = self.get_clock().now()
        dt = (current_time - self.last_time).nanoseconds / 1e9
        self.last_time = current_time
        
        # Update true state
        self.update_true_state(dt)
        
        # Publish true state
        true_msg = PoseWithCovarianceStamped()
        true_msg.header.stamp = current_time.to_msg()
        true_msg.header.frame_id = "map"
        true_msg.pose.pose.position.x = self.true_state[0]
        true_msg.pose.pose.position.y = self.true_state[1]
        theta = self.true_state[2]
        true_msg.pose.pose.orientation.w = np.cos(theta/2)
        true_msg.pose.pose.orientation.z = np.sin(theta/2)
        self.true_state_pub.publish(true_msg)
        
        # Publish GPS measurement
        gps_measurement = self.generate_gps_measurement()
        gps_msg = PoseWithCovarianceStamped()
        gps_msg.header.stamp = current_time.to_msg()
        gps_msg.header.frame_id = "map"
        gps_msg.pose.pose.position.x = gps_measurement[0]
        gps_msg.pose.pose.position.y = gps_measurement[1]
        self.gps_pub.publish(gps_msg)
        
        # Publish IMU measurement
        imu_measurement = self.generate_imu_measurement()
        imu_msg = Imu()
        imu_msg.header.stamp = current_time.to_msg()
        imu_msg.header.frame_id = "map"
        imu_msg.orientation.w = np.cos(imu_measurement/2)
        imu_msg.orientation.z = np.sin(imu_measurement/2)
        self.imu_pub.publish(imu_msg)

def main(args=None):
    rclpy.init(args=args)
    node = SensorSimulator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 