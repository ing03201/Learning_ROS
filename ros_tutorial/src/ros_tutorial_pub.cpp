#include <ros/ros.h>
#include "ros_tutorial/ros_tutorial_msg.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "ros_tutorial_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<ros_tutorial::ros_tutorial_msg>(
        "ros_tutorial", 1000);
    ros::Rate loop_rate(10); //10hz
    ros_tutorial::ros_tutorial_msg msg;
    while (true)
    {
        msg.i = 1;
        msg.j = 2;
        ROS_INFO("Hello world");
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}