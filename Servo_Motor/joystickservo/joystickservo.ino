#include<Servo.h>
int x=A1;
Servo myservo;
int y=A2;
int s=2;
int xval;
int yval;
int sval;
int dt=250;
int servopin=3;
int servovalx;
int buzzpin=7;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(x,INPUT);
pinMode(y,INPUT);
pinMode(s,INPUT);
digitalWrite(s,HIGH);
pinMode(servopin,OUTPUT);
pinMode(buzzpin,OUTPUT);
myservo.attach(x);
}

void loop() {
  // put your main code here, to run repeatedly:
xval=analogRead(x);
servovalx=(180./1023.)*xval;
yval=analogRead(y);
sval=digitalRead(s);
myservo.write(servovalx);
delay(dt);
Serial.print("X= ");
Serial.println(xval);
Serial.print("Y= ");
Serial.println(yval);
Serial.print("Switch state= ");
Serial.println(sval);
Serial.println("*****");
if(sval==0){
  digitalWrite(buzzpin,HIGH);
}
else{
  digitalWrite(buzzpin,LOW);
}
}
