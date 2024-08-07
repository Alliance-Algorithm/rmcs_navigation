from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    node = Node(
        package="rmcs_location",
        executable="rmcs_location_gicp",
        parameters=[[FindPackageShare("rmcs_location"), "/config", "/config.yaml"]],
        output="screen",
    )

    return LaunchDescription([node])
