int potval;
int buzzpin=10;
int dt=2000;
int potPin=A1;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzpin,OUTPUT);
pinMode(potPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
potval=analogRead(potPin);
Serial.println(potval);
while(potval>400){
  digitalWrite(buzzpin,HIGH);
  potval=analogRead(potPin);
  Serial.println(potval);
}
digitalWrite(buzzpin,LOW);
}
  
