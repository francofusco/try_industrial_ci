#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "foo_node");
  ros::NodeHandle nh("~");
  std_msgs::String msg;
  nh.param<std::string>("message", msg.data, "Hello, World!");
  ros::Publisher pub = nh.advertise<std_msgs::String>("message", 1);
  ros::Rate r(1.5);
  while(ros::ok()) {
    pub.publish(msg);
    r.sleep();
  }
  return 0;
}
