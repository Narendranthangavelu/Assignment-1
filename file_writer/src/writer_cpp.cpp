#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <fstream>
#include <boost/bind.hpp>
using namespace std;


void callback1(const std_msgs::String::ConstPtr& msg, std::string path)
{ 
  ROS_INFO("%s is appended to  %s/text1_cpp.txt ",msg->data.c_str(),path.c_str());

  ofstream myfile1(path +"/text1_cpp.txt",ios_base::app | ios_base::out);
  myfile1 <<msg-> data <<"\n";
}

void callback2 (const std_msgs::String::ConstPtr& msg, std::string path)
{
  ROS_INFO("%s is appended to  %s/text2_cpp.txt ",msg->data.c_str(),path.c_str());

  ofstream myfile2(path +"/text2_cpp.txt",ios_base::app | ios_base::out);
  myfile2 <<msg-> data <<"\n";

}


int main(int argc, char **argv)
{

std::string path;

/*path for storing files */
path = argv[1];

/* creating an empty text files*/
ofstream myfile1(path +"/text1_cpp.txt");
myfile1.close();
ofstream myfile2(path +"/text2_cpp.txt");
myfile2.close();

/*intitializing the node*/
ros::init(argc, argv, "text_writer_cpp");
ros::NodeHandle n;

/*initalizing subscribers to the topics talk1_cpp and talk2_cpp*/
ros::Subscriber sub1 = n.subscribe<std_msgs::String>("talk1_cpp", 10, boost::bind(callback1,_1,path) );
ros::Subscriber sub2 = n.subscribe<std_msgs::String>("talk2_cpp", 10, boost::bind(callback2,_1,path) );

/*maintaining the node active*/
ros::spin();


}
