// Import the Arduino Servo library
#include <Servo.h>

// Create a Servo object for each servo
Servo lightswitch;

// Common servo setup values
int minPulse = 600;   // minimum servo position, us (microseconds)
int maxPulse = 2400;  // maximum servo position, us

// User input for servo and position
int userInput[3];    // raw input from serial buffer, 3 bytes
int startbyte;       // start byte, begin reading input
int servo;           // which servo to pulse? Gives the ability to control multiple light switches in the same room using a single arduino per room.
int pos;             // servo angle 0-180
int i;               // iterator


void setup()
{
  // Attach each Servo object to a digital pin
  servo1.attach(9, minPulse, maxPulse);

  // Open the serial connection, 9600 baud
  Serial.begin(9600);
}

void loop()
{
  // Wait for serial input (min 3 bytes in buffer)
  if (Serial.available() > 2) {
    // Read the first byte
    startbyte = Serial.read();
    // If it's really the startbyte (255) ...
    if (startbyte == 255) {
      // ... then get the next two bytes
      for (i=0;i<2;i++) {
        userInput[i] = Serial.read();
      }
      // First byte = servo to move?
      servo = userInput[0];
      // Second byte = which position?
      pos = userInput[1]; // Unused for this case
      // Packet error checking and recovery
      if (pos == 255) {
        servo = 255;
      }
      //In the case of using multiple servos, utilizing a switch statement would be effective; however, in the case of only one servo, it is unececary.
      lightswitch.write(pos);    // move servo1 to 'pos'

      if (pos<10 || pos>170)
      {
        pinState=HIGH;
      }
      else
      {
        pinState=LOW;
      }
    }//startbyte ok
  }//serial avail
}//loop
