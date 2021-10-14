#include <ros/ros.h>
#include <my_msgs/AddTwoInts.h>

// using namespace std;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "client_node");
	ros::NodeHandle nh;

	ros::ServiceClient client = nh.serviceClient<my_msgs::AddTwoInts>("/add_two_ints");

	ros::Rate loop_rate(1);

	int a=0, b=0;

	while(ros::ok())
	{
		my_msgs::AddTwoInts srv;
		srv.request.a = a++;
		srv.request.b = b++;

		if(client.call(srv))
		{
			ROS_INFO("%d + %d = %d", srv.request.a, srv.request.b, srv.response.result);
		}
		loop_rate.sleep();
	}
}