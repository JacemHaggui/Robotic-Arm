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

// Define joystick pins
const int joystick1X = A0; // Joystick 1 controls rotation
const int joystick1Y = A1; // Joystick 1 controls extension (forward-backward)
const int joystick2Y = A2; // Joystick 2 controls lift (up-down)
const int joystick2Button = 2; // Joystick button for claw

// Variables to store the current positions of the servos
int rotationServoPos = 90; // Default rotation position
int liftServoPos = 170; // Default lift position
int extensionServoPos = 0; // Default extension position
int clawServoPos = 0; // Default claw position

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
  
  pinMode(joystick2Button, INPUT_PULLUP); // Joystick button setup
}

void loop() {
  // Read joystick values
  int rotationInput = analogRead(joystick1X);
  int extensionInput = analogRead(joystick1Y);
  int liftInput = analogRead(joystick2Y);
  int clawButton = digitalRead(joystick2Button);

  // Map joystick values to servo positions
  rotationServoPos = map(rotationInput, 0, 1023, 0, 180);
  extensionServoPos = map(extensionInput, 0, 1023, 0, 100);
  liftServoPos = map(liftInput, 0, 1023, 90, 170);
  
  // Update servos
  rotationServo.write(rotationServoPos);
  extensionServo.write(extensionServoPos);
  liftServo.write(liftServoPos);
  
  // Control claw with button press
  if (clawButton == LOW) {
    clawServo.write(90); // Close claw
  } else {
    clawServo.write(0); // Open claw
  }

  delay(15); // Small delay for stability
}
