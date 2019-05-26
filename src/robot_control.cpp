#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>

class robot_control
{
private:
    ros::NodeHandle n;
    ros::Publisher vel_robot;

    float max_lin_speed = 2;
    float min_lin_speed = -2;

    float max_ang_speed = 1;
    float min_ang_speed = -1;

    ros::Time last_time = ros::Time(0);

public:

    robot_control()
    {
        vel_robot = n.advertise<geometry_msgs::Twist>("/RosAria/cmd_vel",1);
    }

    void pub_vel_robot(geometry_msgs::Twist spd_msg)
    {
        vel_robot.publish(spd_msg);
    }

};



int _kbhit()
{
    static const int KBIN = 0;
    static bool start = false;

    if(!start)
    {
        termios term;
        tcgetattr(KBIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(KBIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        start = true;

    }
    int bytesInBuff;
    ioctl(KBIN,FIONREAD,&bytesInBuff);
    return bytesInBuff;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "robot_control");

    robot_control KCObject;

    while(ros::ok())
    {
        if(_kbhit())
        {
            geometry_msgs::Twist vel_robot;

            int c = getchar(); //Call to the function without blocking the function


            if( c =='w' || c == 'A')
            {
                vel_robot.linear.x = 0.400;
                KCObject.pub_vel_robot(vel_robot);
            }
            else if ( c == 's' || c == 'B')
            {
                vel_robot.linear.x = -0.100;
                KCObject.pub_vel_robot(vel_robot);
            }
            else if (c == 'a'|| c == 'D')
            {
                vel_robot.angular.z = 0.5250;
                KCObject.pub_vel_robot(vel_robot);
            }
            else if (c == 'd' || c == 'C')
            {
                vel_robot.angular.z = -0.5250;
                KCObject.pub_vel_robot(vel_robot);
            }
            else
            {
                vel_robot.angular.z = 0;
                vel_robot.linear.x = 0;
                KCObject.pub_vel_robot(vel_robot);
            }


        }

        ros::Rate r(1000);
        ros::spinOnce();
        r.sleep();
    }
    ros::spin();

    return 0;
}
