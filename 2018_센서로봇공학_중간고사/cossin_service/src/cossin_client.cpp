#include "ros/ros.h"
#include "cossin_service/SrvAngle.h"
#include <cstdlib>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "cossin_client");

	if(argc != 2)
	{
		ROS_INFO("cmd : rosrun cossin_service cosin_client arg0");
		ROS_INFO("arg0: double angle value");
		
		return 1;
	}
	
	ros::NodeHandle nh;
	ros::Rate loop_rate(0.5);
	
	ros::ServiceClient service_client =
	nh.serviceClient<cossin_service::SrvAngle>("cossin_srv");
	
	cossin_service::SrvAngle srv;

	for(int i=0;i <10;i++)
	{
		srv.request.angle = atof(argv[1]);

		if(service_client.call(srv))
		{
			ROS_INFO("send srv, Request.angle:%lf",(float)srv.request.angle);
			ROS_INFO("receive srv, Response.cosvalue:%4.2f, Response.sinvalue:%4.2f",(float)srv.response.cosValue,(float)srv.response.sinValue );
		}
		else
		{
			ROS_ERROR("Failed to call service cossin_srv");
			return 1;
		}
		loop_rate.sleep();
	}	

	return 0;
}
