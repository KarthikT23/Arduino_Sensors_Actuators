int bluePin=3;
int greenPin=5;
int btime=100;
int gtime=200;
int bblink=4;
int gblink=5;
int j;
void setup() {
  // put your setup code here, to run once:
pinMode(bluePin,OUTPUT);
pinMode(greenPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for(j=1;j<=bblink;j=j+1){
digitalWrite(bluePin,HIGH);
delay(btime);
digitalWrite(bluePin,LOW);
delay(btime);
}
for(j=1;j<=gblink;j=j+1){
digitalWrite(greenPin,HIGH);
delay(gtime);
digitalWrite(greenPin,LOW);
delay(gtime);
}
}
