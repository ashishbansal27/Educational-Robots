#include<Servo.h>

Servo R1Toe, R1Knee, R1Thigh,
      R2Toe, R2Knee, R2Thigh,
      R3Toe, R3Knee, R3Thigh,
      L1Toe, L1Knee, L1Thigh,
      L2Toe, L2Knee, L2Thigh,
      L3Toe, L3Knee, L3Thigh;

      
#define MOVE_HEXY_SIZE 72


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
 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 503, 504, 504, 505, 505, 506, 506, 507, 507, 507, 507, 507, 707, 707, 707, 708, 708, 708, 708, 709, 709, 709, 709, 710, 31851, 31852, 31853, 31853, 31854, 31854, 31854, 31854, 31855, 31855, 31855, 31855, 32356, 32356, 32357, 32357, 32358, 32358, 32359, 32359, 32359, 32360, 32360, 32360, 32560, 32560, 32561, 32561, 32561, 32562, 32562, 32562, 32563, 32563, 32563, 32564
};

const  uint8_t move_hexy_servo[MOVE_HEXY_SIZE] = {
  16, 16, 15, 15, 17, 17, 18, 14, 18, 14, 13, 13, 21, 20, 21, 20, 22, 22, 10, 11, 10, 11, 9, 9, 7, 7, 6, 6, 5, 5, 24, 24, 25, 25, 26, 26, 16, 16, 15, 15, 17, 17, 14, 18, 14, 18, 13, 13, 21, 20, 21, 20, 22, 22, 10, 11, 10, 9, 11, 9, 7, 7, 6, 6, 5, 5, 24, 24, 25, 25, 26, 26
};

const  uint8_t move_hexy_pos[MOVE_HEXY_SIZE] = {
 100 , 100 , 200 , 200 , 167 , 167 , 67 , 167 , 67 , 167 , 67 , 67 , 226 , 227 , 226 , 227 , 126 , 126 , 226 , 72 , 226 , 72 , 126 , 126 , 100 , 100 , 150 , 150 , 150 , 150 , 200 , 200 , 150 , 150 , 150 , 150 , 1816 , 100 , 1816 , 200 , 1816 , 167 , 1816 , 1816 , 167 , 67 , 1816 , 67 , 1816 , 1816 , 226 , 227 , 1816 , 126 , 1816 , 1816 , 226 , 1816 , 72 , 126 , 1816 , 100 , 1816 , 150 , 1816 , 150 , 1816 , 200 , 1816 , 150 , 1816 , 150
};


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

