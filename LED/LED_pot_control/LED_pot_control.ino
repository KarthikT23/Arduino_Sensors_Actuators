int potPin=A0;
int gPin=9;
int potVal;
float ledVal;
int dtime=600;
void setup() {
  // put your setup code here, to run once:
pinMode(potPin,INPUT);
pinMode(gPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
potVal=analogRead(potPin);
ledVal=(255./1023.)*potPin;
analogWrite(gPin,ledVal);
Serial.println(ledVal);

}
