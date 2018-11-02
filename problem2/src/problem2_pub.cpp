#include <ros/ros.h>
#include <cstdlib>
#include "problem2/problem2_msg.h"

using namespace std;
int main(int argc, char **argv){
    ros::init(argc, argv, "problem2");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<problem2::problem2_msg>(
        "problem2", 1000);
    ros::Rate loop_rate(10);

    problem2::problem2_msg msg;
    u_int16_t r1;
    u_int16_t r2;
    int count = 0;
    std::vector<u_int16_t>::iterator i;
    
    srand(time(NULL));

    while(ros::ok()){
        msg.stamp = ros::Time::now();
        r1 = 1 + rand()%20;
        msg.v.assign(r1,0);
        count = 0;
        msg.r = r1;
        i = msg.v.begin();
        while(i != msg.v.end()){
            r2 = 1 + rand()%20;
            *i = r2;
            i++;
        }
        pub.publish(msg);
        loop_rate.sleep();
        // ROS_INFO();
        count++;
    }
    return 0;

}