//COMMON ANODE RGB LED, DO REVERSE
//LOW IS HIGH, AND HIGH IS LOW
//SUBTRACT REQUIRED RGB DECIMAL CODE FROM 255 TO GET REQUIRED COLOR
int redPin=9;
int greenPin=10;
int bluePin=11;
int dt=500;
String color;
String msg="what color do you want?";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while(Serial.available()==0){
  
}
color=Serial.readString();
if(color=="red"){
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,HIGH);
  digitalWrite(bluePin,HIGH);
}
if(color=="green"){
  digitalWrite(redPin,HIGH);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,HIGH);
}
if(color=="blue"){
  digitalWrite(redPin,HIGH);
  digitalWrite(greenPin,HIGH);
  digitalWrite(bluePin,LOW);
}
if(color=="off"){
  digitalWrite(redPin,HIGH);
  digitalWrite(greenPin,HIGH);
  digitalWrite(bluePin,HIGH);
}
if(color=="purple"){
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,HIGH);
  digitalWrite(bluePin,LOW);
}
if(color=="yellow"){
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,HIGH);
}
if(color=="cyan"||"aqua"){
  digitalWrite(redPin,HIGH);
  digitalWrite(greenPin,LOW);
  digitalWrite(bluePin,LOW);
}
if(color=="magenta"){
  analogWrite(redPin,0);
  analogWrite(greenPin,255);
  analogWrite(bluePin,0);
}
if(color=="silver"){
  analogWrite(redPin,63);
  analogWrite(greenPin,63);
  analogWrite(bluePin,63);
}
if(color=="gray"){
  analogWrite(redPin,127);
  analogWrite(greenPin,127);
  analogWrite(bluePin,127);
}
if(color=="maroon"){
  analogWrite(redPin,127);
  analogWrite(greenPin,255);
  analogWrite(bluePin,255);
}
if(color=="navy"){
  analogWrite(redPin,255);
  analogWrite(greenPin,255);
  analogWrite(bluePin,127);
}
if(color=="orange"){
  analogWrite(redPin,0);
  analogWrite(greenPin,115);
  analogWrite(bluePin,255);
}
if(color=="skyblue"){
  analogWrite(redPin,120);
  analogWrite(greenPin,49);
  analogWrite(bluePin,20);
}
if(color=="pink"){
  analogWrite(redPin,0);
  analogWrite(greenPin,150);
  analogWrite(bluePin,75);
}
if(color=="brown"){
  analogWrite(redPin,95);
  analogWrite(greenPin,173);
  analogWrite(bluePin,210);
}
}
