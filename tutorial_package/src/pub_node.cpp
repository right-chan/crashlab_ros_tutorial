#include <ros/ros.h>
#include <my_msgs/SensorData.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "pub_node");
	ros::NodeHandle nh;

	ros::Publisher pub_number = nh.advertise<my_msgs::SensorData>("/test/topic", 10);

	ros::Rate loop_rate(10);
	my_msgs::SensorData count;

	while(ros::ok())
	{
		pub_number.publish(count);
		ROS_INFO("pub %d", count.data);
		count.data++;

		ros::spinOnce();
		loop_rate.sleep();
	}
}