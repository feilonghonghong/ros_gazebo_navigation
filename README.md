# ros_gazebo_navigation
使用Gazebo仿真和ros的navigation栈实现了二轮差速小车的建图导航和避障，并添加了cartographer纯定位的使用和基于图像匹配的重定位功能。

各个功能包说明：

cartogrpaher_ros:  cartographer算法的ros包，详情可以搜索cartographer算法的安装运行

myrobot_description: 其中的word文件夹存放了仿真环境，urdf文件夹中存放二轮差速的小车模型

navigation_2d： 存放导航功能的launch文件以及参数配置文件，以及自己添加的节点

navigation-melodic： ROS官方导航栈

range_sensor_layer： 代价地图中用于处理红外超声波等传感器的插件

robot_pose_ekf： 扩展卡尔曼滤波包

teb_local_planner-melodic-devel： teb局部规划器

teleop_robot： 键盘控制

使用：

1.创建工程

```
$ mkdir catkin_ws
$ cd catkin_ws
$ mkdir src
然后将该项目中所有的包放入src中
```

2.编译工程

```
回到catkin_ws目录
$ catkin_make
如果提示缺少什么包，就安装什么包
```

3.运行

```
（1）打开一个终端，运行仿真环境
首先进入catkin_ws目录
$ source devel/setup.bash 
$ roslaunch myrobot_description gazebo_robot.launch 

（2）另外启动一个终端，启动导航
同样首先进入catkin_ws目录
$ source devel/setup.bash 
$ roslaunch navigation_2d nav_car.launch 
```

