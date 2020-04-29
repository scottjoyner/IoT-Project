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
First, download [Mosquitto](https://mosquitto.org/download/) from the website and install it on your host computer. This will be the central hub of your network.
Next move your attention to the python files in the /python/ dir. These files are scripts that will be run in order for other devices to connect to the hub and either subscribe to a service, or send a data packet to potentially change the current status of the service. 



```
a. Environment settings
b. How to run the code
c. How to interpret the results
d. Any sample input and output files
e. Any other information required to run and understand the code
```



## Works Cited
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
