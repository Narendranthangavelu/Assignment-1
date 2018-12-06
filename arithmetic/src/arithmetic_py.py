#!/usr/bin/env python

from arithmetic.srv import *
import rospy
import numpy as np
import sys
def process(req):
    switch = {0:add,1:sub,2:mul,3:div,4:exp}
    func = switch.get(int(req.id),'nothing')
    print "Returning [%s + %s]"%(req.num1, req.num2)
    return DataProcessResponse(func(req))

def add(req):
    return (req.num1 + req.num2)
    
def sub(req):
    return (req.num1 - req.num2)

def mul(req):
    return (req.num1 * req.num2)

def div(req):
    return (req.num1 / req.num2)

def exp(req):
    return (req.num1 + req.num2)

def start():
    rospy.init_node('arithmetic_server_py')
    s = rospy.Service('calculate_py', DataProcess, process)
    print "Ready for operation"
    rospy.spin()

if __name__ == "__main__":
    start()
