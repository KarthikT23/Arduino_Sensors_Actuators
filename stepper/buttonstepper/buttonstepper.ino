#include<Stepper.h>
int stepsPerRevolution=2048;
int motSpeed=5;
int dt=500;

int buttonpin=2;
int dir=1;
int buttonvalnew;
int buttonvalold=1;
Stepper mystepper(stepsPerRevolution, 8,9,10,11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mystepper.setSpeed(motSpeed);
pinMode(buttonpin,INPUT);
digitalWrite(buttonpin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:


buttonvalnew=digitalRead(buttonpin);
if(buttonvalold==1&&buttonvalnew==0){
  dir=dir*(-1);
}
mystepper.step(dir*1);
buttonvalnew=buttonvalold;
}
