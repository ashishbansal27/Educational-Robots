#include<AFMotor.h>
AF_DCMotor left(2);
AF_DCMotor right(4);
int leftValue;
int rightValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  left.setSpeed(170);
  right.setSpeed(170); 
}

void loop() {
  leftValue = analogRead(A0);
  rightValue = analogRead(A1);
  // put your main code here, to run repeatedly:
  Serial.print("leftValue:");
  Serial.println(leftValue);
  Serial.print("rightValue:");
  Serial.println(rightValue);
  //delay(500);

  if (leftValue < 800 && rightValue < 800) {
    left.run(FORWARD);
    right.run(FORWARD);
    Serial.print("GOING FORWARD");
  }
  if (leftValue > 900) {
    left.run(RELEASE);
    right.run(FORWARD);
    Serial.print("GOING LEFT");
  }
  if (rightValue > 900) {
    left.run(FORWARD);
    right.run(RELEASE);
    Serial.print("GOING RIGHT");

  }
delay(500);
}
