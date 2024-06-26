
int greenPin=9;
int bright=7;
void setup() {
  // put your setup code here, to run once:
pinMode(greenPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(greenPin,bright);
}
