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

