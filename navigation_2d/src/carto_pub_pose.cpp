#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Pose2D.h>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;
double x,y,z, qx,qy,qz, qw;
double theta;
geometry_msgs::Pose2D pos_now;

int main(int argc, char** argv){
  ros::init(argc, argv, "carto_pub_pose");
 
  ros::NodeHandle node;
  ros::Publisher _pose_pub=node.advertise<geometry_msgs::Pose2D>("pose_data", 10);
  tf::StampedTransform transform;
  tf::TransformListener listener;
  ros::Rate rate(10.0);

  while (ros::ok()){
    ros::Time start = ros::Time::now();
    cout << "StartTime:"<< start << endl;
    tf::StampedTransform transform;
    try{
        //得到坐map和坐标base_link之间的关系
      listener.waitForTransform("map","base_footprint",  ros::Time(0), ros::Duration(3.0));
      listener.lookupTransform("map", "base_footprint", ros::Time(0), transform);
    }
    catch (tf::TransformException &ex) {
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }
 
    x=transform.getOrigin().x();
    y=transform.getOrigin().y();
    z=transform.getOrigin().z();
  
	tf::Quaternion q = transform.getRotation();
    qx = q.x();
    qy = q.y();
	 qz = q.z();
	 qw = q.w();

  pos_now.x = transform.getOrigin().x();
  pos_now.y =transform.getOrigin().y();
  pos_now.theta = tf::getYaw(q);
  _pose_pub.publish(pos_now);
	printf("x: %f, y: %f, z: %f, qx: %f,qy: %f,qz: %f, qw: %f, theta: %f\n",x,y,z,qx,qy,qz,qw,pos_now.theta);
    rate.sleep();
    
  ros::Time end = ros::Time::now();
  cout << "EndTime:"<<end << endl;
  }
  return 0;
};