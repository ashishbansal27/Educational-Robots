#include<AFMotor.h>
AF_DCMotor left(4);
AF_DCMotor right(1);
int leftValue;
int rightValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  left.setSpeed(120);
  right.setSpeed(100); 
}

void loop() {
  leftValue = digitalRead(A0);
  rightValue = digitalRead(A1);
  // put your main code here, to run repeatedly:
  Serial.print("leftValue:");
  Serial.println(leftValue);
  Serial.print("rightValue:");
  Serial.println(rightValue);
  //delay(500);

  if (leftValue) {
    left.run(RELEASE);
    right.run(BACKWARD);
    Serial.print("GOING left");
  }
   else if (rightValue) {
    left.run(BACKWARD);
    right.run(RELEASE);
    Serial.print("GOING right");
  }
 else  {
    left.run(RELEASE);
    right.run(RELEASE);
    Serial.print("resting");

  }

}
