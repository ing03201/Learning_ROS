#include <ros/ros.h>
#include <service_problem2/service_problem2_srv.h>


bool calculate(service_problem2::service_problem2_srv::Request& req,
    service_problem2::service_problem2_srv::Response& res)
    {
        ROS_INFO("got request a, b : %d %d",req.a, req.b);
    switch(req.calc)
    {
        case 0:
            ROS_INFO("a + b");
            res.result = req.a + req.b;
            break;

        case 1:
            ROS_INFO("a - b");
            res.result = req.a - req.b;
            break;
        
        case 2:
            ROS_INFO("a * b");
            res.result = req.a * req.b;
            break;
        case 3:
            ROS_INFO("a / b");
            if(req.b == 0)
                ROS_INF0("infinity");
            else
                res.result = req.a / req.b;
            break;

        default:
            break;
    }
    return true;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "service_problem2_server");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("service_problem2_srv",calculate);
    // 함수를 기술해야함.
    ROS_INFO("service server start....");
    ros::spin();
}