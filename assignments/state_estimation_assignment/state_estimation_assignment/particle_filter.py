#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, TwistStamped
from nav_msgs.msg import Odometry
from visualization_msgs.msg import MarkerArray, Marker
import numpy as np

class ParticleFilterNode(Node):
    def __init__(self):
        super().__init__('particle_filter')
        
        # Publishers
        self.estimated_state_pub = self.create_publisher(
            Odometry, 'estimated_state', 10)
        self.particle_pub = self.create_publisher(
            MarkerArray, 'particles', 10)
        
        # Subscribers
        self.gps_sub = self.create_subscription(
            PoseStamped, 'gps/pose', self.gps_callback, 10)
        self.imu_sub = self.create_subscription(
            TwistStamped, 'imu/velocity', self.imu_callback, 10)
        
        # Parameters
        self.declare_parameter('num_particles', 100)
        self.num_particles = self.get_parameter('num_particles').value
        
        # Initialize particles [x, y, vx, vy] and weights
        self.particles = np.zeros((self.num_particles, 4))
        self.weights = np.ones(self.num_particles) / self.num_particles
        
        # System parameters
        self.dt = 0.1  # Time step
        
        # TODO: Students should tune these parameters
        self.motion_noise = np.array([0.1, 0.1, 0.05, 0.05])  # Motion model noise
        self.gps_noise = 0.5  # GPS measurement noise
        self.imu_noise = 0.1  # IMU measurement noise
        
    def predict(self):
        """TODO: Students should implement the prediction step
        
        This should:
        1. Propagate each particle through the motion model
        2. Add random noise to represent uncertainty in motion
        """
        # Example motion model (students should modify this)
        # for i in range(self.num_particles):
        #     # Update position based on velocity
        #     self.particles[i, 0] += self.particles[i, 2] * self.dt
        #     self.particles[i, 1] += self.particles[i, 3] * self.dt
        #     
        #     # Add noise
        #     self.particles[i] += np.random.normal(0, self.motion_noise)
        pass
    
    def update_gps(self, measurement):
        """TODO: Students should implement the GPS measurement update
        
        This should:
        1. Update particle weights based on GPS measurement likelihood
        2. Normalize weights
        3. Compute effective sample size and resample if needed
        """
        # Example weight update (students should modify this)
        # for i in range(self.num_particles):
        #     # Compute likelihood of measurement given particle state
        #     error = measurement - self.particles[i, :2]
        #     self.weights[i] *= np.exp(-np.sum(error**2) / (2 * self.gps_noise**2))
        #
        # Normalize weights
        # self.weights /= np.sum(self.weights)
        pass
    
    def update_imu(self, measurement):
        """TODO: Students should implement the IMU measurement update
        
        Similar to GPS update but using velocity measurements
        """
        pass
    
    def resample(self):
        """TODO: Students should implement resampling
        
        This should:
        1. Compute effective sample size
        2. If ESS < threshold, resample particles based on weights
        3. Reset weights to uniform
        """
        # Example resampling (students should modify this)
        # eff_sample_size = 1.0 / np.sum(self.weights**2)
        # if eff_sample_size < self.num_particles / 2:
        #     # Resample using numpy's choice
        #     indices = np.random.choice(
        #         self.num_particles,
        #         size=self.num_particles,
        #         p=self.weights
        #     )
        #     self.particles = self.particles[indices]
        #     self.weights = np.ones(self.num_particles) / self.num_particles
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
        self.resample()
        
        # Publish current estimate and particles
        self.publish_estimate(msg.header.stamp)
        self.publish_particles(msg.header.stamp)
    
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
        self.resample()
        
        # Publish current estimate and particles
        self.publish_estimate(msg.header.stamp)
        self.publish_particles(msg.header.stamp)
    
    def get_estimated_state(self):
        """Compute estimated state as weighted average of particles"""
        return np.average(self.particles, weights=self.weights, axis=0)
    
    def publish_estimate(self, stamp):
        """Publish the current state estimate"""
        state = self.get_estimated_state()
        
        msg = Odometry()
        msg.header.stamp = stamp
        msg.header.frame_id = 'map'
        msg.child_frame_id = 'base_link'
        
        # Fill position
        msg.pose.pose.position.x = state[0]
        msg.pose.pose.position.y = state[1]
        msg.pose.pose.position.z = 0.0
        
        # Fill velocity
        msg.twist.twist.linear.x = state[2]
        msg.twist.twist.linear.y = state[3]
        msg.twist.twist.linear.z = 0.0
        
        self.estimated_state_pub.publish(msg)
    
    def publish_particles(self, stamp):
        """Publish particle visualization markers"""
        marker_array = MarkerArray()
        
        for i in range(self.num_particles):
            marker = Marker()
            marker.header.frame_id = 'map'
            marker.header.stamp = stamp
            marker.ns = 'particles'
            marker.id = i
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD
            
            # Position
            marker.pose.position.x = self.particles[i, 0]
            marker.pose.position.y = self.particles[i, 1]
            marker.pose.position.z = 0.0
            
            # Scale (size based on weight)
            scale = 0.1 * (self.weights[i] * self.num_particles)
            marker.scale.x = scale
            marker.scale.y = scale
            marker.scale.z = scale
            
            # Color (blue with alpha based on weight)
            marker.color.r = 0.0
            marker.color.g = 0.0
            marker.color.b = 1.0
            marker.color.a = min(1.0, self.weights[i] * self.num_particles)
            
            marker_array.markers.append(marker)
        
        self.particle_pub.publish(marker_array)

def main(args=None):
    rclpy.init(args=args)
    node = ParticleFilterNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main() 