#include <Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;

// Motor pins
const int motor1Pin = 9;
const int motor2Pin = 10;
const int motor3Pin = 11;

// Buttons
const int m1Left  = 2;
const int m1Right = 3;

const int m2Left  = 4;
const int m2Right = 5;

const int m3Left  = 6;
const int m3Right = 7;

void setup() {
  motor1.attach(motor1Pin);
  motor2.attach(motor2Pin);
  motor3.attach(motor3Pin);

  // Buttons use the Arduino's built-in pull-up resistors
  pinMode(m1Left, INPUT_PULLUP);
  pinMode(m1Right, INPUT_PULLUP);

  pinMode(m2Left, INPUT_PULLUP);
  pinMode(m2Right, INPUT_PULLUP);

  pinMode(m3Left, INPUT_PULLUP);
  pinMode(m3Right, INPUT_PULLUP);

  // Start stopped
  motor1.write(90);
  motor2.write(90);
  motor3.write(90);
}

void loop() {

  //motor1
  if (digitalRead(m1Left) == LOW) {
    motor1.write(87);       // Slow left
  }
  else if (digitalRead(m1Right) == LOW) {
    motor1.write(93);       // Slow right
  }
  else {
    motor1.write(90);       // Stop
  }

//motor2
  if (digitalRead(m2Left) == LOW) {
    motor2.write(87);
  }
  else if (digitalRead(m2Right) == LOW) {
    motor2.write(93);
  }
  else {
    motor2.write(90);
  }


  //motor3
  if (digitalRead(m3Left) == LOW) {
    motor3.write(87);
  }
  else if (digitalRead(m3Right) == LOW) {
    motor3.write(93);
  }
  else {
    motor3.write(90);
  }
}