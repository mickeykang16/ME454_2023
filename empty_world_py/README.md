# Empty world with gazebo_ros_state plug-in
### mkdir -p ~/ros2_ws/src && cd ~/ros2_ws/src
### ros2 pkg create empty_world_py --build-type ament_python
### cd ~/ros2_ws
### colcon build --symlink-install
### source ./install/setup.bash
### ros2 launch empty_world_py empty_world.launch.py
### ros2 run gazebo_ros spawn_entity.py -file ~/ros2_ws/src/oneball_urdf/oneball.urdf -entity oneball -z 1
### ros2 service call /me454/set_entity_state gazebo_msgs/srv/SetEntityState "state: {name: 'oneball', pose: {position: {x: 0.0, y: 0.0, z: 5.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, twist: {linear: {x: 0.0, y: 10.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}, reference_frame: ''}"
  
## Notes
### in package.xml
#### <exec_depend>ros2launch</exec_depend>
### in setup.py
#### import os
#### from glob import glob
#### (os.path.join('share', package_name, 'launch'), glob('launch/*')),
  
## Also see the files in launch
