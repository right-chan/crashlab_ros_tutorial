#include <ros/ros.h>
#include <my_msgs/SensorData.h>

void NumberCallback(const my_msgs::SensorData &msg)
{
    ROS_INFO("sub %d", msg.data);
}

// void NumberCallback(const std_msgs::Int16::ConstPtr &msg)
// {
//     ROS_INFO("sub %d", msg->data);
// }

int main(int argc, char** argv)
{
    ros::init(argc, argv, "sub_node");
    ros::NodeHandle nh;

    ros::Subscriber sub_number = nh.subscribe("/test/topic", 10, NumberCallback);

    ros::spin();
}