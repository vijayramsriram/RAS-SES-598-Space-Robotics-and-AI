#!/usr/bin/env python3

import numpy as np
from geometry_msgs.msg import PoseWithCovarianceStamped
from sensor_msgs.msg import Imu
import rclpy
from rclpy.node import Node

class KalmanFilter(Node):
    def __init__(self):
        super().__init__('kalman_filter_node')
        
        # Initialize state [x, y, theta]
        self.state = np.zeros(3)
        self.covariance = np.eye(3)
        
        # Initialize noise parameters
        self.Q = np.diag([0.1, 0.1, 0.1])  # Process noise
        self.R_gps = np.diag([0.5, 0.5])    # GPS measurement noise
        self.R_imu = np.array([[0.1]])       # IMU measurement noise
        
        # ROS publishers and subscribers
        self.state_pub = self.create_publisher(
            PoseWithCovarianceStamped, 
            'estimated_state', 
            10
        )
        
        self.gps_sub = self.create_subscription(
            PoseWithCovarianceStamped,
            'gps',
            self.gps_callback,
            10
        )
        
        self.imu_sub = self.create_subscription(
            Imu,
            'imu',
            self.imu_callback,
            10
        )
        
        self.last_time = self.get_clock().now()
        
    def predict(self, dt, velocity, angular_velocity):
        """
        TODO: Implement the prediction step
        State: [x, y, theta]
        Input: [v, w]
        
        Motion model:
        x' = x + v*cos(theta)*dt
        y' = y + v*sin(theta)*dt
        theta' = theta + w*dt
        """
        # Your code here
        pass

    def update_gps(self, gps_measurement):
        """
        TODO: Implement GPS measurement update
        Measurement: [x, y]
        
        1. Calculate Kalman gain
        2. Update state
        3. Update covariance
        """
        # Your code here
        pass

    def update_imu(self, imu_measurement):
        """
        TODO: Implement IMU measurement update
        Measurement: [theta]
        
        1. Calculate Kalman gain
        2. Update state
        3. Update covariance
        """
        # Your code here
        pass

    def gps_callback(self, msg):
        """Handle incoming GPS measurements"""
        gps_measurement = np.array([
            msg.pose.pose.position.x,
            msg.pose.pose.position.y
        ])
        self.update_gps(gps_measurement)
        self.publish_state()

    def imu_callback(self, msg):
        """Handle incoming IMU measurements"""
        # Extract orientation (assuming 2D, using yaw only)
        # In practice, you would use tf transformations
        orientation = msg.orientation
        # Convert quaternion to yaw
        imu_measurement = np.array([np.arctan2(2.0 * (orientation.w * orientation.z + 
                                                     orientation.x * orientation.y),
                                             1.0 - 2.0 * (orientation.y * orientation.y + 
                                                         orientation.z * orientation.z))])
        self.update_imu(imu_measurement)
        self.publish_state()

    def publish_state(self):
        """Publish the current state estimate"""
        msg = PoseWithCovarianceStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "map"
        
        msg.pose.pose.position.x = self.state[0]
        msg.pose.pose.position.y = self.state[1]
        
        # Convert theta to quaternion
        theta = self.state[2]
        msg.pose.pose.orientation.w = np.cos(theta/2)
        msg.pose.pose.orientation.z = np.sin(theta/2)
        
        # Fill covariance (6x6 matrix in ROS message)
        ros_covariance = np.zeros((6,6))
        ros_covariance[0:2, 0:2] = self.covariance[0:2, 0:2]
        ros_covariance[5,5] = self.covariance[2,2]
        msg.pose.covariance = ros_covariance.flatten().tolist()
        
        self.state_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = KalmanFilter()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 