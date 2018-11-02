#include <ros/ros.h>
#include <service_problem1/service_problem1_srv.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "service_problem1_client");
    ros::NodeHandle nh;

    ros::ServiceClient cli = nh.serviceClient<service_problem1::service_problem1_srv>(
        "service_problem1_srv" // server와 동일하게 맞춰야함
    );
    //  request를 받을 객체 생성

    srand(time(NULL));
    service_problem1::service_problem1_srv srv;
    srv.request.num = (((long)rand()<<15|rand())%10000)+1;
    ROS_INFO("is %ld prime number?",srv.request.num);
    // request에 대한 구체적인 행동

    if(cli.call(srv))
    {
        ROS_INFO("Request is successed!");
        if(srv.response.result)
            ROS_INFO("%ld is prime number", srv.request.num);
        else
            ROS_INFO("%ld is not prime number", srv.request.num);
    }
    else
    {
        ROS_INFO("service fail!");
    }
    // 서버에 call 신호 보내기
    // ros::spin(); - 이건 클라이언트에선 필요 없음 
}