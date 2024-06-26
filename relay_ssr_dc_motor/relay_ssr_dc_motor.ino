// Define pins
#define RELAY_SPIRAL_PIN 11  // Pin connected to the IN pin of the relay module, WHICH IS THE SPIRAL MOTOR
#define SSR_CONV_PIN 5  // Pin connected to the control input of the SSR, WHICH IS THE CONVEYOR BELT MOTOR
#define LPWM_PIN 12
void setup() {
  // Set control pins as output
  pinMode(RELAY_SPIRAL_PIN, OUTPUT);
  pinMode(SSR_CONV_PIN, OUTPUT);

  // Initialize the motors to be off
  digitalWrite(RELAY_SPIRAL_PIN, LOW);
  digitalWrite(SSR_CONV_PIN, LOW);
   digitalWrite(RELAY_SPIRAL_PIN, HIGH);
}

void loop() {
  // Turn on the first motor via relay module
  digitalWrite(SSR_CONV_PIN, HIGH); // Relay activated, motor 1 runs
  //elay(1000); // Run for 5 seconds

  // Turn off the first motor
  digitalWrite(SSR_CONV_PIN, LOW); // Relay deactivated, motor 1 stops
  //delay(1000); // Stop for 2 seconds

  // Turn on the second motor via SSR
  //digitalWrite(SSR_PIN, HIGH); // SSR activated, motor 2 runs
  //delay(5000); // Run for 5 seconds

  // Turn off the second motor
  //digitalWrite(SSR_PIN, LOW); // SSR deactivated, motor 2 stops
  //delay(2000); // Stop for 2 seconds
}
