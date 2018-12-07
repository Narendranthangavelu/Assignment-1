#include "ros/ros.h"
#include <string>
#include "arithmetic/DataProcess.h"

bool process(arithmetic::DataProcess::Request  &req,
         arithmetic::DataProcess::Response &res)
{
  std::string status;
  if ((int)req.id > 4 )
  {
  switch((int)req.id)
    {
   case 0:
        res.result = req.num1 + req.num2;
        status = "Addition";
        break;
   case 1:
        res.result = req.num1 - req.num2;
	status = "Subtraction";
        break;
   case 2:
        res.result = req.num1 * req.num2;
	status = "Multiplication";
        break;
   case 3:
        res.result = req.num1 / req.num2;
	status = "Divide";
        break;
   case 4 :
        res.result= pow(req.num1, req.num2);
	status = "Give correct identifier (0-4)";     
    }
  
  ROS_INFO("sending back response [%f] after %s",res.result,status.c_str());
  }
   else 
  {
  ROS_ERROR("Enter Identifier value between 0-4");
  res.result = 0.0;
  }
  return true;
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "arithmetic_server_cpp");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("calculate_cpp", process);
  ROS_INFO("Ready for arithmetic operations");
  ros::spin();

  return 0;
}

