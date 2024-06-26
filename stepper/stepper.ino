#include<Stepper.h>
int stepsPerRevolution=2048;
int motSpeed=5;
int dt=500;
Stepper mystepper(stepsPerRevolution, 8,9,10,11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mystepper.setSpeed(motSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
mystepper.step(stepsPerRevolution);
delay(dt);
mystepper.step(-stepsPerRevolution);
delay(dt);
}
