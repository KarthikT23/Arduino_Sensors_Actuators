/* TEMP
req: {"action":"temp","params":{"drum":80,"cooler":4}}
res: #{"code":200,"msg":{"drum":{"md":1,"pv":62,"sv":80},"cool":{"md":"on","pv":12,"sv":4}}}$ */

#include <ArduinoJson.h>

// Define global variables
int drumPV = 0;   // Global variable to store drum PV
int coolPV = 28;   // Global variable to store cooler PV, starts from room temperature
int coolSV = 4;   // Global variable to store cooler SV
int increment = 3; // Increment value for PV
int i = 0;
int x, x2;
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

        // Check if the action is "temp"
        if (doc["action"] == "temp") {
            drumPV = doc["params"]["drum"];
            coolSV = doc["params"]["cooler"];

            if (i < increment) {
                x = drumPV / increment;
                //Serial.println(x);
                x2 = (coolPV - coolSV) / increment; // Calculate the decrement for cooler PV per iteration
                //Serial.println(x2);
                // Clear the response JSON document
                responseDoc.clear();
                // Add values to the response JSON document
                responseDoc["code"] = 200;
                JsonObject msg = responseDoc.createNestedObject("msg");
                JsonObject drum = msg.createNestedObject("drum");
                drum["md"] = 1;
                drum["pv"] = x * (i + 1);
                drum["sv"] = drumPV;
                JsonObject cool = msg.createNestedObject("cool");
                cool["md"] = "on";
                cool["pv"] = coolPV - (x2 * (i + 1)); // Decrementing cooler PV
                cool["sv"] = coolSV;
                // Serialize the response JSON document
                String responseString;
                serializeJson(responseDoc, responseString);
                // Print the response
                Serial.println("Response: " + responseString);
                // Update PVs
                drumPV = x * (i + 1);
                coolPV -= (x2 * (i + 1)); // Decrementing cooler PV
                // Delay for 1 second
                delay(1000);
                i++;
            } else {
                // For the last iteration, set PVs directly to their final values
                drumPV = doc["params"]["drum"];
                coolPV = coolSV;
                // Add values to the response JSON document for the last iteration
                responseDoc.clear();
                responseDoc["code"] = 200;
                JsonObject msg = responseDoc.createNestedObject("msg");
                JsonObject drum = msg.createNestedObject("drum");
                drum["md"] = 1;
                drum["pv"] = drumPV;
                drum["sv"] = drumPV;
                JsonObject cool = msg.createNestedObject("cool");
                cool["md"] = "on";
                cool["pv"] = coolPV;
                cool["sv"] = coolSV;
                // Serialize the response JSON document
                String responseString;
                serializeJson(responseDoc, responseString);
                // Print the response for the last iteration
                Serial.println("Response: " + responseString);
                // Print final message
                Serial.println("drumpv = " + String(drumPV) + ", coolpv = " + String(coolPV) + ". Response done");
            }
        }
    }
}
