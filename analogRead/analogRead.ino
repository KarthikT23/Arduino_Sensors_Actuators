int readPin=A0;
float V2=0;
int readVal;
int time=600;
void setup() {
  // put your setup code here, to run once:
pinMode(readPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readVal=analogRead(readPin);
V2=(3.3/523.)*readVal;
Serial.println(V2);
delay(time);
}
