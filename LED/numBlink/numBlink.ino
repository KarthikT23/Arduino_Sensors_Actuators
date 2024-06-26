int numBlinks;
String msg="how many blinks?:";
int j;
int bt=500;
int bluePin=8;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while(Serial.available()==0){
  
}
numBlinks=Serial.parseInt();
for(j=1;j<=numBlinks;j=j+1){
  digitalWrite(bluePin,HIGH);
  delay(bt);
  digitalWrite(bluePin,LOW);
  delay(bt);
}
}
