#include <Servo.h>

// Create servo objects
Servo rotationServo;
Servo liftServo;
Servo extensionServo;
Servo clawServo;

// Define the pins for the servos
const int rotationServoPin = 3;
const int liftServoPin = 5;
const int extensionServoPin = 6;
const int clawServoPin = 9;

// Variables to store the current positions of the servos
int rotationServoPos = 90;
int liftServoPos = 170;
int extensionServoPos = 0;
int clawServoPos = 0;

void setup() {
  // Attach the servo objects to their respective pins
  rotationServo.attach(rotationServoPin);
  liftServo.attach(liftServoPin);
  extensionServo.attach(extensionServoPin);
  clawServo.attach(clawServoPin);

  // Initialize the servos to their starting positions
  rotationServo.write(rotationServoPos);
  liftServo.write(liftServoPos);
  extensionServo.write(extensionServoPos);
  clawServo.write(clawServoPos);
  delay(5000);
}

void loop() {
  // Example movements
  //rotateArm(60, 120);       // Rotate the arm from 0 to 180 degrees
  //liftArm(60, 170);       // Lift the arm from 0 to 90 degrees
  extendArmBoomerang(0, 100);

}

// Function to rotate the arm
void rotateArm(int startAngle, int endAngle) {
  for (int pos = startAngle; pos <= endAngle; pos++) {
    rotationServo.write(pos);
    rotationServoPos = pos; // Update the position variable
    delay(15);
  }
  for (int pos = endAngle; pos >= startAngle; pos--) {
    rotationServo.write(pos);
    rotationServoPos = pos; // Update the position variable
    delay(15);
  }
}

// Function to lift the arm
void liftArm(int startAngle, int endAngle) {
  for (int pos = startAngle; pos <= endAngle; pos++) {
    liftServo.write(pos);
    liftServoPos = pos; // Update the position variable
    delay(15);
  }
  for (int pos = endAngle; pos >= startAngle; pos--) {
    liftServo.write(pos);
    liftServoPos = pos; // Update the position variable
    delay(15);
  }
}

// Function to extend the arm
void extendArm(int startPosition, int endPosition) {
  if(startPosition < endPosition){
      for (int pos = startPosition; pos <= endPosition; pos++) {
      extensionServo.write(pos);
      extensionServoPos = pos; // Update the position variable
      delay(15);
    }
  }
  else{
    for (int pos = endPosition; pos >= startPosition; pos--) {
      extensionServo.write(pos);
      extensionServoPos = pos; // Update the position variable
      delay(15);
    }
  }
}


void extendArmBoomerang(int startPosition, int endPosition) {
  for (int pos = startPosition; pos <= endPosition; pos++) {
    extensionServo.write(pos);
    extensionServoPos = pos; // Update the position variable
    delay(15);
  }
  for (int pos = endPosition; pos >= startPosition; pos--) {
    extensionServo.write(pos);
    extensionServoPos = pos; // Update the position variable
    delay(15);
  }
}

void openCloseClaw(int startAngle, int endAngle) {
  for (int pos = startAngle; pos <= endAngle; pos++) {
    clawServo.write(pos);
    clawServoPos = pos; // Update the position variable
    delay(15);
  }
  delay(500);
  for (int pos = endAngle; pos >= startAngle; pos--) {
    clawServo.write(pos);
    clawServoPos = pos; // Update the position variable
    delay(2);
  }
}
