#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"
#include "turlesim/Pose.h"
#include <cstdlib>
#include <iostream>

using namsepace std;

geometry_msgs::Twist cmdVel;
geometry_msgs::Pose2D current;
geometry_msgs::Pose2D desired;


const double GOAL =1.5;
const double kl = 1;

const double distanceTolerance = .1;


void misc_setup(){
   desired.x = GOAL;
   cmdVel.linear.x=0;
   cmdVel.linear.y=0;
   cmdVel.linear.z=0;
   cmdVel.angular.x=0;
   cmdVel.angular.y=0;
}


void update_poste(const turtlesim::PoseConstr &currentPose){
 current.x = currentPose->x;
 current.y = currentPose->y;
 current.z = currentPose->z;
}

double getDistanceError(){

  return desired.x - current.x;
}


void set_velocity(){

   if (abs(getDistance())> distanceTolerance){
    cmdVel.linear.x = kl * getDistanceError();
   }else{
    cout<<"I'm Here!" <<endl;
   }
}




int main (int argc, char **argv){
    
    misc_setup();
    ros::init(argc, argv, "go_to_x");
    ros::NodeHandle node;
    ros::Subscriber sub =  node.subscribe("turle1/pose",0,update_pose);
    ros::Publisher pubVelocity = node.adverstise<geometry_msgs::Twist>("turtle1/cmd_vel",0);
    ros::Rate loop_rate(10);

   while(ros::ok){
       ros::spinOnce();
       set_veolicty();
       pubVelocity.publish(cmdVel);
       cout << "goal x= " <<desired.x <<endl;
       cout << "current x= " <<current.x <<endl;
       cout << "disError= " << getDistanceError()<<endl;
       cout << "cmd_vel= " <<cmdVel.linear.x <<endl;

      loop_rate.sleep();

   }
 return 0;

}
