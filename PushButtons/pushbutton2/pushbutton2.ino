int buttonpin=6;
int buttonval;
int dt=1000;
void setup() {
  // put your setup code here, to run once:
pinMode(buttonpin,INPUT);
digitalWrite(buttonpin,HIGH);
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
buttonval=digitalRead(buttonpin);
Serial.print("button is: ");
Serial.println(buttonval);
delay(dt);
}
