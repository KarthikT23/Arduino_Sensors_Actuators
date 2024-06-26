#include<Servo.h>
int servopin=9;
int servopos=78;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("what angle for the servo? ");
while(Serial.available()==0){
  
}
servopos=Serial.parseInt();
myservo.write(servopos);
}
