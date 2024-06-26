int lightpin=A2;
int lightval;
void setup() {
  // put your setup code here, to run once:
pinMode(lightpin,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
lightval=analogRead(lightpin);
Serial.println(lightval);
delay(1000);
}
