#include <ros/ros.h>
// #include <패키지 이름 / 메시지.h>
#include "topic_problem1/topic_problem1_msg.h"

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "topic_problem1_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<topic_problem1::topic_problem1_msg>("topic_problem1_pub",10);

    topic_problem1::topic_problem1_msg msg;

    ros::Rate loop_rate(10); // 10Hz로 퍼블리시 함. 
    srand(time(NULL));
    while(true)
    {
        msg.num = rand()%22;
        pub.publish(msg);
        loop_rate.sleep();
    }
}
