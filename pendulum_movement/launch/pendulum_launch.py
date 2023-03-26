# Copyright 2019 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.substitutions import ThisLaunchFileDir
from launch_ros.substitutions import FindPackageShare



def generate_launch_description():

	file_path = os.path.realpath(__file__)
	file_dir = os.path.dirname(file_path)
	pkg_src_dir = os.path.join(file_dir, '..', '..', '..', '..', 'src', 'pendulum_movement')
	
	world_file_name = 'pendulum.world'
	world_path = os.path.join(pkg_src_dir, 'worlds', world_file_name)

	world = LaunchConfiguration('world')

	return LaunchDescription([

		IncludeLaunchDescription(
			PythonLaunchDescriptionSource(['/opt/ros/foxy/share/gazebo_ros/launch/gzserver.launch.py']),
			launch_arguments={'world': world_path}.items()
		),

		IncludeLaunchDescription(
			PythonLaunchDescriptionSource(['/opt/ros/foxy/share/gazebo_ros/launch/gzclient.launch.py']),
		),
	])

