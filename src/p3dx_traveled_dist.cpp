#include <ros/ros.h>
#include <tf/tf.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>
#include <math.h>

extern float x_ant, x_act, y_ant, y_act;


void chatterCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    float x_ant = 0.0, y_ant = 0.0, x_act, y_act;


        ROS_INFO("Seq: [%d]", msg->header.seq);
        ROS_INFO("Position-> x: [%f], y: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y);
        ROS_INFO("Orientation-> z: [%f], w: [%f]", msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
        ROS_INFO("Travelled Dist-> Linear: [%f], Angular: [%f]", msg->twist.twist.linear.x,msg->twist.twist.angular.z);
}

int main(int argc, char **argv)
{
        ros::init(argc, argv, "p3dx_traveled_dist");
        ros::NodeHandle n;

        ros::Subscriber sub = n.subscribe("/RosAria/pose",1000, chatterCallback);

        ros::spin();
        return 0;
}

float distance(float x_ant,float x_act, float y_ant, float y_act)
{
    float dist = sqrt((pow((x_ant-x_act),2.0))+(pow((y_ant-y_act),2.0)));

    return dist;
}
