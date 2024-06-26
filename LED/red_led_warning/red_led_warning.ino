int myVoltPin=A0;
int readVal;
float V2;
int redPin=9;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
readVal=analogRead(myVoltPin);
V2=(5./1023.)*readVal;
Serial.println(V2);
if(V2>4.0){
  Serial.println("WARNING");
  digitalWrite(redPin,HIGH);
}
if(V2<4.0){
  digitalWrite(redPin,LOW);
}
delay(400);
}
