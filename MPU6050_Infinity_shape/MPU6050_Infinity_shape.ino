#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

#define ACCEL_THRESHOLD 2000  
#define GYRO_THRESHOLD 2000   
#define MIN_MOVEMENT_COUNT 10 
#define RESET_TIME 1000       

int prevX, prevY; 
int countAccel;  
unsigned long lastMovement = 0; 

enum class State { INITIAL, UPWARD, LOOP, DOWNWARD };
State currentState = State::INITIAL;

void setup() {
  Wire.begin();
  mpu.initialize();
  mpu.setAccelerometerScale(MPU6050_SCALE_2_G); 
  mpu.setGyroScale(MPU6050_SCALE_250DPS); 
  Serial.begin(9600);
}

void loop() {
  int accelX, accelY;
  int gyroX;

  mpu.update();
  accelX = mpu.getAccelerometerX();
  accelY = mpu.getAccelerometerY();
  gyroX = mpu.getGyroX();

  
  switch (currentState) {
    case State::INITIAL:
      if (abs(accelY - prevY) > ACCEL_THRESHOLD) {
        countAccel++;
        if (countAccel >= MIN_MOVEMENT_COUNT && accelY > 0) {
          currentState = State::UPWARD;
          countAccel = 0;
        }
      } else {
        countAccel = 0;
      }
      break;
    case State::UPWARD:
      if (abs(gyroX - prevX) > GYRO_THRESHOLD && gyroX > 0) {
        currentState = State::LOOP;
      } else if (abs(accelY - prevY) < -ACCEL_THRESHOLD) {
        currentState = State::DOWNWARD;
      }
      break;
    case State::LOOP:
      if (abs(gyroX - prevX) > GYRO_THRESHOLD && gyroX < 0) {
        currentState = State::DOWNWARD;
      } else if (millis() - lastMovement > 200) { 
        currentState = State::INITIAL;
      }
      break;
    case State::DOWNWARD:
      if (abs(accelY - prevY) < -ACCEL_THRESHOLD && accelY < 0) {
        countAccel++;
        if (countAccel >= MIN_MOVEMENT_COUNT) {
          currentState = State::INITIAL;
          countAccel = 0;
          Serial.println("Infinity symbol detected!");
        }
      } else {
        countAccel = 0;
      }
      break;
  }

  prevX = accelX;
  prevY = accelY;

  delay(10); 
}
