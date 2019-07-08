#include<AFMotor.h>
AF_DCMotor motorR(3);
AF_DCMotor motorL(1);
void setup() {
  
  // put your setup code here, to run once:
motorR.setSpeed(50);
motorL.setSpeed(50);
pinMode(A0,INPUT);
//pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
 if(digitalRead(A0)){
  motorR.run(RELEASE);
  motorL.run(FORWARD);
 }

 else{
  motorR.run(FORWARD);
  motorL.run(FORWARD);
  
 }

 
  
  // put your main code here, to run repeatedly:

}
