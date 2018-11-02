#include <ros/ros.h>
#include <service_problem2/service_problem2_srv.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "service_problem2_client");
    ros::NodeHandle nh;

    ros::ServiceClient cli = nh.serviceClient<service_problem2::service_problem2_srv>(
        "service_problem2_srv" // server와 동일하게 맞춰야함
    );
    //  request를 받을 객체 생성

    service_problem2::service_problem2_srv srv;

    srv.request.a = rand()%6;
    srv.request.b = rand()%6;
    srv.request.calc = rand()%4;

    ROS_INFO("a, b : %d %d",srv.request.a, srv.request.b);
    switch(srv.request.calc)
    {
        case 0:
            ROS_INFO("a + b");
            break;
        case 1:
            ROS_INFO("a - b");
            break;
        case 2:
            ROS_INFO("a * b");
            break;
        case 3:
            ROS_INFO("a / b");
            break;
    }
    // request에 대한 구체적인 행동

    if(cli.call(srv))
    {
        ROS_INFO("service succeed!! \n result : %d", srv.response.result);
    }
    else
    {
        ROS_INFO("service failed....");
    }
    // 서버에 call 신호 보내기
}