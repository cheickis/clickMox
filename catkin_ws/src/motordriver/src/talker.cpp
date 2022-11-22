#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int16.h"
#include <sstream>
#include  <iostream>

using namespace std;

int main(int argc, char **argv){

ros::init(argc, argv, "talker");

ros::NodeHandle n;
ros::Publisher chatter_pub = n.advertise<std_msgs::Int16>("Chatter",1000);
ros::Rate loop_rate(10);

int count = 0;
while(ros::ok()){
   int sp = 0;
   cout<<"Enter a value " <<endl;
   cin >> sp;
   std_msgs::Int16 value;
   value.data = sp;
   //std_msgs::String msg;
   //std::stringstream ss;
   //ss<<"hello world" <<count;
  // msg.data = ss.str();
   ROS_INFO("%d",value.data);
   chatter_pub.publish(value);
   ros::spinOnce();
   loop_rate.sleep();
  // ++count;
}

return 0;

}
