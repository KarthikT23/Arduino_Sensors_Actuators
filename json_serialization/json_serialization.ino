#include <ArduinoJson.h>
String jsonString;
// Create a JSON document
StaticJsonDocument<200> doc;
const char* name = "Ram 234";
int age = 250;
const char* city = "Bengaluru 00";

void setup() {
    Serial.begin(9600);

    // Wait for the serial monitor to open
    while (!Serial) {
        delay(10);
    }
}

void loop() {
    // Your code here
    // Populate the JSON document
    doc["name"] = name;
    doc["age"] = age;
    doc["city"] = city;

    // Serialize the JSON document into a string
    //String jsonString;
    serializeJson(doc, jsonString);

    // Print the serialized JSON string
    Serial.println("Serialized JSON:");
    Serial.println(jsonString); 
    jsonString = ""; 
    doc.clear();
    delay(5000);
}
