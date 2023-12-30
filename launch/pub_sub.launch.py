import launch
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    container = ComposableNodeContainer(
            name='image_container',
            namespace='',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package='pub_sub_int32',
                    plugin='pub_sub_int32::pub_int',
                    name='node_talker'),
                ComposableNode(
                    package='pub_sub_int32',
                    plugin='pub_sub_int32::sub_int',
                    name='node_listener')
            ],
    )

    return launch.LaunchDescription([container])