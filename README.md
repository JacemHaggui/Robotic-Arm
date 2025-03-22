# Robotic Arm Control with Joysticks

This project allows you to control a robotic arm using two joysticks. The system is built with an Arduino and four servo motors to enable precise movements.

## Features
- **Joystick 1 (X-axis):** Controls arm rotation.
- **Joystick 1 (Y-axis):** Controls arm extension (forward/backward movement).
- **Joystick 2 (Y-axis):** Controls arm lift (up/down movement).
- **Joystick 2 Button:** Opens and closes the claw.

## Components Required
- Arduino board
- 4x Servo motors
- 2x Analog joysticks
- Wires and breadboard

## Wiring
| Component        | Arduino Pin |
|-----------------|------------|
| Rotation Servo  | 3          |
| Lift Servo      | 5          |
| Extension Servo | 6          |
| Claw Servo     | 9          |
| Joystick 1 X   | A0         |
| Joystick 1 Y   | A1         |
| Joystick 2 Y   | A2         |
| Joystick 2 Btn | 2          |

## How It Works
1. The joysticks send analog signals to the Arduino, which maps them to servo positions.
2. Moving Joystick 1 left/right rotates the arm.
3. Moving Joystick 1 forward/backward extends or retracts the arm.
4. Moving Joystick 2 up/down lifts or lowers the arm.
5. Pressing the button on Joystick 2 opens or closes the claw.

## Installation & Usage
1. Connect all components as per the wiring diagram.
2. Upload the provided Arduino code.
3. Power the system and use the joysticks to control the robotic arm.

## Code Overview
- Reads joystick values using `analogRead()`.
- Maps values to servo positions.
- Updates servo positions in real-time based on joystick input.
- Uses a button press to toggle the claw's open/close state.

## Future Improvements
- Add speed control for smoother movement.
- Implement wireless joystick control.
- Use inverse kinematics for advanced control.

Feel free to contribute or modify the project to fit your needs!

