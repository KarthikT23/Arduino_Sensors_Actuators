#include <ArduinoJson.h>

// Define global variables
int volume = 0; // Global variable to store volume
int pv = 0;     // Global variable to store pv
int increment = 4; // Increment value for pv
bool responseDone = false; // Flag to indicate if response is done
int i = 0;
int x;
String response;

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        delay(10);
    }
}

void loop() {
    // Check if there's data available on the Serial port
    if (Serial.available() > 0) {
        String jsonString = Serial.readStringUntil('\n'); // Read data until newline character
        
        // Print the received request
        Serial.println("Received request: " + jsonString);

        // Parse the received JSON
        StaticJsonDocument<200> doc;
        DeserializationError error = deserializeJson(doc, jsonString);
        
        // Check for parsing errors
        if (error) {
            Serial.print("Parsing failed: ");
            Serial.println(error.c_str());
            return;
        }

        // Check if the action is "fill"
        if (doc["action"] == "fill") {
            volume = doc["params"]["volume"];
            if (pv == volume){
            // Print the final message when pv reaches volume
              Serial.println("pv = " + String(volume) + ". Response done");
        }
        else {
            
            DeserializationError error = deserializeJson(doc, jsonString);
                x = volume/increment;
                // Generate response message
                response = "#{\"code\":200,\"msg\":{\"st\":1,\"pv\":" + String(x*(i+1)) + "}}$";
                i++;
                // Print the response
                Serial.println("Response: " + response);

                // Delay for 1 second
                delay(1000);
            }

    }
}
}

