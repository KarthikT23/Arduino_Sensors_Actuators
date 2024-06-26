int enA = 9;
int in1 = 8;
int in2 = 7;
const int buttonPin1 = 2;
const int buttonPin2 = 3;
int buttonState1 = 0;
int buttonState2 = 0;
unsigned long startTime; 
int motorSpeedState1 = 0; 
int motorSpeedState2 = 0; 

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH) {
    if (motorSpeedState1 == 0) {
      motor_clock_50_percent();
      motorSpeedState1 = 1;
    } else if (motorSpeedState1 == 1) {
      motor_clock_100_percent();
      motorSpeedState1 = 0;
    }
    delay(50); // Debounce delay
  }

  if (buttonState2 == HIGH) {
    if (motorSpeedState2 == 0) {
      motor_anticlock_50_percent();
      motorSpeedState2 = 1;
    } else if (motorSpeedState2 == 1) {
      motor_anticlock_100_percent();
      motorSpeedState2 = 0;
    }
    delay(50); // Debounce delay
  }
}

void motor_clock_50_percent() {
  analogWrite(enA, 128);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void motor_clock_100_percent() {
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void motor_anticlock_50_percent() {
  analogWrite(enA, 128);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void motor_anticlock_100_percent() {
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
