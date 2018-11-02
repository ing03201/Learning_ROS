#include <ros/ros.h>
#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "my_first_ros_package");
    ros::NodeHandle nh;

    ros::Rate loop_rate(10); //10hz
    int ary[2] ={1,1};
    while (true)
    {
        int next = ary[0]+ary[1];
        ary[0] = ary[1];
        ary[1] = next;
        ROS_INFO("ary[0] : %d, ary[1] : %d", ary[0],ary[1]);
        loop_rate.sleep();
    }
    return 0;
}