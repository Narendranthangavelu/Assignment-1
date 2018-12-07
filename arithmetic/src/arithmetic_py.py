#!/usr/bin/env python

from arithmetic.srv import *
import rospy


def process(req):
    result =0.0
    if req.id <5 :
       switch = {0:add,1:sub,2:mul,3:div,4:power}
       func = switch.get(int(req.id),'nothing')
       result = func(req)
       rospy.loginfo("sending back response [%f]",result)
    else :
       result = 0.0
       rospy.logerr("Enter Identifier value between 0-4")
    return DataProcessResponse(result)

def add(req):
    return (req.num1 + req.num2)
    
def sub(req):
    return (req.num1 - req.num2)

def mul(req):
    return (req.num1 * req.num2)

def div(req):
    return (req.num1 / req.num2)

def power(req):
    return (req.num1**req.num2)

def start():
    rospy.init_node('arithmetic_server_py')
    s = rospy.Service('calculate_py', DataProcess, process)
    print "Ready for operation"
    rospy.spin()

if __name__ == "__main__":
    start()
