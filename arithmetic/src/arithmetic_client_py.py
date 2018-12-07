#!/usr/bin/env python

import sys
import rospy
from arithmetic.srv import *

def client(x, y, i):
    rospy.wait_for_service('calculate_py')
    try:
        operation = rospy.ServiceProxy('calculate_py', DataProcess)
        resp1 = operation(x, y, i)
        return resp1.result
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

#to get identifier
def get_identifier():
	ok = True
	identifier = 0
	while ok and not rospy.is_shutdown():
	   try:
		identifier = int(input("Enter the identifier\n 0.Add \n 1.Sub\n 2.Mul\n 3.Div\n 4.Power\n "))
		if identifier < 5 and identifier >= 0 :
                	ok = False
	   except:
		rospy.logerr("\nEnter only integers between 0-4\n")
	return identifier


#to get operands for operation
def get_operands():
    ok = True
    num1 = 0.0
    num2 = 0.0
    while ok and not rospy.is_shutdown():
       try:
          num1 = float(input("Enter the first operand :  "))
          num2 = float(input("Enter the second operand :  "))
          ok = False
       except:
          rospy.logerr("\nEnter only integers or floating point\n")
    return num1,num2
        

if __name__ == "__main__":


    rospy.init_node('client_node_py')

    while not rospy.is_shutdown():
        num1,num2 = get_operands()
        iden = get_identifier()
        result = client(num1,num2,iden)
        print("The result is {} ".format(result))
  




