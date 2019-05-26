#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float64.h"


#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>

class robot_control_battery
{
private:
    ros::NodeHandle n;
    ros::Publisher vel_robot;
    ros::Subscriber battery_level;

    ros::Time last_time = ros::Time(0);

public:

    robot_control_battery()
    {
        vel_robot = n.advertise<geometry_msgs::Twist>("/RosAria/cmd_vel",1);

        battery_level = n.subscribe<std_msgs::Float64>("/RosAria/battery_voltage",1,&);

    }
    void pub_vel_robot(geometry_msgs::Twist spd_msp)
    {
        vel_robot.publish(spd_msp);
    }
    double get_battery_vol()
    {
        double bat_volt = battery_level.getTopic();

        return;
                bat_volt;
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
    ros::init(argc, argv, "robot_control_battery");

    robot_control_battery KCObject;

    while(ros::ok())
    {
        while()
        {
            if(_kbhit())
            {
                geometry_msgs::Twist vel_robot;

                int c = getchar(); //Call to the function without blocking the function

                if( c =='w' ) //
                {
                    vel_robot.linear.x = 0.5;
                    KCObject.pub_vel_robot(vel_robot);
                }
                else if ( c == 's' )
                {
                    vel_robot.linear.x = -0.5;
                    KCObject.pub_vel_robot(vel_robot);
                }
                else if (c == 'a')
                {
                    vel_robot.angular.z = 0.3;
                    KCObject.pub_vel_robot(vel_robot);
                }
                else if (c == 'd')
                {
                    vel_robot.angular.z = -0.3;
                    KCObject.pub_vel_robot(vel_robot);
                }
                else
                {
                    vel_robot.angular.z = 0;
                    vel_robot.linear.x = 0;
                }


            }
        }

        ros::Rate r(500);
        ros::spinOnce();
        r.sleep();
    }
    ros::spin();

    return 0;
}

