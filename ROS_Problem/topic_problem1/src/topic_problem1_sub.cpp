#include <ros/ros.h>
#include "topic_problem1/topic_problem1_msg.h"
#include <deque>

using namespace std;

std::deque<int64_t> data;


void msgCallback(const topic_problem1::topic_problem1_msg::ConstPtr& msg)
{
    int64_t sum = 0;
    int64_t average = 0;
    //  double average = 0;
    if(data.size() >= 10)
        data.pop_front();
    data.push_back(msg->num);
    /*
    data.push_back(msg->num);
    if(data.size()>10)
        data.pop_front();
    */
    for(int i =0; i<10; i++)
        sum += data[i];
    average = sum / 10;
    // average = sum / 10.0 이러면 정수 나누기 실수형 => 실수형으로 자동 변환됨

    ROS_INFO("sum : %ld", sum);
    ROS_INFO("average : %ld", average);
    ROS_INFO("message : %ld", msg->num);
    ROS_INFO("==================");
    
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "topic_problem1_sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("topic_problem1_pub", 10, msgCallback);
    ros::spin();
}