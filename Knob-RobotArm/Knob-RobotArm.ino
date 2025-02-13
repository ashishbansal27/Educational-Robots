/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;// create servo object to control a servo
Servo myservo1;
Servo myservo2;
Servo myservo3;

int potpin = 0;  // analog pin used to connect the potentiometer
int potpin1 = 1;
int potpin2 = 2;
int potpin3 = 3;
int val;    // variable to read the value from the analog pin
int val1; 
int val2; 
int val3; 

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(10);
  myservo2.attach(9);
  myservo3.attach(6);
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  val1 = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023)
  val1 = map(val1, 0, 1023, 0, 180); 
  val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1023, 0, 180); 
  val3 = analogRead(potpin3);            // reads the value of the potentiometer (value between 0 and 1023)
  val3 = map(val3, 0, 1023, 0, 180); 
  
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);
  myservo1.write(val1);  
  delay(15);
  myservo2.write(val2); 
  delay(15); 
  myservo3.write(val3);  
  delay(15);                           // waits for the servo to get there
}

