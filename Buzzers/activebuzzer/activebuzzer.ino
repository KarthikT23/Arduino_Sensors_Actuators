int num;
int buzzpin=8;
int t=2000;
String msg="please input your number:";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buzzpin,OUTPUT);
}

void loop() {
  Serial.println(msg);
  // put your main code here, to run repeatedly:
while(Serial.available()==0){
  
}
num=Serial.parseInt();
if(num>10){
  digitalWrite(buzzpin,HIGH);
  delay(t);
  digitalWrite(buzzpin,LOW);
  
}
}
