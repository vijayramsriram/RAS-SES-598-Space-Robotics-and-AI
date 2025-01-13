from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='state_estimation_assignment',
            executable='sensor_simulator',
            name='sensor_simulator',
            output='screen'
        ),
        Node(
            package='state_estimation_assignment',
            executable='kalman_filter',
            name='kalman_filter',
            output='screen'
        ),
        Node(
            package='state_estimation_assignment',
            executable='particle_filter',
            name='particle_filter',
            output='screen'
        )
    ]) 