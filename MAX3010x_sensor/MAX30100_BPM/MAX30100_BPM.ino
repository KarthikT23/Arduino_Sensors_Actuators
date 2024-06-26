#include "MAX30100.h"
 
MAX30100* pulseOxymeter;
int result; 
void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Pulse oxymeter test!");
 
  pulseOxymeter = new MAX30100();
  pinMode(2, OUTPUT);
 
}
 
void loop() {
  //You have to call update with frequency at least 37Hz. But the closer you call it to 100Hz the better, the filter will work.
  result = pulseOxymeter->update();
  
  if( result.pulseDetected == true )
  {
    Serial.println("BEAT");
    
    Serial.print( "BPM: " );
    Serial.print( result.heartBPM );
  }
}
