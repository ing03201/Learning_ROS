#include <ros/ros.h>
// #include <패키지 이름 / 메시지.h>
#include "topic_problem2/topic_problem2_msg.h"

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "topic_problem2_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<topic_problem2::topic_problem2_msg>("topic_problem2_pub",10);

    topic_problem2::topic_problem2_msg msg;

    ros::Rate loop_rate(10);
    srand(time(NULL));
    while(true)
    {
        msg.num = 1 + rand()%4;
        pub.publish(msg);
        loop_rate.sleep();
    }
}