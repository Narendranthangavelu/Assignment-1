#include "ros/ros.h"
#include "arithmetic/DataProcess.h"
using namespace std;

struct operand{ float n1; float n2;};

/*to get operands for operation*/
operand get_operands()
{
  bool ok = true;
  float num1 = 0.0;
  float num2 = 0.0;
  operand values ;
  while (ok and ros::ok())
  {  
     cout << "\nEnter the first operand : ";
     cin >> num1;
     cout << "Enter the second operand : ";
     cin >> num2;
     values.n1 = (float)(num1);
     values.n2 = (float)(num2);
     /* avoid errors due to characters in input stream */
     if (cin.fail()) 
       {
        cin.clear();
        cin.ignore(512, '\n');
        ROS_ERROR("Enter only integers");
        continue;
       }
     ok = false;
  }
  return values;
}

/*to get identifier*/
int get_identifier()
{
  bool ok = true;
  int id = 0;
  while (ok and ros::ok())
  {
     cout <<"Enter the identifier\n" << "0.Add\n" << "1.Sub\n" << "2.Mul\n" << "3.Div\n" << "4.Power\n" ;
     cin >> id; 
     /* avoid errors due to characters in input stream */       
     if (cin.fail()) 
       {cin.clear();
        cin.ignore(512, '\n');
        ROS_ERROR("Enter only integers");
        continue;
       }         
     if (id >= 0 and id < 5)
       {ok = false;}
     else {ROS_ERROR("Enter correct values");}
  }
  return id ;
}



int main(int argc, char **argv)
{
  /*intializing node and client*/
  ros::init(argc, argv, "client_node_cpp");
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<arithmetic::DataProcess>("calculate_cpp");
  arithmetic::DataProcess srv;
  
  float num1, num2;
  operand values ;
  int id ;
  /*looping till interupts*/
  while (ros::ok())
  {
   try 
    {values = get_operands();
  
     id = get_identifier();
     srv.request.num1 = values.n1;
     srv.request.num2 = values.n2;
     srv.request.id = id;
     /*calling the service */
     if (client.call(srv))
      {cout << "\nThe result is " << srv.response.result;}
     else
      {ROS_ERROR("Failed to call service add_two_ints");
      return 1;}
    }
    catch (int x){cout <<"error";}
  }
  return 0;
}
