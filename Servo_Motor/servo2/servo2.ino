#include<Servo.h>
int lightval;
int servopin=9;
int lightpin=A3;
int dt=250;
int servopos;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(lightpin,INPUT);
myservo.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
lightval=analogRead(lightpin);
Serial.println(lightval);
Serial.println(servopos);
delay(dt);
servopos=(-20./63.)*lightval+20.*780./63.;
myservo.write(servopos);
}
