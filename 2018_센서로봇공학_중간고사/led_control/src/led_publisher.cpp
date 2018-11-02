#include <ros/ros.h>
#include "led_control/MsgLedControl.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "led_publisher");
	ros::NodeHandle nh;
	
	ros::Publisher led_pub = nh.advertise<led_control::MsgLedControl>("display_led",100);
	
	ros::Rate loop_rate(0.5);

         
        led_control::MsgLedControl msg;
        int count = 0;
	
	while(ros::ok())
	{
	//	msg.stamp = ros::Time::now();
		msg.data = count;
	//	ROS_INFO("send msg = %d", msg.stamp.sec);
	//	ROS_INFO("send msg = %d", msg.stamp.nsec);
		ROS_INFO("send msg = %d", msg.data);
		
		led_pub.publish(msg);

		loop_rate.sleep();
		
		count++;
	}

	return 0;
}
