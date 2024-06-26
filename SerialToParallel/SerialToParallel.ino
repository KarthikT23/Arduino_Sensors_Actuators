int latchpin=11;
int clockpin=9;
int datapin=12;
byte LEDs=0xF0;
void setup() {
Serial.begin(9600);
pinMode(latchpin,OUTPUT);
pinMode(datapin,OUTPUT);
pinMode(clockpin,OUTPUT);
}

void loop() {
digitalWrite(latchpin,LOW);
shiftOut(datapin,clockpin,LSBFIRST,LEDs);
digitalWrite(latchpin,HIGH);
}
