#include <ArduinoJson.h>

String jsonString;
String jsonString1;
// Create a JSON document
StaticJsonDocument<200> doc1;
const char* ack;
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
    
    doc1["ack"] = name;
    serializeJson(doc1, jsonString1);

    // Print the serialized JSON string
    Serial.println("Serialized JSON:");
    Serial.println(jsonString1); 
    jsonString1 = ""; 
    doc.clear();

    
    delay(1000);
}
}