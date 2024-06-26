int buzzpin=10;
int buzztime=1000;
int buzztime2=20;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(buzzpin,HIGH);
delay(buzztime2);
digitalWrite(buzzpin,LOW);
delay(buzztime);
}
