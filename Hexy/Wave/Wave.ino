 #include<Servo.h>

Servo R1Toe, R1Knee, R1Thigh,
      R2Toe, R2Knee, R2Thigh,
      R3Toe, R3Knee, R3Thigh,
      L1Toe, L1Knee, L1Thigh,
      L2Toe, L2Knee, L2Thigh,
      L3Toe, L3Knee, L3Thigh;

      
#define MOVE_HEXY_SIZE 38


void setup() {
  // put your setup code here, to run once:
  R1Toe.attach(39);
  R1Knee.attach(38);
  R1Thigh.attach(37);
  R2Toe.attach(42);
  R2Knee.attach(41);
  R2Thigh.attach(40);
  R3Toe.attach(45);
  R3Knee.attach(44);
  R3Thigh.attach(43);
  L1Toe.attach(31);
  L1Knee.attach(32);
  L1Thigh.attach(33);
  L2Toe.attach(28);
  L2Knee.attach(29);
  L2Thigh.attach(30);
  L3Toe.attach(22);
  L3Knee.attach(23);
  L3Thigh.attach(24);
}

void loop() {
  // put your main code here, to run repeatedly:
  move_hexy();
}
const  uint16_t move_hexy_time[MOVE_HEXY_SIZE] = {
0, 0, 0, 1, 1, 1, 213, 214, 214, 214, 215, 215, 424, 425, 425, 426, 635, 635, 636, 636, 637, 637, 840, 840, 841, 841, 1050, 1050, 1051, 1052, 1052, 1052, 1266, 1268, 1270, 1271, 1483, 1484};

const  uint8_t move_hexy_servo[MOVE_HEXY_SIZE] = {
7, 7, 6, 6, 5, 5, 7, 7, 6, 6, 5, 5, 6, 6, 5, 5, 7, 7, 6, 6, 5, 5, 6, 6, 5, 5, 7, 7, 6, 6, 5, 5, 6, 6, 5, 5, 6, 6};

const  uint8_t move_hexy_pos[MOVE_HEXY_SIZE] = {
1816 , 127 , 1816 , 150 , 1816 , 150 , 127 , 127 , 150 , 94 , 150 , 127 , 94 , 138 , 127 , 150 , 127 , 127 , 138 , 94 , 150 , 127 , 94 , 138 , 127 , 150 , 127 , 127 , 138 , 94 , 150 , 127 , 94 , 138 , 127 , 150 , 138 , 105 };


void move_hexy() {
  int startTime = millis();
  int currentTime = 0;
  int last_update = 0;
  for (int i = 0; i < MOVE_HEXY_SIZE; i++) {
    delayMicroseconds(10);
    currentTime = millis() - startTime;
    uint16_t move_time = move_hexy_time[i];
    while (currentTime < move_time) {
      delayMicroseconds(10);
      currentTime = millis() - startTime;
    }
    uint8_t servo_time = move_hexy_servo[i];
    uint8_t servo_pos  = move_hexy_pos[i];
    changeServo(servo_time, servo_pos * 10);
    last_update = currentTime;
  }
}
//Move Size is 100 bytes
//Run this move by using:
// move_hexy()
void changeServo(int servoTime, int servoAngle) {
  switch (servoTime) {
    case 24: R1Thigh.writeMicroseconds(servoAngle);
      break;
    case 25: R1Knee.writeMicroseconds(servoAngle);
      break;
    case 26: R1Toe.writeMicroseconds(servoAngle);
      break;
    case 20: R2Thigh.writeMicroseconds(servoAngle);
      break;
    case 21: R2Knee.writeMicroseconds(servoAngle);
      break;
    case 22: R2Toe.writeMicroseconds(servoAngle);
      break;
    case 16: R3Thigh.writeMicroseconds(servoAngle);
      break;
    case 17: R3Knee.writeMicroseconds(servoAngle);
      break;
    case 18: R3Toe.writeMicroseconds(servoAngle);
      break;
    case 7: L1Thigh.writeMicroseconds(servoAngle);
      break;
    case 6: L1Knee.writeMicroseconds(servoAngle);
      break;
    case 5: L1Toe.writeMicroseconds(servoAngle);
      break;
    case 11:  L2Thigh.writeMicroseconds(servoAngle);
      break;
    case 10:  L2Knee.writeMicroseconds(servoAngle);
      break;
    case 9: L2Toe.writeMicroseconds(servoAngle);
      break;

    case 15 : L3Thigh.writeMicroseconds(servoAngle);
      break;
    case 14: L3Knee.writeMicroseconds(servoAngle);
      break;
    case 13: L3Toe.writeMicroseconds(servoAngle);
      break;
  }
}

