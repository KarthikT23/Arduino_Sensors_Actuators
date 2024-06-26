String Name;
String msg="what is your name? ";
String msg2="hello";
String msg3="welcome to arduino";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while(Serial.available()==0){
  
}
Name=Serial.readString();
Serial.print(msg2);
Serial.print(Name);
Serial.println(msg3);
}
