#include <ArduinoJson.h>

// Define global variables
int volume = 0; // Global variable to store volume
int pv = 0;     // Global variable to store pv
int increment = 4; // Increment value for pv
int i = 0;
int x;
StaticJsonDocument<200> responseDoc;

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

            if (i < increment) {
                x = volume / increment;
                // Clear the response JSON document
                responseDoc.clear();
                // Add values to the response JSON document
                responseDoc["code"] = 200;
                JsonObject msg = responseDoc.createNestedObject("msg");
                msg["st"] = 1;
                msg["pv"] = x * (i + 1);
                // Serialize the response JSON document
                String responseString;
                serializeJson(responseDoc, responseString);
                // Print the response
                Serial.println("Response: " + responseString);
                // Update pv
                pv = x * (i + 1);
                // Delay for 1 second
                delay(1000);
                i++;
            } else {
                // For the last iteration, set pv directly to volume
                pv = volume;
                // Add values to the response JSON document for the last iteration
                responseDoc.clear();
                responseDoc["code"] = 200;
                JsonObject msg = responseDoc.createNestedObject("msg");
                msg["st"] = 1;
                msg["pv"] = pv;
                // Serialize the response JSON document
                String responseString;
                serializeJson(responseDoc, responseString);
                // Print the response for the last iteration
                Serial.println("Response: " + responseString);
                // Print final message
                Serial.println("pv = " + String(pv) + ". Response done");

            }
        }
    }
}

