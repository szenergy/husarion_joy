#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>

// Std Libs
#include <stdint.h>

// ROS Nodehandles and Publishers
ros::NodeHandle *nh;
ros::Publisher estop_pub;
ros::Publisher vel_pub;

geometry_msgs::Twist twist;

// ROS Callbacks
void joy_cb(const sensor_msgs::Joy::ConstPtr& msg);

// ROS Params
double lag = 0.25;
int linear = 1;
int angular = 2;
double speed_l = 0.5;
double speed_a = 1;

void joy_cb(const sensor_msgs::Joy::ConstPtr& joy){
 if(joy->axes[linear]){
 twist.linear.x *= lag;
 twist.linear.x = (1.0 - lag) * speed_l* joy->axes[linear];
 vel_pub.publish(twist);
 }else
 {
 twist.linear.x = 0;
 vel_pub.publish(twist);
 }
 if(joy->axes[angular]){
 twist.angular.z *= lag;
 twist.angular.z = (1.0 - lag) * speed_a * joy->axes[angular];
 vel_pub.publish(twist);
 }else
 {
 twist.angular.z = 0;
 vel_pub.publish(twist);
 }
}

int main(int argc, char** argv){
// Init
ros::init(argc, argv, "joy_to_something_node");
nh = new ros::NodeHandle();
ros::Rate loop_r(10);

// Subs
ros::Subscriber joy_sub = nh->subscribe("joy", 10, joy_cb);

// Pubs
vel_pub = nh->advertise<geometry_msgs::Twist>("cmd_vel", 1);

twist.linear.x = 0;
twist.angular.z = 0;

while(ros::ok()){
   vel_pub.publish(twist);
   ros::spinOnce();
   loop_r.sleep();
}
}
