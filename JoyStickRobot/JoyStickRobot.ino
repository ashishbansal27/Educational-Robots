#include<AFMotor.h>
AF_DCMotor motorLeft(2);
AF_DCMotor motorRight(4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  motorLeft.setSpeed(100);
  motorRight.setSpeed(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xValue = analogRead(A4);
  int yValue = analogRead(A5);
  Serial.print("X:");
  Serial.println(xValue);
  Serial.print("Y:");
  Serial.println(yValue);
  //delay(500);

  if (xValue > 700) {
    motorLeft.run(FORWARD);
    motorRight.run(FORWARD);
    Serial.println("Going Forward");
  }
  else if (xValue < 300) {
    motorLeft.run(BACKWARD);
    motorRight.run(BACKWARD);
    Serial.println("Going Backward");
  }
  else if (yValue > 700) {
    motorLeft.run(FORWARD);
    motorRight.run(RELEASE);
    Serial.println("Going Right");
  }
  else if (yValue < 300) {
    motorLeft.run(RELEASE);
    motorRight.run(FORWARD);
    Serial.println("Going Left");
  }

  else {
    motorLeft.run(RELEASE);
    motorRight.run(RELEASE);
    Serial.println("At rest");
  }
}

