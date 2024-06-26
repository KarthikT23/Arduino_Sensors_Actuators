int buzzpin=10;
int dt1=2;
int dt2=6;
int j;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
for(j=1;j<=100;j=j+1){
  digitalWrite(buzzpin,HIGH);
  delay(dt1);
  digitalWrite(buzzpin,LOW);
  delay(dt1);
  }
for(j=1;j<=100;j=j+1){
  digitalWrite(buzzpin,HIGH);
  delay(dt2);
  digitalWrite(buzzpin,LOW);
  delay(dt2);
}
}
