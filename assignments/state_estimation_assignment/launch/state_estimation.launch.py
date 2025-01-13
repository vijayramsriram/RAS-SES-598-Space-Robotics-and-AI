from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Start sensor simulator
        Node(
            package='state_estimation_assignment',
            executable='sensor_simulator',
            name='sensor_simulator',
            parameters=[{
                'gps_noise_std': 0.5,
                'imu_noise_std': 0.1,
                'update_rate': 10.0
            }]
        ),
        
        # Start Kalman filter node
        Node(
            package='state_estimation_assignment',
            executable='kalman_filter',
            name='kalman_filter'
        ),
        
        # Start particle filter node
        Node(
            package='state_estimation_assignment',
            executable='particle_filter',
            name='particle_filter',
            parameters=[{
                'num_particles': 100
            }]
        )
    ]) 