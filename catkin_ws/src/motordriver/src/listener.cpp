
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include "roboclaw.h"
#include <stdio.h>  //printf
#include <stdlib.h> //exit
#include <unistd.h> //sleep


struct roboclaw *rc;
int16_t voltage,  duty_cycle;
uint8_t address=0x80; //address of roboclaw unit

void checkBatteryStatus(){
 roboclaw_main_battery_voltage(rc, 0x80, &voltage);
 float voltage_float = (float)voltage/10.0f;
 ROS_INFO("Battery level= %f",voltage_float);
}

void initRoboclaw(){
   ROS_INFO("Roboclaw Motor driver initilisation");
   rc=roboclaw_init("/dev/ttyACM0", 115200);

   if(rc==NULL){
      ROS_FATAL("Cannot connect to the roboclaw driver!");
    }else{
       ROS_INFO("Connexion done!");
   }
  checkBatteryStatus();
}


int16_t getRobotSpeed(int16_t  sp){
    if( sp > 100 )
	sp = 100;
			
    if( duty_cycle < -100 )
	  sp = -100;
			
   return (float)sp/100.0f * 32767;
}

void closeRoboclaw(){

   ROS_INFO("stopping the motors..\n");
   roboclaw_duty_m1m2(rc, address, 0, 0);
		
   if(roboclaw_close(rc) != ROBOCLAW_OK)
       ROS_ERROR("unable to shutdown roboclaw cleanly");
   
}

int drive(int leftSp, int rightSp){
     
    int result = roboclaw_duty_m1m2(rc, address, leftSp, rightSp) ;
   if( result!= ROBOCLAW_OK )
   {
     ROS_ERROR( "problem communicating with roboclaw, terminating\n");
			return -1;			
   } 
  return ROBOCLAW_OK;
}

int left(int16_t sp){
   int leftSp = getRobotSpeed( -sp);
   int rightSp = getRobotSpeed(7);

 
  int result = roboclaw_duty_m1m2(rc, address, -leftSp, -rightSp) ;
   if( result!= ROBOCLAW_OK )
   {
     ROS_ERROR( "problem communicating with roboclaw, terminating\n");
			return -1;			
   } 
  return ROBOCLAW_OK;

}

int right(int sp){
  int rightSp = getRobotSpeed( sp);
  int leftSp = getRobotSpeed(7);
  int result = roboclaw_duty_m1m2(rc, address, leftSp, -rightSp) ;
   if( result!= ROBOCLAW_OK )
   {
     ROS_ERROR( "problem communicating with roboclaw, terminating\n");
			return -1;			
   } 
  return ROBOCLAW_OK;


}


int backward(int sp){
  int mtrSp = getRobotSpeed( sp);
  int result = roboclaw_duty_m1m2(rc, address, -mtrSp, mtrSp) ;
   if( result!= ROBOCLAW_OK )
   {
     ROS_ERROR( "problem communicating with roboclaw, terminating\n");
			return -1;			
   } 
  return ROBOCLAW_OK;

}


int forward(int sp){
  int mtrSp = getRobotSpeed( sp);
  int result = roboclaw_duty_m1m2(rc, address, mtrSp, -mtrSp) ;
   if( result!= ROBOCLAW_OK )
   {
     ROS_ERROR( "problem communicating with roboclaw, terminating\n");
			return -1;			
   } 
  return ROBOCLAW_OK;
}


void testRoboclaw()
{
      initRoboclaw();
      
}


void testDriving(const std_msgs::Int16::ConstPtr& msg){
   // duty_cycle = getRobotSpeed( msg->data)
    //drive(duty_cycle, duty_cycle);
    // forward(msg->data);
    //backward(msg->data);
   // left(msg->data);
    right(msg->data);

 }
void chatterCallback(const std_msgs::Int16::ConstPtr& msg)
{

   ROS_INFO("New speed Value: [%d]", msg->data);
   testDriving(msg);
 
}

void timer_callback(const ros::TimerEvent &event){

   ROS_INFO("In timer callback");
}
int main(int argc, char **argv)
{
  
   testRoboclaw();
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  
  
  ros::Subscriber sub = n.subscribe("Chatter", 1000, chatterCallback);

  ros::spin();

  closeRoboclaw();
 
  return 0;
}

