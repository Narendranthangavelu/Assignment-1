#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <fstream>
#include <boost/bind.hpp>
using namespace std;


void callback1(const std_msgs::String::ConstPtr& msg, std::string path)
{
  ofstream myfile1(path +"/text1_cpp.txt",ios_base::app | ios_base::out);
  myfile1 <<msg-> data <<"\n";
}

void callback2 (const std_msgs::String::ConstPtr& msg, std::string path)
{

  ofstream myfile2(path +"/text2_cpp.txt",ios_base::app | ios_base::out);
  myfile2 <<msg-> data <<"\n";

}


int main(int argc, char **argv)
{

std::string path;
if (argc > 1)
{  path = argv[1];
}

ofstream myfile1(path +"/text1_cpp.txt");
myfile1.close();
ofstream myfile2(path +"/text2_cpp.txt");
myfile2.close();

ros::init(argc, argv, "text_writer_cpp");
ros::NodeHandle n;

ros::Subscriber sub1 = n.subscribe<std_msgs::String>("talk1_cpp", 10, boost::bind(callback1,_1,path) );
ros::Subscriber sub2 = n.subscribe<std_msgs::String>("talk2_cpp", 10, boost::bind(callback2,_1,path) );

ros::spin();


}
