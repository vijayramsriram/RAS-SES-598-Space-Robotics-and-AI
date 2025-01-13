#!/usr/bin/env python3

import numpy as np
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray

class PendulumController(Node):
    def __init__(self):
        super().__init__('pendulum_controller')
        
        # Controller parameters
        self.K = np.zeros((1, 4))  # LQR gain matrix
        
        # State estimate
        self.state_estimate = np.zeros(4)
        
        # Publishers and subscribers
        self.control_pub = self.create_publisher(
            Float64MultiArray, 
            'pendulum/control', 
            10
        )
        
        self.state_sub = self.create_subscription(
            Float64MultiArray,
            'pendulum/state',
            self.state_callback,
            10
        )
        
        # Control timer
        self.create_timer(0.01, self.control_timer_callback)
    
    def compute_control(self, state):
        """
        TODO: Implement LQR controller
        Compute control input u = -K*x
        """
        # Your code here
        pass
    
    def estimate_state(self, measurements):
        """
        TODO: Implement state observer
        Update state estimate using sensor measurements
        """
        # Your code here
        pass
    
    def state_callback(self, msg):
        """Handle incoming state measurements"""
        measurements = np.array(msg.data)
        self.state_estimate = self.estimate_state(measurements)
    
    def control_timer_callback(self):
        """Compute and publish control input"""
        control = self.compute_control(self.state_estimate)
        
        msg = Float64MultiArray()
        msg.data = [control]
        self.control_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = PendulumController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 