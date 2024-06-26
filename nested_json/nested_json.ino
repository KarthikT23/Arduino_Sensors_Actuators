#include <ArduinoJson.h>

// Define a struct to represent person information
struct PersonInfo {
    String name;
    int age;
    String city;
};

// Declare variables
String jsonString;
String jsonString1;
StaticJsonDocument<200> doc1;
const char* DuplicatePerson;
StaticJsonDocument<200> doc;
PersonInfo person;

void setup() {
    Serial.begin(9600);

    // Wait for the serial monitor to open
    while (!Serial) {
        delay(10);
    }
}

void loop() {
    // Check if there's data available on the Serial port
    if (Serial.available() > 0) {
        // Read the data from the Serial port until a newline character is encountered
        jsonString = Serial.readString();
        
        // Parse the JSON string
        DeserializationError error = deserializeJson(doc, jsonString);
        
        // Read values from JSON
        person.name = doc["person"]["name"].as<const char*>();
        person.age = doc["person"]["age"];
        person.city = doc["person"]["city"].as<const char*>();

        // Print the values
        Serial.print("Name: ");
        Serial.println(person.name);
        Serial.print("Age: ");
        Serial.println(person.age);
        Serial.print("City: ");
        Serial.println(person.city);
        
        // Serialize the JSON document into a string
        doc1["DuplicatePerson"]["name"] = person.name;
        doc1["DuplicatePerson"]["age"] = person.age;
        doc1["DuplicatePerson"]["city"] = person.city;
        serializeJson(doc1, jsonString1);
        
        // Print the serialized JSON string
        Serial.println("Serialized JSON:");
        Serial.println(jsonString1);
        
        // Clear variables and JSON document
        jsonString1 = ""; 
        doc.clear();

        delay(1000);
    }
}


