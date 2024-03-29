# ME454 Dynamics System Programming
### Department of Mechanical Engineering, KAIST, South Korea  
- Lecturer : Prof. Seungbum Koo (skoo at kaist.ac.kr)  
- TA : Seungwoo Yoon (seungwoo.yoon at kaist.ac.kr), Junyo Boo (junyo94 at kaist.ac.kr), Jeongseok Oh (dhwjdtjr0 at kaist.ac.kr), Gunwoo Park (parkgw at kaist.ac.kr), and Beomsoo Shin (sbs0323 at kaist.ac.kr)
  
## Packages for practice sessions
### The packages are tested in WSL2 Ubuntu 20.04 with ROS2 Foxy and Gazebo 11 (classic)
  
### Installation
```
>> mkdir -p ~/ros2_ws/src && cd ~/ros2_ws/src
# remove all files in ~/ros2_ws/src before executing the following command
# note the dot "." at the end of the command
>> git clone https://github.com/skoo1/ME454_2023.git .
>> cd ~/ros2_ws
>> colcon build --symlink-install
>> source ~/ros2_ws/install/setup.bash
# open gazebo using the world file in this package
>> ros2 launch <package_name> <launch_file_name>
```
See the documents (README.MD) in the weekly project folders for details

### Week 2. Ubuntu and ROS 2 installation

### Week 3. Linux commands
- Homework #1  

### Week 4. CPP practice
- [CPP Practice #1](./cpp_practice1)  
- [Ball throwing (package)](./ball_throwing)  
  - SDF file
  - Mechanical properties of a single object
  - ROS service call

### Week 5. CPP practice
- [CPP Practice #2](./cpp_practice2)  
- [Pendulum movement (package)](./pendulum_movement)  
  - Multi-body system simulation  
- Homework #2  
