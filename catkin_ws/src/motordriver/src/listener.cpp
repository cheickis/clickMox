
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include "roboclaw.h"
#include <stdio.h>  //printf
#include <stdlib.h> //exit
#include <unistd.h> //sleep


 struct roboclaw *rc;
int16_t voltage,  duty_cycle;

void initRoboclaw(){
   rc=roboclaw_init("/dev/ttyACM0", 115200);
}
void checkBatteryStatus(){
 roboclaw_main_battery_voltage(rc, 0x80, &voltage);
 float voltage_float = (float)voltage/10.0f;
 ROS_INFO("Battery level= %f",voltage_float);
}

int16_t getRobotSpeed(int16_t  sp){
    if( sp > 100 )
	sp = 100;
			
    if( duty_cycle < -100 )
	  sp = -100;
			
   return (float)sp/100.0f * 32767;
}

void closeRoboclaw(){
   roboclaw_close(rc);
}
void testRoboclaw()
{
      
       
        
	
}





void chatterCallback(const std_msgs::Int16::ConstPtr& msg)
{

  testRoboclaw();
  // ROS_INFO("I heard: [%d]", msg->data.c_str());
   ROS_INFO("I heard: [%d]", msg->data);
   //ROS_INFO("I heard:");
}


int main(int argc, char **argv)
{
   
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("Chatter", 1000, chatterCallback);

  ros::spin();


  return 0;
}

