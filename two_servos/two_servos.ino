#include <Servo.h>

Servo servo1;  // create servo object to control the first servo
Servo servo2;  // create servo object to control the second servo

int pos = 0;    // variable to store the servo position

void setup() {
  servo1.attach(13);  // attaches the first servo on pin 13 to the servo object
  servo2.attach(7);   // attaches the second servo on pin 7 to the servo object
}

void loop() {
  for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);  // tell the first servo to go to position in variable 'pos'
    servo2.write(pos);  // tell the second servo to go to position in variable 'pos'
    delay(15);          // waits 15ms for the servos to reach the position
  }
  for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo1.write(pos);  // tell the first servo to go to position in variable 'pos'
    servo2.write(pos);  // tell the second servo to go to position in variable 'pos'
    delay(15);          // waits 15ms for the servos to reach the position
  }
}
