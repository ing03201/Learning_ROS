#include <ros/ros.h>
#include <param_problem1/param_problem1_msg.h>
// 
static int parameter = 0;
static int before = 0;
static double num[5];
void msgCallback(const param_problem1::param_problem1_msg::ConstPtr& msg)
{
    if(parameter > 0 && parameter <5 && before != parameter)
    {
        for(int i = 0; i < 5; i++)
            num[i] = pow(msg->num[i],-(double)parameter);
        before = parameter;
    }
    for(int i =0; i<5; i++)
        ROS_INFO("num[%d] = %10.5lf", i, num[i]);
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "param_problem1_sub");
    ros::NodeHandle nh;

    nh.getParam("square",parameter);
    // 터미널에 rosparam 

    ros::Subscriber sub = nh.subscribe("param_problem1_pub", 10, msgCallback);
}