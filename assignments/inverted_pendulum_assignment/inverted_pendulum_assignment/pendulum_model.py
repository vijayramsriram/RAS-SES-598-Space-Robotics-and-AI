#!/usr/bin/env python3

import numpy as np
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray

class PendulumModel(Node):
    def __init__(self):
        super().__init__('pendulum_model')
        
        # System parameters
        self.M = 1.0  # Cart mass (kg)
        self.m = 0.1  # Pendulum mass (kg)
        self.l = 0.5  # Pendulum length (m)
        self.g = 9.81 # Gravity (m/s^2)
        
        # State: [x, x_dot, theta, theta_dot]
        self.state = np.zeros(4)
        
        # Publishers and subscribers
        self.state_pub = self.create_publisher(
            Float64MultiArray, 
            'pendulum/state', 
            10
        )
        
        self.control_sub = self.create_subscription(
            Float64MultiArray,
            'pendulum/control',
            self.control_callback,
            10
        )
        
        # Simulation timer
        self.dt = 0.01  # 100Hz
        self.create_timer(self.dt, self.timer_callback)
    
    def update_state(self, state, control_input, dt):
        """
        TODO: Implement pendulum dynamics
        State: [x, x_dot, theta, theta_dot]
        Input: [force]
        
        Dynamic model:
        x_ddot = (force - m*l*theta_ddot*cos(theta) + m*l*theta_dot^2*sin(theta)) / (M + m)
        theta_ddot = (g*sin(theta) - x_ddot*cos(theta)) / l
        """
        # Your code here
        pass
    
    def control_callback(self, msg):
        """Handle incoming control inputs"""
        self.last_control = msg.data[0]
    
    def timer_callback(self):
        """Update and publish system state"""
        # Update state
        self.state = self.update_state(self.state, self.last_control, self.dt)
        
        # Publish state
        msg = Float64MultiArray()
        msg.data = self.state.tolist()
        self.state_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = PendulumModel()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 