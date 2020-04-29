#!/usr/bin/env python

import serial

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
