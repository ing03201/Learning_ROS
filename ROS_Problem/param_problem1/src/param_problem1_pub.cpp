#include <ros/ros.h>
// #include <패키지 이름 / 메시지.h>
#include <param_problem1/param_problem1_msg.h>
static int parameter = 0;
static int frequancy = 10;
int main(int argc, char* argv[])
{
    ros::init(argc, argv, "param_problem1_pub");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<param_problem1::param_problem1_msg>("param_problem1_pub",10);
    // nh.setParam("pow",1); 터미널에서 가능함.
    // nh.setParam("frequancy",10); 터미널에서 가능함.
    // nh.getParam("frequancy",frequancy);
    if(!nh.getParam("frequancy",frequancy))
        ROS_ERROR(param frequancy no exist!!);
    param_problem1::param_problem1_msg msg;

    ros::Rate loop_rate(frequancy);
    for(double i=0; i<5; i++)
        msg.num[i] = i;
    int before = 0;
    while(true)
    {
        nh.getParam("pow",parameter);
        if(parameter > 0 && parameter <5 && before != parameter)
        {
            for(int i = 0; i < 5; i++)
                msg.num[i] = pow(msg.num[i],(double)parameter);
            before = parameter;
        }
        pub.publish(msg);
        loop_rate.sleep();
    }
}