from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='inverted_pendulum_assignment',
            executable='pendulum_model',
            name='pendulum_model',
            output='screen'
        ),
        Node(
            package='inverted_pendulum_assignment',
            executable='pendulum_controller',
            name='pendulum_controller',
            output='screen'
        ),
        Node(
            package='inverted_pendulum_assignment',
            executable='safety_monitor',
            name='safety_monitor',
            output='screen'
        )
    ]) 