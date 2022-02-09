# husarion_joy
Husarion RosBot 2.0 Pro auxiliaries e.g. joystick

## Installation

We assume that you are working on Ubuntu 18.04 and already have installed ROS Melodic. If not, follow the [ROS install guide](http://wiki.ros.org/melodic/Installation/Ubuntu)

We recommend to use [catkin tools](https://catkin-tools.readthedocs.io/en/latest/installing.html) instead of catkin_make.

Prepare the repository:
```
cd ~
mkdir [your_workspace]
mkdir [your_workspace]/src
cd ~/[your_workspace]/src
catkin init
```
(with catkin_make the commands would be `catkin_init_workspace` and `catkin_make`)

Clone this repository to your workspace:
```
cd ~/[your_workspace]/src
git clone https://github.com/szenergy/husarion_joy
```

Build the workspace:
```
cd ~/[your_workspace]
catkin build husarion_joy
```
(with catkin_make the command would be `catkin_make` but it builds the whole workspace)

Please remember that each time, when you open new terminal window, you will need to load system variables:
```
source ~/[your_workspace]/devel/setup.sh
```
Or put this command into your `~/.bashrc`-

## How to use

Run the following commands below.

In Terminal 1:
```
roscore
```

In Terminal 2:
```
roslaunch husarion_joy joy_teleop.launch
```

## Dependencies

- `ROS`
- `rosbot_ekf`