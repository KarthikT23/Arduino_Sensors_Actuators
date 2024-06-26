int lightpin=A1;
int buzzpin=8;
int dt;
int lightval;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzpin,INPUT);
pinMode(lightpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
lightval=analogRead(lightpin);
dt=(9./550.)*lightval-(9.*200./550.)+1;
Serial.println(dt);
Serial.println(lightval);
digitalWrite(buzzpin,HIGH);
delay(dt);
digitalWrite(buzzpin,LOW);
delay(dt);
}
