from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        # Start the turtlesim node
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='turtlesim'
        ),
        
        # Start our lawnmower controller
        Node(
            package='turtlesim_survey_demo',
            executable='lawnmower_controller',
            name='lawnmower_controller'
        )
    ])
