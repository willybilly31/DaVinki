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

// Speed
const int FAST = 85;
const int SLOW = 95;
const int STOP = 90;

// Current servo speeds
int motor1Speed = STOP;
int motor2Speed = STOP;
int motor3Speed = STOP;

void setup() {

  motor1.attach(motor1Pin);
  motor2.attach(motor2Pin);
  motor3.attach(motor3Pin);

  pinMode(m1Left, INPUT_PULLUP);
  pinMode(m1Right, INPUT_PULLUP);

  pinMode(m2Left, INPUT_PULLUP);
  pinMode(m2Right, INPUT_PULLUP);

  pinMode(m3Left, INPUT_PULLUP);
  pinMode(m3Right, INPUT_PULLUP);

  motor1.write(STOP);
  motor2.write(STOP);
  motor3.write(STOP);
}

void loop() {

  // MOTOR 1

  if (digitalRead(m1Left) == LOW) {
    motor1Speed = FAST;
  }
  else if (digitalRead(m1Right) == LOW) {
    motor1Speed = SLOW;
  }
  else {
    // Gradually return to stop
    if (motor1Speed < STOP) motor1Speed++;
    if (motor1Speed > STOP) motor1Speed--;
  }

  motor1.write(motor1Speed);


  // MOTOR 2

  if (digitalRead(m2Left) == LOW) {
    motor2Speed = FAST;
  }
  else if (digitalRead(m2Right) == LOW) {
    motor2Speed = SLOW;
  }
  else {
    if (motor2Speed < STOP) motor2Speed++;
    if (motor2Speed > STOP) motor2Speed--;
  }

  motor2.write(motor2Speed);


  // MOTOR 3

  if (digitalRead(m3Left) == LOW) {
    motor3Speed = FAST;
  }
  else if (digitalRead(m3Right) == LOW) {
    motor3Speed = SLOW;
  }
  else {
    if (motor3Speed < STOP) motor3Speed++;
    if (motor3Speed > STOP) motor3Speed--;
  }

  motor3.write(motor3Speed);

  delay(30);
}