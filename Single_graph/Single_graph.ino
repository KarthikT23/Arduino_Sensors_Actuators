int i = 0;
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  float y = 220*sin((PI/180.0)*i);
  i++;
  Serial.println(y);
  delay(1);        
}