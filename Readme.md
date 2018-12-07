# Assignment-1

Project contains two packages
1. File_writer - This package writes the published text into the text file in the defined path. 
2. Arithmetic operations - This package creates a server to perform basic mathematical operations.

## Getting Started

Clone this project in your catkin workspace under the **src** folder.  
      ```
      git clone https://github.com/Narendranthangavelu/Assignment-1.git 
      ```  
      Build the project using the following command before that make sure you are in catkin workspace directory.  
      ```
      catkin_make
      ```   
### 1. Text File Writer
  * It was written in both c++ and python language. Path to store the text file can be given as a argument while launching.
    By default text files will be stored under the packgage (file_writer) directory.  
    #### C++ code can be launched using the folowing command.
    ```
    roslaunch file_writer file_writer_cpp.launch path:= "specify Path within quotes"  eg: "/home/naren/Music"
    ```
    #### python code can be launched using the folowing command.
    ```
    roslaunch file_writer file_writer_py.launch
    ```
   
    #### python and c++ code can be launched using the folowing command.
    ```
    roslaunch file_writer file_writer.launch
    ```
    Text can be added to the file by publishing a string value to the topic.
    ```
    rostopic pub /talk1_py std_msgs/String "data: 'this canbe applied to both cpp and python program'" 
    ```
    |Language   |Topics |
    |-----------|-------|
    |c++ topics | /talk1_cpp , /talk2_cpp |
    |python topics | /talk1_py , /talk2_py |

### 2. Arithmetic Operations
  * This package creates a service for basic mathematical operations. Service request consist of two operands and one identifier.
    Identifier will specify the artihmetic operation as mentioned below,  
    
    |Identifier  | operation|
    |-------|----------|
    |0   | Addition   |
    |1 | Subtraction  |
    |2 | Multiplication|
    |3 | Divide    |
    |4 | Power      |
    
    To launch the service created on c++.
    ```
    roslaunch arithmetic arithmetic_cpp.launch
    ```
    To launch the service created on python
    ```
    roslaunch arithmetic arithmetic_py.launch
    ```
    Services created are **calculate_cpp** and **calculate_py** for c++ and python respectively.  
    #### eg: 
    ```
    rosservice call /calculate_cpp "num1: 5.0                 
    num2: 2.0
    id: 1" 

    ```
    ```
    rosservice call /calculate_py "num1: 5.0                 
    num2: 2.0
    id: 1" 

    ```
    
    
    




