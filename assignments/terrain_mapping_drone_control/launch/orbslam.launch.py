#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    """Generate launch description for camera transforms and visualization."""
    
    # Get the package share directory
    pkg_share = get_package_share_directory('terrain_mapping_drone_control')
    
    # Add static transforms for the camera
    static_transforms = [
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_to_camera_tf',
            parameters=[{'use_sim_time': True}],
            arguments=[
                '0.0', '0.0', '-0.15',  # Camera offset
                '0.0', '0.0', '0.0',    # No rotation
                'base_link',
                'camera_link'
            ]
        )
    ]

    # RViz configuration
    rviz_config_file = os.path.join(pkg_share, 'config', 'orbslam.rviz')
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config_file],
        output='screen'
    )

    # Add topic remapping node
    topic_remap = Node(
        package='topic_tools',
        executable='relay',
        name='camera_relay',
        parameters=[{'use_sim_time': True}],
        remappings=[
            ('input', '/drone_camera'),
            ('output', 'mono_py_driver/img_msg')
        ]
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='True',
            description='Use simulation (Gazebo) clock if true'),
        *static_transforms,
        topic_remap,
        rviz
    ]) 