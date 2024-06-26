int ledpin=8;
int buttonpin=12;
int buttonread;
int dt=100;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
pinMode(buttonpin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
buttonread=digitalRead(buttonpin);
Serial.println(buttonread);
delay(dt);
if(buttonread==0){
  digitalWrite(ledpin,HIGH);
}
if(buttonread==1){
  digitalWrite(ledpin,LOW);
}

}
