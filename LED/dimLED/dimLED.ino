int button1=12;
int button2=8;
int dt=500;
int buttonV1;
int buttonV2;
int ledBright=0;
int ledpin=3;
int buzzpin=2;
void setup() {
  // put your setup code here, to run once:
pinMode(button1,INPUT);
pinMode(button2,INPUT);
pinMode(ledpin,OUTPUT);
pinMode(buzzpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonV1=digitalRead(button1);
buttonV2=digitalRead(button2);
Serial.print("button 1 =");
Serial.print(buttonV1);
Serial.print(",");
Serial.print("button 2 =");
Serial.println(buttonV2);
delay(dt);
if(buttonV1==0){
  ledBright=ledBright+5;
}
if(buttonV2==0){
  ledBright=ledBright-5;
}
Serial.println(ledBright);
if(ledBright>255){
  ledBright=255;
  digitalWrite(buzzpin,HIGH);
  delay(dt);
  digitalWrite(buzzpin,LOW);
  Serial.println("Buzz High");
}
if(ledBright<0){
  ledBright=0;
    digitalWrite(buzzpin,HIGH);
  delay(dt);
  digitalWrite(buzzpin,LOW);
  Serial.println("Buzz Low");
}
analogWrite(ledpin,ledBright);
}
