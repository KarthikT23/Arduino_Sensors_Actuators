int enA = 9;
int in1 = 8;
int in2 = 7;
const int buttonPin1 = 2;
const int buttonPin2 = 3;
int buttonState1 = 0;
int buttonState2 = 0;
int i = 0;
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

  if(buttonState1 == HIGH){
    motor_clock_50_percent();
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    if(buttonState1 == HIGH){
      motor_clock_100_percent();
    }
  }

  if(buttonState2 == HIGH){
    for(i=0;i<4;i++){
      digitalWrite(in1, LOW);
	    digitalWrite(in2, LOW);
      delay(1000);
    }
    motor_anticlock_50_percent();
    buttonState2 = digitalRead(buttonPin2);
    if(buttonState2 == HIGH){
      motor_anticlock_100_percent();
    }
  }
}

void motor_clock_50_percent(){
  analogWrite(enA, 128);
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
}

void motor_clock_100_percent(){
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
}

void motor_anticlock_50_percent(){
  analogWrite(enA, 128);
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
}

void motor_anticlock_100_percent(){
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
}