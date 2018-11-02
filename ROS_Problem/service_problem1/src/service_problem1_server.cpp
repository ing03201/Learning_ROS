#include <ros/ros.h>
#include <service_problem1/service_problem1_srv.h>
// 메시지를 원래 패키지에 넣지 않음! => 서버와 클라이언트를 따로따로 만들기 때문! 
// 더 큰 패키지를 생성 -> 메시지 파일을 만든후 패키지를 종속 시킨다.


bool find_prime(service_problem1::service_problem1_srv::Request& req,
    service_problem1::service_problem1_srv::Response& res)
{
        ROS_INFO("find prime number : %ld",req.num);
        for(int64_t i = 2; i <= req.num; i++)
        {
            if(req.num % i == 0)
            {
                if(req.num == i)
                    res.result = true;
                else
                {
                    res.result = false; // 결과값
                    break;
                }
            }
            /*
            */
        }
        
        return true; // 서버가 작동한다 안한다 
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "service_problem1_server");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("service_problem1_srv",find_prime);
    // 함수를 기술해야함.
    ROS_INFO("service server start....");
    ros::spin();
}