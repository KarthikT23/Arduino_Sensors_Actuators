int x=A1;
int y=A2;
int s=2;
int xval;
int yval;
int sval;
int dt=250;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(x,INPUT);
pinMode(y,INPUT);
pinMode(s,INPUT);
digitalWrite(s,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
xval=analogRead(x);
yval=analogRead(y);
sval=digitalRead(s);
delay(dt);
Serial.print("X= ");
Serial.println(xval);
Serial.print("Y= ");
Serial.println(yval);
Serial.print("Switch state= ");
Serial.println(sval);
Serial.println("*****");
}
