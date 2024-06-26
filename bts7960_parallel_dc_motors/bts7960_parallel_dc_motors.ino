// Define pins FOR PARALLEL DC MOTORS
#define LPWM_PIN 12
#define RPWM_PIN 6
#define RELAY_SPIRAL_PIN 11  // Pin connected to the IN pin of the relay module, WHICH IS THE SPIRAL MOTOR
#define SSR_CONV_PIN 5  // Pin connected to the control input of the SSR, WHICH IS THE CONVEYOR BELT MOTOR
void setup() {
  // Set control pins as output
  pinMode(LPWM_PIN, OUTPUT);
  pinMode(RPWM_PIN, OUTPUT);
  pinMode(SSR_CONV_PIN, OUTPUT);
  pinMode(RELAY_SPIRAL_PIN, OUTPUT);
}

void loop() {
  // Move motors forward
  analogWrite(LPWM_PIN, 0); // Set speed (0-255)
  analogWrite(RPWM_PIN, 255);   // Set speed (0-255)
  digitalWrite(RELAY_SPIRAL_PIN, LOW);
  digitalWrite(SSR_CONV_PIN, LOW);
  delay(3000);
  digitalWrite(SSR_CONV_PIN, HIGH);

  //delay(1000); // Run for 5 seconds

  // Move motors backward
  //analogWrite(LPWM_PIN, 0);   // Set speed (0-255)
  //analogWrite(RPWM_PIN, 255); // Set speed (0-255)

  //delay(2000); // Run for 5 seconds

  // Stop motors
  //analogWrite(LPWM_PIN, 0);
  //analogWrite(RPWM_PIN, 0);

  delay(1000); // Stop for 2 seconds
}
