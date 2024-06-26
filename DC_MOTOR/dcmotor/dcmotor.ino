int speedpin=6;
int dir1=5;
int dir2=4;
int mspeed=250;
int dt=250;

void setup() {
  // put your setup code here, to run once:
pinMode(speedpin,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);

Serial.begin(9600);
}

void loop() {
  

  
digitalWrite(dir1,HIGH);
digitalWrite(dir2,LOW);

analogWrite(speedpin,mspeed);


}
