// Import the Arduino Servo library
#include <Servo.h>

// Create a Servo object for each servo
Servo servo1;


// Common servo setup values
int minPulse = 600;   // minimum servo position, us (microseconds)
int maxPulse = 2400;  // maximum servo position, us

// User input for servo and position
int userInput[3];    // raw input from serial buffer, 3 bytes
int startbyte;       // start byte, begin reading input
int servo;           // which servo to pulse?
int pos;             // servo angle 0-180
int i;               // iterator


void setup()
{
  // Attach each Servo object to a digital pin
  servo1.attach(9, minPulse, maxPulse);

  // TO ADD SERVOS:
  //   servo5.attach(YOUR_PIN, minPulse, maxPulse);
  //   etc...


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
      pos = userInput[1];
      // Packet error checking and recovery
      if (pos == 255) {
        servo = 255;
      }

      // Assign new position to appropriate servo
      switch (servo) {
      case 1:
        servo1.write(pos);    // move servo1 to 'pos'
        break;
      }//switch
    }//startbyte ok
  }//serial avail
}//loop
