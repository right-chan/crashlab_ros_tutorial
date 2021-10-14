#include <ros/ros.h>
#include <my_msgs/AddTwoInts.h>

bool add(my_msgs::AddTwoInts::Request &req,my_msgs::AddTwoInts::Response &res)
{
	res.result = req.a+req.b;
	return true;
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "server_node");
	ros::NodeHandle nh;

	ros::ServiceServer service = nh.advertiseService("/add_two_ints", add);
	ros::spin();
}