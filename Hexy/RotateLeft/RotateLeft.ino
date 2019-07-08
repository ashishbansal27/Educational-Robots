 #include<Servo.h>

Servo R1Toe, R1Knee, R1Thigh,
      R2Toe, R2Knee, R2Thigh,
      R3Toe, R3Knee, R3Thigh,
      L1Toe, L1Knee, L1Thigh,
      L2Toe, L2Knee, L2Thigh,
      L3Toe, L3Knee, L3Thigh;

      
#define MOVE_HEXY_SIZE 174


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
0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 70, 70, 71, 71, 71, 72, 73, 73, 73, 73, 73, 74, 74, 74, 74, 74, 74, 75, 147, 147, 148, 149, 149, 150, 150, 150, 150, 150, 150, 151, 151, 151, 151, 151, 151, 151, 302, 303, 304, 304, 304, 305, 305, 306, 306, 306, 306, 306, 605, 606, 606, 607, 607, 607, 1012, 1012, 1013, 1014, 1014, 1014, 1015, 1015, 1015, 1016, 1016, 1016, 1320, 1321, 1322, 1322, 1323, 1324, 1324, 1325, 1325, 1325, 1325, 1325, 1326, 1326, 1326, 1326, 1326, 1326, 1438, 1439, 1439, 1440, 1441, 1441, 1441, 1442, 1442, 1442, 1442, 1442, 1442, 1443, 1443, 1443, 1443, 1443, 1541, 1541, 1542, 1542, 1543, 1543, 1544, 1544, 1544, 1544, 1545, 1545, 1545, 1545, 1545, 1545, 1546, 1546, 1834, 1835, 1836, 1837, 1837, 1838, 1839, 1839, 1840, 1840, 1841, 1841, 1842, 1842, 1842, 1843, 1843, 1843, 1843, 1844, 1844, 1844, 1845, 1845, 1845, 1845, 1846, 1846, 1846, 1846, 1847, 1847, 1847, 1847, 1848, 1848};

const  uint8_t move_hexy_servo[MOVE_HEXY_SIZE] = {
6, 6, 5, 14, 5, 14, 7, 13, 21, 7, 13, 21, 15, 22, 15, 22, 20, 20, 6, 21, 14, 6, 21, 14, 5, 22, 13, 5, 22, 13, 7, 20, 15, 7, 20, 15, 14, 21, 6, 14, 21, 6, 13, 22, 5, 13, 22, 5, 15, 20, 7, 15, 20, 7, 25, 25, 17, 26, 17, 26, 18, 10, 18, 10, 9, 9, 7, 7, 15, 15, 20, 20, 25, 25, 26, 17, 26, 17, 10, 18, 10, 18, 9, 9, 6, 6, 21, 5, 21, 5, 14, 22, 7, 14, 22, 7, 13, 20, 13, 20, 15, 15, 14, 6, 21, 14, 6, 21, 13, 5, 22, 13, 5, 22, 15, 7, 15, 20, 7, 20, 6, 14, 6, 21, 14, 5, 21, 13, 5, 22, 13, 7, 22, 15, 7, 20, 15, 20, 6, 6, 10, 5, 10, 5, 14, 9, 14, 25, 9, 13, 25, 21, 13, 26, 21, 7, 26, 17, 22, 7, 17, 22, 20, 18, 20, 18, 15, 15, 24, 24, 11, 11, 16, 16};

const  uint8_t move_hexy_pos[MOVE_HEXY_SIZE] = {
1816 , 160 , 1816 , 1816 , 60 , 160 , 1816 , 1816 , 1816 , 164 , 60 , 160 , 1816 , 1816 , 164 , 60 , 1816 , 164 , 160 , 160 , 160 , 151 , 151 , 151 , 60 , 60 , 60 , 51 , 51 , 51 , 164 , 164 , 164 , 178 , 178 , 178 , 151 , 151 , 151 , 181 , 181 , 181 , 51 , 51 , 51 , 81 , 81 , 81 , 178 , 178 , 178 , 193 , 193 , 193 , 1816 , 176 , 1816 , 1816 , 176 , 76 , 1816 , 1816 , 76 , 176 , 1816 , 76 , 193 , 105 , 193 , 105 , 193 , 105 , 176 , 209 , 76 , 176 , 109 , 209 , 176 , 76 , 209 , 109 , 76 , 109 , 181 , 156 , 181 , 81 , 156 , 56 , 181 , 81 , 105 , 209 , 56 , 135 , 81 , 105 , 109 , 120 , 105 , 105 , 209 , 156 , 156 , 209 , 156 , 156 , 109 , 56 , 56 , 109 , 56 , 56 , 105 , 135 , 105 , 120 , 164 , 135 , 156 , 209 , 209 , 156 , 209 , 56 , 209 , 109 , 109 , 56 , 109 , 164 , 109 , 105 , 194 , 135 , 105 , 151 , 209 , 209 , 209 , 109 , 209 , 109 , 209 , 109 , 209 , 209 , 109 , 109 , 209 , 209 , 109 , 109 , 209 , 194 , 109 , 209 , 109 , 183 , 209 , 109 , 151 , 109 , 150 , 109 , 105 , 116 , 1816 , 116 , 1816 , 150 , 1816 , 183 };


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

