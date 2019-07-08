 #include<Servo.h>

Servo R1Toe, R1Knee, R1Thigh,
      R2Toe, R2Knee, R2Thigh,
      R3Toe, R3Knee, R3Thigh,
      L1Toe, L1Knee, L1Thigh,
      L2Toe, L2Knee, L2Thigh,
      L3Toe, L3Knee, L3Thigh;

      
#define MOVE_HEXY_SIZE 248


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
0, 1, 2, 4, 5, 6, 106, 108, 109, 110, 111, 112, 215, 216, 403, 405, 406, 407, 409, 410, 517, 518, 519, 520, 521, 522, 625, 626, 627, 627, 628, 629, 808, 809, 810, 811, 812, 813, 914, 915, 917, 918, 920, 921, 1033, 1034, 1218, 1219, 1221, 1223, 1224, 1225, 1339, 1341, 1343, 1345, 1346, 1347, 1463, 1464, 1465, 1467, 1469, 1471, 1633, 1636, 1638, 1639, 1640, 1641, 1641, 1642, 2145, 2147, 2148, 2149, 2151, 2152, 2163, 2166, 2168, 2171, 2173, 2175, 2176, 2178, 2181, 2182, 2183, 2184, 2185, 2186, 2186, 2187, 2580, 2581, 2582, 2583, 2585, 2586, 2594, 2596, 2599, 2602, 2604, 2605, 2606, 2608, 2609, 2610, 2610, 2611, 2612, 2613, 2613, 2614, 3010, 3012, 3013, 3014, 3016, 3017, 3027, 3029, 3032, 3036, 3038, 3040, 3042, 3043, 3045, 3046, 3047, 3048, 3049, 3050, 3051, 3052, 3439, 3441, 3442, 3443, 3444, 3445, 3455, 3458, 3461, 3465, 3467, 3469, 3471, 3472, 3473, 3474, 3475, 3476, 3477, 3478, 3479, 3480, 3874, 3876, 3877, 3879, 3880, 3882, 3891, 3893, 3897, 3899, 3902, 3904, 3907, 3908, 3910, 3910, 3911, 3912, 3913, 3914, 3915, 3915, 4307, 4309, 4310, 4310, 4312, 4313, 4319, 4321, 4323, 4325, 4328, 4330, 4331, 4333, 4334, 4335, 4336, 4336, 4337, 4338, 4339, 4339, 4731, 4732, 4734, 4735, 4736, 4737, 4745, 4747, 4749, 4751, 4753, 4755, 4756, 4757, 4758, 4759, 4760, 4760, 4761, 4761, 4762, 4763, 5160, 5162, 5163, 5165, 5167, 5168, 5176, 5178, 5180, 5183, 5185, 5188, 5190, 5192, 5193, 5194, 5195, 5196, 5196, 5197, 5198, 5199};

const  uint8_t move_hexy_servo[MOVE_HEXY_SIZE] = {
6, 6, 5, 5, 7, 7, 6, 6, 5, 5, 7, 7, 7, 7, 25, 25, 26, 26, 24, 24, 25, 25, 26, 26, 24, 24, 25, 25, 26, 26, 24, 24, 10, 10, 9, 9, 11, 11, 10, 10, 9, 9, 11, 11, 11, 11, 21, 21, 22, 22, 20, 20, 21, 21, 22, 22, 20, 20, 21, 21, 22, 22, 20, 20, 17, 17, 14, 18, 14, 18, 13, 13, 25, 25, 26, 26, 24, 24, 10, 10, 14, 9, 14, 9, 13, 21, 13, 21, 17, 22, 17, 22, 18, 18, 25, 25, 26, 26, 24, 24, 10, 10, 14, 9, 14, 9, 21, 13, 21, 13, 22, 17, 22, 17, 18, 18, 25, 25, 26, 26, 24, 24, 10, 10, 14, 9, 14, 9, 13, 21, 13, 21, 17, 22, 17, 22, 18, 18, 25, 25, 26, 26, 24, 24, 10, 10, 14, 9, 14, 21, 9, 13, 21, 17, 13, 22, 17, 22, 18, 18, 25, 25, 26, 26, 24, 24, 10, 10, 9, 14, 9, 14, 21, 13, 21, 13, 17, 22, 17, 22, 18, 18, 25, 25, 26, 26, 24, 24, 10, 10, 9, 14, 9, 14, 21, 13, 21, 13, 17, 22, 17, 22, 18, 18, 25, 25, 26, 26, 24, 24, 10, 10, 14, 9, 14, 21, 9, 13, 21, 13, 17, 22, 17, 22, 18, 18, 25, 25, 26, 26, 24, 24, 10, 10, 14, 9, 14, 21, 9, 13, 21, 17, 13, 22, 17, 22, 18, 18};

const  uint8_t move_hexy_pos[MOVE_HEXY_SIZE] = {
1816 , 153 , 1816 , 53 , 1816 , 134 , 153 , 168 , 53 , 68 , 134 , 118 , 118 , 103 , 1816 , 160 , 1816 , 60 , 1816 , 164 , 160 , 151 , 60 , 51 , 164 , 178 , 151 , 181 , 51 , 81 , 178 , 193 , 1816 , 153 , 1816 , 53 , 1816 , 134 , 153 , 168 , 53 , 68 , 134 , 118 , 118 , 103 , 1816 , 160 , 1816 , 60 , 1816 , 164 , 160 , 151 , 60 , 51 , 164 , 178 , 151 , 181 , 51 , 81 , 178 , 193 , 1816 , 185 , 1816 , 1816 , 185 , 85 , 1816 , 85 , 181 , 83 , 81 , 150 , 193 , 150 , 168 , 198 , 185 , 68 , 178 , 98 , 85 , 181 , 78 , 198 , 185 , 81 , 178 , 98 , 85 , 78 , 83 , 205 , 150 , 94 , 150 , 227 , 198 , 209 , 178 , 98 , 185 , 109 , 198 , 78 , 209 , 85 , 98 , 178 , 109 , 185 , 78 , 85 , 205 , 83 , 94 , 150 , 227 , 150 , 209 , 198 , 185 , 109 , 178 , 98 , 85 , 209 , 78 , 198 , 185 , 109 , 178 , 98 , 85 , 78 , 83 , 205 , 150 , 94 , 150 , 227 , 198 , 209 , 178 , 98 , 185 , 198 , 109 , 78 , 209 , 178 , 85 , 98 , 185 , 109 , 78 , 85 , 205 , 83 , 94 , 150 , 227 , 150 , 209 , 198 , 109 , 185 , 98 , 178 , 209 , 85 , 198 , 78 , 185 , 109 , 178 , 98 , 85 , 78 , 83 , 205 , 150 , 94 , 150 , 227 , 198 , 209 , 98 , 178 , 109 , 185 , 198 , 78 , 209 , 85 , 178 , 98 , 185 , 109 , 78 , 85 , 205 , 83 , 94 , 150 , 227 , 150 , 209 , 198 , 185 , 109 , 178 , 209 , 98 , 85 , 198 , 78 , 185 , 109 , 178 , 98 , 85 , 78 , 83 , 205 , 150 , 94 , 150 , 227 , 198 , 209 , 178 , 98 , 185 , 198 , 109 , 78 , 209 , 178 , 85 , 98 , 185 , 109 , 78 , 85 };


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

