int pin1=13;
int pin2=12;
int pin3=11;
String color;
String msg="which led?";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pin1,OUTPUT);
pinMode(pin2,OUTPUT);
pinMode(pin3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while(Serial.available()==0){
  
}
color=Serial.readString();
if(color=="pin1"){
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
}
if(color=="pin2"){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,LOW);
}
if(color=="pin3"){
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,HIGH);
}
}
