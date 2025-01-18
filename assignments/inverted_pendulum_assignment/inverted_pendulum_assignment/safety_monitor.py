#!/usr/bin/env python3

import numpy as np
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray, Bool

class SafetyMonitor(Node):
    def __init__(self):
        super().__init__('safety_monitor')
        
        # Safety parameters
        self.max_position = 1.0  # meters
        self.max_velocity = 0.1  # m/s
        self.max_angle = np.pi/4  # radians
        self.max_angular_velocity = np.pi/4.0  # rad/s
        self.max_force = 20.0  # N
        
        # Publishers and subscribers
        self.safety_pub = self.create_publisher(
            Bool, 
            'pendulum/safety_status', 
            10
        )
        
        self.state_sub = self.create_subscription(
            Float64MultiArray,
            'pendulum/state',
            self.state_callback,
            10
        )
        
        self.control_sub = self.create_subscription(
            Float64MultiArray,
            'pendulum/control',
            self.control_callback,
            10
        )
    
    def check_safety_constraints(self, state, control):
        """
        TODO: Implement safety checks
        - Position limits
        - Velocity limits
        - Control input saturation
        - Emergency stop conditions
        """
        # Your code here
        pass
    
    def state_callback(self, msg):
        """Handle incoming state measurements"""
        state = np.array(msg.data)
        self.last_state = state
        self.check_safety()
    
    def control_callback(self, msg):
        """Handle incoming control inputs"""
        self.last_control = msg.data[0]
        self.check_safety()
    
    def check_safety(self):
        """Check safety constraints and publish status"""
        if hasattr(self, 'last_state') and hasattr(self, 'last_control'):
            is_safe = self.check_safety_constraints(self.last_state, self.last_control)
            
            msg = Bool()
            msg.data = is_safe
            self.safety_pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = SafetyMonitor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 