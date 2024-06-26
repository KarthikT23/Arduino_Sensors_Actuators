int ledstate=0;
int ledpin=8;
int buttonpin=12;
int dt=100;
int buttonNew;
int buttonOld=1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
pinMode(buttonpin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
buttonNew=digitalRead(buttonpin);
if(buttonOld==0&&buttonNew==1){
  if(ledstate==0){
    digitalWrite(ledpin,HIGH);
    ledstate=1;
  }
  else {
    digitalWrite(ledpin,LOW);
    ledstate=0;
  }
}
buttonOld=buttonNew;
delay(dt);
}
