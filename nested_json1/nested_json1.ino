#include <ArduinoJson.h>

// Define a struct to represent person information
struct PersonInfo {
    String name;
    int age;
    String city;
    String email;
    String phoneNumber;
    String location;
};

// Declare variables
String jsonString;
String jsonString1;
StaticJsonDocument<400> doc1; // Increased capacity to accommodate larger JSON
const char* DuplicatePerson;
StaticJsonDocument<400> doc; // Increased capacity to accommodate larger JSON
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
        person.name = doc["person"]["info"]["name"].as<const char*>();
        person.age = doc["person"]["info"]["age"];
        person.city = doc["person"]["info"]["city"].as<const char*>();
        person.email = doc["person"]["info"]["email"].as<const char*>(); // Added email
        person.phoneNumber = doc["person"]["info"]["phoneNumber"].as<const char*>(); // Added phone number
        person.location = doc["person"]["info"]["location"].as<const char*>(); // Added location

        // Print the values
        Serial.print("Name: ");
        Serial.println(person.name);
        Serial.print("Age: ");
        Serial.println(person.age);
        Serial.print("City: ");
        Serial.println(person.city);
        Serial.print("Email: ");
        Serial.println(person.email);
        Serial.print("Phone Number: ");
        Serial.println(person.phoneNumber);
        Serial.print("Location: ");
        Serial.println(person.location);
        
        // Serialize the JSON document into a string
        doc1["DuplicatePerson"]["name"] = person.name;
        doc1["DuplicatePerson"]["age"] = person.age;
        doc1["DuplicatePerson"]["city"] = person.city;
        doc1["DuplicatePerson"]["email"] = person.email;
        doc1["DuplicatePerson"]["phoneNumber"] = person.phoneNumber;
        doc1["DuplicatePerson"]["location"] = person.location;
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
