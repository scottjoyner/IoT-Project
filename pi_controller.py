#!/usr/bin/env python

import serial
import paho.mqtt.client as MQTT #import the client

# Function to process recieved message
def process_message(client, userdata, message):
    print("message received " ,str(message.payload.decode("utf-8")))
    print("message topic=",message.topic)
    print("message qos=",message.qos)
    print("message retain flag=",message.retain)
    msg = str(message.payload.decode("utf-8"))
    if "off" in msg:
        ser.write(chr(255))  // This char lets the arduino know that a message starts here
        ser.write(chr(1))    // We are referanceing servo 1, we only have one servo in this case, as I did not have more servos on hand
        ser.write(chr(0))    // 0 Degree angle for the servo signifies the off position
    if "on" in msg:
        ser.write(chr(255))  // This char lets the arduino know that a message starts here
        ser.write(chr(1))    // We are referanceing servo 1, we only have one servo in this case, as I did not have more servos on hand
        ser.write(chr(60))   // 60 Degree angle for the servo signifies the on position.


# Create client
client = mqtt.Client(client_id="closet-light")

# Assign callback function
client.on_message = process_message

# Connect to broker
client.connect(broker_address,1883,60)

# Subscriber to topic
client.subscribe("house/closet-light")

# Run loop
client.loop_forever()
# Assign Arduino's serial port address
usbport = '/dev/ttyACM1'

# Set up serial baud rate
ser = serial.Serial(usbport, 9600, timeout=1)

        
def move(servo, angle):
    '''Moves the specified servo to the supplied angle.

    Arguments:
        servo
          the servo number to command, an integer from 1-4
        angle
          the desired servo angle, an integer from 0 to 180

    (e.g.) >>> servo.move(2, 90)
           ... # "move servo #2 to 90 degrees"'''

    if (0 <= angle <= 180):
        ser.write(chr(255))
        ser.write(chr(servo))
        ser.write(chr(angle))
    else:
        print("Servo angle must be an integer between 0 and 180.\n")


def init():
    move(1,0)


#init()
