#include <ros/ros.h>
#include "topic_problem2/topic_problem2_msg.h"

void msgCallback(const topic_problem2::topic_problem2_msg::ConstPtr& msg)
{
    switch (msg->num)
    {
        case 1:
            ROS_INFO("message 1");
            ROS_INFO("*");
            break;
        case 2:
            ROS_INFO("message 2");
            for(int i =0; i < msg->num; i++)
            {
                ROS_INFO("** **");
            }
            break;
        case 3:
            ROS_INFO("message 3");
            for(int i =0; i < msg->num; i++)
            {
                if(i == 1)
                    ROS_INFO("* * * * * *");
                else
                    ROS_INFO("*** *** ***");
            }
            break;
        case 4:
            ROS_INFO("message 4");
            for(int i =0; i < msg->num; i++)
            {
                if(i == 1 || i == 2)
                    ROS_INFO("*  * *  * *  * *  *");
                else
                    ROS_INFO("**** **** **** ****");
            }
            break;
        default:
            ROS_ERROR("why control ");
            break;
    }
    
    
    
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "topic_problem2_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("topic_problem2_pub", 10, msgCallback);
    ros::spin();
}