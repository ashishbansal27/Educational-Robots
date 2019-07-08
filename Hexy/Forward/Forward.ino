#include<Servo.h>

Servo R1Toe, R1Knee, R1Thigh,
      R2Toe, R2Knee, R2Thigh,
      R3Toe, R3Knee, R3Thigh,
      L1Toe, L1Knee, L1Thigh,
      L2Toe, L2Knee, L2Thigh,
      L3Toe, L3Knee, L3Thigh;


#define MOVE_HEXY_SIZE 260


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
  0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 169, 170, 170, 171, 171, 172, 172, 173, 173, 173, 174, 174, 174, 174, 175, 175, 175, 175, 338, 338, 339, 339, 340, 340, 340, 341, 341, 341, 342, 342, 342, 342, 605, 606, 607, 607, 608, 609, 609, 610, 611, 611, 612, 612, 613, 613, 613, 613, 613, 614, 614, 614, 614, 614, 615, 615, 615, 615, 615, 616, 616, 616, 776, 777, 777, 777, 778, 778, 778, 779, 779, 780, 780, 781, 781, 781, 781, 782, 782, 782, 945, 945, 945, 946, 946, 946, 947, 947, 947, 948, 948, 948, 949, 949, 950, 950, 950, 950, 1213, 1213, 1214, 1215, 1216, 1217, 1218, 1218, 1219, 1220, 1220, 1220, 1220, 1220, 1221, 1221, 1221, 1221, 1222, 1222, 1222, 1222, 1222, 1222, 1223, 1223, 1223, 1223, 1223, 1223, 1383, 1384, 1384, 1384, 1385, 1386, 1386, 1386, 1387, 1387, 1387, 1388, 1388, 1388, 1389, 1389, 1389, 1389, 1552, 1553, 1553, 1553, 1554, 1554, 1554, 1555, 1555, 1555, 1556, 1556, 1556, 1557, 1557, 1557, 1558, 1558, 1820, 1821, 1822, 1822, 1823, 1824, 1825, 1825, 1826, 1827, 1827, 1827, 1827, 1827, 1828, 1828, 1828, 1828, 1829, 1829, 1829, 1829, 1829, 1829, 1830, 1830, 1830, 1830, 1831, 1831, 1991, 1991, 1992, 1992, 1993, 1994, 1994, 1994, 1995, 1995, 1996, 1996, 1996, 1996, 1996, 1997, 1997, 1997, 2160, 2161, 2161, 2162, 2162, 2162, 2163, 2163, 2164, 2164, 2164, 2165, 2165, 2165, 2165, 2165, 2166, 2166
};

const  uint8_t move_hexy_servo[MOVE_HEXY_SIZE] = {
  6, 6, 5, 21, 5, 21, 14, 7, 22, 14, 7, 22, 24, 13, 20, 24, 11, 13, 20, 24, 11, 16, 15, 24, 11, 16, 15, 11, 16, 16, 6, 6, 5, 5, 21, 7, 21, 7, 22, 22, 20, 14, 20, 14, 13, 13, 15, 15, 6, 6, 5, 5, 7, 21, 7, 21, 22, 22, 15, 20, 15, 20, 25, 25, 10, 26, 10, 26, 17, 9, 24, 17, 7, 9, 24, 18, 20, 7, 11, 15, 18, 20, 11, 7, 15, 16, 20, 7, 15, 16, 20, 15, 25, 25, 26, 26, 24, 24, 10, 10, 9, 17, 9, 17, 11, 18, 11, 18, 16, 16, 25, 25, 26, 26, 24, 24, 10, 10, 9, 9, 17, 11, 17, 11, 18, 18, 16, 16, 6, 6, 5, 21, 5, 21, 14, 7, 22, 14, 7, 24, 22, 13, 24, 11, 20, 13, 24, 11, 16, 20, 15, 24, 11, 16, 15, 11, 16, 16, 6, 6, 5, 5, 7, 7, 21, 21, 22, 14, 22, 14, 20, 13, 20, 13, 15, 15, 6, 6, 5, 5, 7, 7, 21, 21, 22, 22, 14, 20, 14, 20, 13, 13, 15, 15, 25, 25, 10, 26, 10, 26, 17, 9, 24, 9, 17, 7, 24, 11, 18, 7, 20, 11, 18, 7, 20, 15, 16, 7, 20, 15, 16, 20, 15, 15, 25, 25, 26, 26, 10, 24, 10, 24, 17, 9, 17, 9, 18, 18, 11, 16, 11, 16, 25, 25, 26, 26, 24, 24, 10, 17, 10, 17, 9, 18, 9, 18, 11, 16, 11, 16
};

const  uint8_t move_hexy_pos[MOVE_HEXY_SIZE] = {
  1816 , 209 , 1816 , 1816 , 109 , 158 , 1816 , 1816 , 1816 , 153 , 150 , 58 , 1816 , 1816 , 1816 , 94 , 1816 , 53 , 158 , 94 , 177 , 1816 , 1816 , 94 , 177 , 150 , 131 , 177 , 150 , 150 , 209 , 209 , 109 , 109 , 158 , 150 , 153 , 150 , 58 , 53 , 158 , 153 , 167 , 165 , 53 , 65 , 131 , 112 , 209 , 209 , 109 , 109 , 150 , 153 , 150 , 193 , 53 , 93 , 112 , 167 , 93 , 176 , 1816 , 156 , 1816 , 1816 , 156 , 56 , 1816 , 1816 , 94 , 156 , 150 , 56 , 113 , 1816 , 176 , 205 , 177 , 93 , 56 , 122 , 159 , 205 , 150 , 150 , 122 , 205 , 150 , 168 , 122 , 150 , 156 , 156 , 56 , 56 , 113 , 131 , 156 , 156 , 56 , 156 , 56 , 156 , 159 , 56 , 140 , 56 , 168 , 187 , 156 , 209 , 56 , 109 , 131 , 150 , 156 , 209 , 56 , 109 , 156 , 140 , 209 , 122 , 56 , 109 , 187 , 205 , 209 , 156 , 109 , 193 , 56 , 156 , 165 , 205 , 93 , 156 , 187 , 150 , 56 , 65 , 94 , 122 , 122 , 56 , 94 , 177 , 205 , 140 , 150 , 94 , 177 , 150 , 131 , 177 , 150 , 150 , 156 , 156 , 56 , 56 , 187 , 168 , 156 , 156 , 56 , 156 , 56 , 156 , 140 , 56 , 159 , 56 , 131 , 113 , 156 , 209 , 56 , 109 , 168 , 150 , 156 , 209 , 56 , 109 , 156 , 159 , 209 , 177 , 56 , 109 , 113 , 94 , 209 , 156 , 209 , 109 , 156 , 56 , 209 , 109 , 94 , 56 , 156 , 150 , 113 , 177 , 109 , 205 , 177 , 159 , 56 , 205 , 122 , 94 , 150 , 205 , 122 , 150 , 168 , 122 , 150 , 150 , 156 , 156 , 56 , 56 , 156 , 113 , 156 , 131 , 156 , 56 , 156 , 56 , 56 , 56 , 159 , 168 , 140 , 187 , 156 , 209 , 56 , 109 , 131 , 150 , 156 , 156 , 209 , 209 , 56 , 56 , 109 , 109 , 140 , 187 , 122 , 205
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

