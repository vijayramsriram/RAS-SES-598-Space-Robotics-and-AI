#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, TwistStamped
from nav_msgs.msg import Odometry
import numpy as np

class KalmanFilterNode(Node):
    def __init__(self):
        super().__init__('kalman_filter')
        
        # Publishers
        self.estimated_state_pub = self.create_publisher(
            Odometry, 'estimated_state', 10)
        
        # Subscribers
        self.gps_sub = self.create_subscription(
            PoseStamped, 'gps/pose', self.gps_callback, 10)
        self.imu_sub = self.create_subscription(
            TwistStamped, 'imu/velocity', self.imu_callback, 10)
        
        # Initialize state [x, y, vx, vy]
        self.state = np.zeros(4)
        self.covariance = np.eye(4) * 100  # High initial uncertainty
        
        # System matrices
        self.dt = 0.1  # Time step
        
        # TODO: Students should complete these matrices
        # State transition matrix F
        self.F = np.array([
            [1, 0, self.dt, 0],      # x = x + vx*dt
            [0, 1, 0, self.dt],      # y = y + vy*dt
            [0, 0, 1, 0],            # vx = vx
            [0, 0, 0, 1]             # vy = vy
        ])
        
        # Process noise covariance Q
        # TODO: Students should tune this
        self.Q = np.eye(4) * 0.1
        
        # Measurement matrix H for GPS (position only)
        self.H_gps = np.array([
            [1, 0, 0, 0],
            [0, 1, 0, 0]
        ])
        
        # Measurement matrix H for IMU (velocity only)
        self.H_imu = np.array([
            [0, 0, 1, 0],
            [0, 0, 0, 1]
        ])
        
        # Measurement noise covariance R
        # TODO: Students should tune these
        self.R_gps = np.eye(2) * 0.5
        self.R_imu = np.eye(2) * 0.1
        
    def predict(self):
        """TODO: Students should implement the prediction step"""
        # State prediction
        # self.state = ?
        
        # Covariance prediction
        # self.covariance = ?
        pass
    
    def update_gps(self, measurement):
        """TODO: Students should implement the GPS update step"""
        # Innovation
        # y = measurement - self.H_gps @ self.state
        
        # Innovation covariance
        # S = self.H_gps @ self.covariance @ self.H_gps.T + self.R_gps
        
        # Kalman gain
        # K = ?
        
        # State update
        # self.state = ?
        
        # Covariance update
        # self.covariance = ?
        pass
    
    def update_imu(self, measurement):
        """TODO: Students should implement the IMU update step"""
        # Similar to GPS update but with IMU matrices
        pass
    
    def gps_callback(self, msg):
        """Handle incoming GPS messages"""
        # Extract measurement
        measurement = np.array([
            msg.pose.position.x,
            msg.pose.position.y
        ])
        
        # Perform prediction and update
        self.predict()
        self.update_gps(measurement)
        
        # Publish current estimate
        self.publish_estimate(msg.header.stamp)
    
    def imu_callback(self, msg):
        """Handle incoming IMU messages"""
        # Extract measurement
        measurement = np.array([
            msg.twist.linear.x,
            msg.twist.linear.y
        ])
        
        # Perform prediction and update
        self.predict()
        self.update_imu(measurement)
        
        # Publish current estimate
        self.publish_estimate(msg.header.stamp)
    
    def publish_estimate(self, stamp):
        """Publish the current state estimate"""
        msg = Odometry()
        msg.header.stamp = stamp
        msg.header.frame_id = 'map'
        msg.child_frame_id = 'base_link'
        
        # Fill position
        msg.pose.pose.position.x = self.state[0]
        msg.pose.pose.position.y = self.state[1]
        msg.pose.pose.position.z = 0.0
        
        # Fill velocity
        msg.twist.twist.linear.x = self.state[2]
        msg.twist.twist.linear.y = self.state[3]
        msg.twist.twist.linear.z = 0.0
        
        # Fill covariance (only diagonal elements)
        msg.pose.covariance[0] = self.covariance[0,0]
        msg.pose.covariance[7] = self.covariance[1,1]
        msg.twist.covariance[0] = self.covariance[2,2]
        msg.twist.covariance[7] = self.covariance[3,3]
        
        self.estimated_state_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = KalmanFilterNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main() 