# husarion_joy
Husarion RosBot 2.0 Pro auxiliaries e.g. joystick

## Installation. ## 

We assume that you are working on Ubuntu 18.04 and already have installed ROS Melodic. If not, follow the [ROS install guide](http://wiki.ros.org/melodic/Installation/Ubuntu)

Prepare the repository:
```
cd ~
mkdir [your_workspace]
mkdir [your_workspace]/src
cd ~/[your_workspace]/src
catkin_init_workspace
cd ~/[your_workspace]
catkin_make
```
Clone this repository to your workspace:
```
cd ~/[your_workspace]/src
git clone https://github.com/szenergy/husarion_joy.git
```

Build the workspace:
```
cd ~/[your_workspace]
catkin_make
```

Please remember that each time, when you open new terminal window, you will need to load system variables:
```
source ~/[your_workspace]/devel/setup.sh
```

## How to use. ##

Run the following commands below.

In Terminal 1:
```
roscore
```

In Terminal 2:
```
roslaunch husarion_joy joy_teleop.launch
```
