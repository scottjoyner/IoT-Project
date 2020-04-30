# CSC453: IoT-Project
### Scott Joyner (scjoyner)

## Introduction
This repository contains the code I used in order to construct the elements of an automatic lightswitch for lights in my home.
My setup consisted of an Arduino Uno, used to control the servo which activates the lightswitch position, a rasbery pi 4, which enables wireless communication between the primary hub server, and the arduino in order to wait for new signals.

### Materials
1. Rasbery Pi 4
2. Arduino Uno
3. Arduino Ultrasonic Sensor
4. Arduino Servo
5. Iphone SE
6. Desktop PC
7. WiFi router (my home network)

## How To Run
The src code for this project is split up into a few categories. 
* First, download [Mosquitto](https://mosquitto.org/download/) from the website and install it on your host computer. This will be the central hub of your network.
* Next move your attention to the python files. These files are scripts that will be run in order for other devices to connect to the hub and either subscribe to a service, or send a data packet to potentially change the current status of the service. 
* The **command.py** file is self contained as the publisher of the MQTT system I have setup for this project. It uses a number of external dependancies that you will have to install with pip. If you run into an issue with AppKit, I was running this on mac os, and ran into a number of problems obtaining all the dependancies. ```pip3 install -U PyObjC``` I had to install the Objective C package to get it to run. This file will allow you to utilize voice commands to turn on, and off the lightswitch that I have implemented.
* The **pi_controller.py** file is what I ran on the rasberry pi. It was the subscriber of the MQTT system, which was responsible for sending actions to the arduino, which moved the servo that is attached to the lightswitch.
The way I settup this system it will be easy for me to expand upon it, now that a. lot of the ground work has been done. I am looking forward to being able to make a nunmber of additions to this system with the goal of enabling voice activated commands for a number of tasks around my house. 
The **arduino_controller.ino** file contains the other end of the serial connection. 

The pi_controller would send small, 3 byte, packets of data to the arduino board in order to register the shift from off to on. The angles that the arduinos servo uses was chosesn based on trial and error, after mounting the servo to the wall in a rediculus fashion. The result was I am able to use the voice commands "lights on" and "lights off" in order to control the light in my closet. I use it a lot as a night time light source and it can be frustrating to get out of bed before I go to sleep, and that was the original inspiration for the project, as I have been home quarintined for quite some time. 

 * **Notes:** I had a lot of trouble with making sure that I could identify the correct port for the serial communications betweeb the Pi and Arduino, make sure to enable connections for the serial port in the system preferances menu > Interfaces in order to utilize the ports. Then identify that the current port that is being used by the arduino and set it in the source code. It was changing every time I unplugged it and eventually made it a CLI, but did not end up pushing that version to this repo.


```
a. Environment settings
b. How to run the code
c. How to interpret the results
d. Any sample input and output files
e. Any other information required to run and understand the code
```



## Works Cited
For a lot of command.py :geeksforgeeks
```
################################################
# Module:   servo.py
# Created:  2 April 2008
# Author:   Brian D. Wendt
#   http://principialabs.com/
# Version:  0.3
# License:  GPLv3
#   http://www.fsf.org/licensing/
'''
Provides a serial connection abstraction layer
for use with Arduino "MultipleSerialServoControl" sketch.
'''
################################################
```
```
/*
 * ------------------------------
 *   MultipleSerialServoControl
 * ------------------------------
 *
 * Uses the Arduino Serial library
 *  (http://arduino.cc/en/Reference/Serial)
 * and the Arduino Servo library
 *  (http://arduino.cc/en/Reference/Servo)
 * to control multiple servos from a PC using a USB cable.
 *
 * Dependencies:
 *   Arduino 0017 or higher
 *     (http://www.arduino.cc/en/Main/Software)
 *   Python servo.py module
 *     (http://principialabs.com/arduino-python-4-axis-servo-control/)
 *
 * Created:  23 December 2009
 * Author:   Brian D. Wendt
 *   (http://principialabs.com/)
 * Version:  1.1
 * License:  GPLv3
 *   (http://www.fsf.org/licensing/)
 *
 */
```
