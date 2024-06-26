int lightpin=A2;
int lightval;
int redpin=3;
int greenpin=8;
void setup() {
  // put your setup code here, to run once:
pinMode(lightpin,INPUT);
pinMode(redpin,OUTPUT);
pinMode(greenpin,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
lightval=analogRead(lightpin);
Serial.println(lightval);
delay(1000);
if(lightval>500){
  digitalWrite(greenpin,HIGH);
  digitalWrite(redpin,LOW);
}
if(lightval<500){
  digitalWrite(greenpin,LOW);
  digitalWrite(redpin,HIGH);
}

}
