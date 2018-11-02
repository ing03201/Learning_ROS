#include "ros/ros.h" 
#include <cmath>
#include "cossin_service/SrvAngle.h"

bool calculation(cossin_service::SrvAngle::Request &req, cossin_service::SrvAngle::Response &res)
{
	res.cosValue = cos(req.angle*(3.14/180));
        res.sinValue = sin(req.angle*(3.14/180));

	ROS_INFO("request: x=%lf", (float)req.angle);
	ROS_INFO("Sending back response: %4.2f,%4.2f", (float)res.cosValue, (float)res.sinValue);

	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "cossin_server");
	ros::NodeHandle nh;

	ros::ServiceServer service_server = nh.advertiseService("cossin_srv", calculation);

	ROS_INFO("ready srv server!");
	
	ros::spin();

	return 0;
}

