
#include <SPI.h>              //Library for using SPI Communication 
#include <mcp2515.h>          //Library for using CAN Communication

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

struct can_frame canMsg; 
MCP2515 mcp2515(10);                 // SPI CS Pin 10 
 
void setup() {
  lcd.init();       //initialize i2c LCD
  lcd.backlight();
  delay(1000);
    
  SPI.begin();                       //Begins SPI communication
  
  Serial.begin(9600);                //Begins Serial Communication at 9600 baudrate 
  
  mcp2515.reset();      

  mcp2515.setBitrate(CAN_500KBPS,MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz 
  mcp2515.setNormalMode();                  //Sets CAN at normal mode
}

void loop() 
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) // To receive data (Poll Read)
  {
    if(canMsg.can_id==0x036)
    {
     int x = canMsg.data[0];         
     Serial.println(x);
     lcd.setCursor(1,0);     
      lcd.print("CAN Receiver...");
      lcd.setCursor(2,1);          
      lcd.print("pot value:");
      lcd.print(x);
      delay(200);
     }
    }
   
}                    
