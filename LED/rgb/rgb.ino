int red=7;
int blue=6;
int green=5;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
 digitalWrite(red,HIGH);
 delay(1000);
 digitalWrite(red,LOW);

  digitalWrite(blue,HIGH);
 delay(1000);
 digitalWrite(blue,LOW);


  digitalWrite(green,HIGH);
 delay(1000);
 digitalWrite(green,LOW);
 delay(1000);

}
