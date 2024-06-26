#include <ArduinoJson.h>

String jsonString;

// Parse the JSON string
StaticJsonDocument<200> doc;
// Read values from JSON
const char* name;
int age;
const char* city;

void setup() {
    Serial.begin(9600);

    // Wait for the serial monitor to open
    while (!Serial) {
        delay(10);
    }

}

void loop() {
    // Your code here
    
  // Check if there's data available on the Serial port
  if (Serial.available() > 0) {
    String jsonString = Serial.readString();
    DeserializationError error = deserializeJson(doc, jsonString);
    name = doc[String("name")];
    age = doc[String("age")];
    city = doc[String("city")];
    // Print the values
    Serial.print("Name: ");
    Serial.println(name);
    Serial.print("Age: ");
    Serial.println(age);
    Serial.print("City: ");
    Serial.println(city);

    name = "";
    age = 0;
    city = "";

    // Print the values
    Serial.print("Name: ");
    Serial.println(name);
    Serial.print("Age: ");
    Serial.println(age);
    Serial.print("City: ");
    Serial.println(city);
    

    
    delay(1000);
}
}