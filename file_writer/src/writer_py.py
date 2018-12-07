#!/usr/bin/env python
import rospy
from std_msgs.msg import String
import sys

def callback1(data,path):
    rospy.loginfo(" %s is appended to %s/text1_py.txt",data.data,path)
    f1 = open(path + "/text1_py.txt","a")
    f1.write(data.data+'\n')
    f1.close()
    return
def callback2(data,path):
    rospy.loginfo(" %s is appended to %s/text2_py.txt",data.data,path)
    f2 = open(path + "/text2_py.txt","a")
    f2.write(data.data+'\n')
    f2.close()
    return
    
def write_string_to_file(path):

    
    rospy.init_node('text_writer_py', anonymous=True)

    rospy.Subscriber("talk1_py", String, callback1,(path))
    rospy.Subscriber("talk2_py", String, callback2,(path))
 
    rospy.spin()

if __name__ == '__main__':
    path = sys.argv[1]

    # create a new file 
    f1= open(path + "/text1_py.txt","w+")
    f1.close()
    f2= open(path + "/text2_py.txt","w+")
    f2.close()


    write_string_to_file(path)
