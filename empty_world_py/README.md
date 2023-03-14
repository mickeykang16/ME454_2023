# Empty world with gazebo_ros_state plug-in
### Installation
```
# skip --- mkdir -p ~/ros2_ws/src && cd ~/ros2_ws/src
# skip --- ros2 pkg create --build-type ament_python empty_world_py
>> cd ~/ros2_ws/src
# remove all files in ~/ros2_ws/src before executing the following command
# note the dot "." at the end of the command
>> git clone https://github.com/skoo1/ME454_2023.git .
>> cd ~/ros2_ws
>> colcon build --symlink-install
>> source ~/ros2_ws/install/setup.bash
# open gazebo using the world file in this package
# make sure that you have a X-server (like Xming) running
>> ros2 launch empty_world_py empty_world.launch.py
```
### Test the gazebo simulation environment
```
# open a new ubuntu shell
# check gazebo topics and services
>> ros2 topic list
>> ros2 service list
# spawn a urdf model at position (0, 0, 1) in meter
>> ros2 run gazebo_ros spawn_entity.py -file ~/ros2_ws/src/oneball_urdf/oneball.urdf -entity oneball -z 1
# transport the model to (0, 0, 5) and throw it to y direction at 10.0 m/s
>> ros2 service call /me454/set_entity_state gazebo_msgs/srv/SetEntityState "state: {name: 'oneball', pose: {position: {x: 0.0, y: 0.0, z: 5.0}, orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}}, twist: {linear: {x: 0.0, y: 10.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}, reference_frame: ''}"

```


## Notes
### in package.xml
```
Line 015   <exec_depend>ros2launch</exec_depend>
```
### in setup.py
```
Line 001 import os
Line 002 from glob import glob
Line 015 (os.path.join('share', package_name, 'launch'), glob('launch/*')),
```
## Also see the files in launch
- empty_world.launch.py
- empty_state.world
  - libgazebo_ros_state.so is loaded through the world file

## References
- ROS 2 Documentation (Foxy), Creating a package
  - https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Creating-Your-First-ROS2-Package.html
- ROS 2 Documentation (Foxy), Creating a launch file
  - https://docs.ros.org/en/foxy/Tutorials/Intermediate/Launch/Creating-Launch-Files.html
- ROS 2 Documentation (Foxy), Using Python, XML, and YAML for ROS 2 Launch Files
  - https://docs.ros.org/en/foxy/How-To-Guides/Launch-file-different-formats.html
- Tutorial: ROS2 launch files – All you need to know
  - https://roboticscasual.com/tutorial-ros2-launch-files-all-you-need-to-know/
