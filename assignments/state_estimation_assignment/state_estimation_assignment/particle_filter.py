#!/usr/bin/env python3

import numpy as np
from geometry_msgs.msg import PoseWithCovarianceStamped
from sensor_msgs.msg import Imu
from visualization_msgs.msg import MarkerArray, Marker
import rclpy
from rclpy.node import Node

class ParticleFilter(Node):
    def __init__(self):
        super().__init__('particle_filter_node')
        
        # Filter parameters
        self.num_particles = 100
        self.resample_threshold = self.num_particles / 2
        
        # Initialize particles [x, y, theta, weight]
        self.particles = np.zeros((self.num_particles, 4))
        self.particles[:,3] = 1.0 / self.num_particles  # Initialize weights
        
        # Noise parameters
        self.motion_noise = np.diag([0.1, 0.1, 0.1])
        self.gps_noise = np.diag([0.5, 0.5])
        self.imu_noise = 0.1
        
        # Publishers and subscribers
        self.state_pub = self.create_publisher(
            PoseWithCovarianceStamped, 
            'estimated_state', 
            10
        )
        
        self.particle_pub = self.create_publisher(
            MarkerArray,
            'particles',
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
        TODO: Implement particle prediction
        Each particle: [x, y, theta, weight]
        
        1. Apply motion model to each particle
        2. Add noise to prediction
        """
        # Your code here
        pass

    def update(self, gps_measurement, imu_measurement):
        """
        TODO: Implement measurement update and weight calculation
        
        1. Update particle weights based on measurements
        2. Normalize weights
        3. Calculate effective sample size
        4. Trigger resampling if needed
        """
        # Your code here
        pass

    def resample(self):
        """
        TODO: Implement systematic resampling
        
        1. Create cumulative sum of weights
        2. Generate systematic sampling points
        3. Create new particle set
        4. Reset weights
        """
        # Your code here
        pass

    def get_effective_sample_size(self):
        """Calculate the effective sample size based on weights"""
        return 1.0 / np.sum(np.square(self.particles[:,3]))

    def estimate_state(self):
        """Compute weighted mean of particle states"""
        mean_state = np.average(self.particles[:,:3], weights=self.particles[:,3], axis=0)
        return mean_state

    def publish_particles(self):
        """Publish particle visualization markers"""
        marker_array = MarkerArray()
        
        for i, particle in enumerate(self.particles):
            marker = Marker()
            marker.header.frame_id = "map"
            marker.header.stamp = self.get_clock().now().to_msg()
            marker.id = i
            marker.type = Marker.ARROW
            marker.action = Marker.ADD
            marker.pose.position.x = particle[0]
            marker.pose.position.y = particle[1]
            
            # Convert theta to quaternion
            theta = particle[2]
            marker.pose.orientation.w = np.cos(theta/2)
            marker.pose.orientation.z = np.sin(theta/2)
            
            # Size and color based on weight
            marker.scale.x = 0.3
            marker.scale.y = 0.05
            marker.scale.z = 0.05
            
            marker.color.a = 0.5
            marker.color.r = particle[3] * self.num_particles
            marker.color.g = 0.2
            marker.color.b = 0.2
            
            marker_array.markers.append(marker)
        
        self.particle_pub.publish(marker_array)

    def publish_state(self):
        """Publish the estimated state"""
        state = self.estimate_state()
        
        msg = PoseWithCovarianceStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "map"
        
        msg.pose.pose.position.x = state[0]
        msg.pose.pose.position.y = state[1]
        
        # Convert theta to quaternion
        theta = state[2]
        msg.pose.pose.orientation.w = np.cos(theta/2)
        msg.pose.pose.orientation.z = np.sin(theta/2)
        
        self.state_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = ParticleFilter()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 