from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='customer_and_peets',
            executable='customer_node',
            name='customer_node',
            output='screen'
        ),
        Node(
            package='customer_and_peets',
            executable='peets_node',
            name='peets_node',
            output='screen'
        )
    ])
