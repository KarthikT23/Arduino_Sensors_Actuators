int i = 0;
void setup() 
{
  Serial.begin(9600);
  Serial.println("Sin:,Cos:"); //Legend
  delay(200);
  
}

void loop() 
{
  float ySin = 220*sin((PI/180.0)*i);
  float yCos = 220*cos((PI/180.0)*i);
  Serial.print(ySin);Serial.print(","); //supported delimiter commna, space, tab(\t)
  Serial.println(yCos);
  delay(1); 
  i++;       
}