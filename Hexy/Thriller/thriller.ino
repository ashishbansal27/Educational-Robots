 #include<Servo.h>

Servo R1Toe, R1Knee, R1Thigh,
      R2Toe, R2Knee, R2Thigh,
      R3Toe, R3Knee, R3Thigh,
      L1Toe, L1Knee, L1Thigh,
      L2Toe, L2Knee, L2Thigh,
      L3Toe, L3Knee, L3Thigh;

      
#define MOVE_HEXY_SIZE 372


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
0, 0, 0, 0, 1, 1, 102, 103, 103, 103, 104, 104, 210, 211, 411, 412, 412, 412, 412, 413, 519, 519, 519, 520, 520, 521, 627, 627, 628, 628, 628, 628, 813, 813, 813, 813, 814, 814, 925, 925, 925, 926, 926, 926, 1029, 1029, 1215, 1216, 1216, 1216, 1216, 1217, 1316, 1317, 1317, 1317, 1318, 1318, 1427, 1428, 1428, 1428, 1429, 1429, 1629, 1629, 1630, 1630, 1631, 1631, 1631, 1632, 1632, 1632, 1633, 1633, 1633, 1634, 1634, 1634, 1634, 1634, 1635, 1635, 2142, 2142, 2143, 2144, 2145, 2145, 2146, 2146, 2147, 2147, 2147, 2147, 2148, 2148, 2148, 2148, 2149, 2149, 2149, 2149, 2150, 2150, 2150, 2150, 2150, 2150, 2151, 2151, 2355, 2356, 2356, 2357, 2358, 2359, 2359, 2360, 2360, 2361, 2361, 2361, 2362, 2362, 2362, 2362, 2363, 2363, 2363, 2363, 2364, 2364, 2364, 2364, 2364, 2364, 2365, 2365, 2872, 2872, 2873, 2873, 2874, 2875, 2875, 2875, 2876, 2876, 2876, 2876, 2877, 2877, 2877, 2877, 2877, 2878, 2878, 2878, 2878, 2878, 2878, 2878, 2879, 2879, 2879, 2879, 3089, 3090, 3090, 3091, 3091, 3092, 3092, 3093, 3093, 3094, 3094, 3094, 3094, 3095, 3095, 3095, 3095, 3095, 3095, 3096, 3096, 3096, 3096, 3096, 3096, 3096, 3097, 3097, 3602, 3603, 3603, 3604, 3605, 3605, 3606, 3606, 3606, 3607, 3607, 3608, 3608, 3608, 3608, 3609, 3609, 3609, 3609, 3610, 3610, 3610, 3610, 3610, 3611, 3611, 3611, 3611, 3815, 3816, 3817, 3817, 3818, 3818, 3819, 3819, 3820, 3820, 3820, 3821, 3821, 3821, 3822, 3822, 3822, 3823, 3823, 3823, 3823, 3823, 3824, 3824, 3824, 3824, 3824, 3824, 4326, 4327, 4327, 4328, 4329, 4329, 4330, 4330, 4331, 4331, 4331, 4332, 4332, 4332, 4333, 4333, 4333, 4333, 4334, 4334, 4334, 4334, 4334, 4334, 4335, 4335, 4335, 4335, 4548, 4549, 4550, 4551, 4551, 4552, 4552, 4553, 4553, 4553, 4554, 4554, 4555, 4555, 4555, 4556, 4556, 4556, 4556, 4556, 4557, 4557, 4557, 4557, 4557, 4557, 4558, 4558, 5057, 5058, 5058, 5059, 5059, 5060, 5060, 5060, 5061, 5061, 5061, 5062, 5062, 5062, 5062, 5063, 5063, 5063, 5063, 5063, 5064, 5064, 5064, 5064, 5064, 5064, 5065, 5065, 5564, 5565, 5566, 5566, 5566, 5567, 5567, 5568, 5568, 5568, 5568, 5568, 5675, 5676, 5676, 5676, 5677, 5677, 5678, 5678, 5678, 5678, 5678, 5679, 5784, 5784, 5785, 5786, 5786, 5786, 5786, 5786, 5787, 5787, 5787, 5787};

const  uint8_t move_hexy_servo[MOVE_HEXY_SIZE] = {
6, 6, 5, 5, 7, 7, 6, 6, 5, 5, 7, 7, 7, 7, 25, 25, 26, 26, 24, 24, 25, 25, 26, 26, 24, 24, 25, 25, 26, 26, 24, 24, 10, 10, 9, 9, 11, 11, 10, 10, 9, 9, 11, 11, 11, 11, 21, 21, 22, 22, 20, 20, 21, 21, 22, 22, 20, 20, 21, 21, 22, 22, 20, 20, 17, 17, 18, 14, 25, 18, 14, 25, 6, 13, 6, 13, 26, 26, 5, 5, 24, 24, 7, 7, 10, 10, 9, 14, 9, 14, 21, 13, 21, 13, 22, 17, 25, 22, 17, 25, 18, 6, 18, 6, 26, 26, 5, 5, 24, 24, 7, 7, 10, 10, 9, 9, 14, 14, 21, 13, 21, 17, 13, 25, 22, 17, 25, 22, 18, 6, 18, 6, 26, 26, 5, 5, 24, 24, 7, 7, 10, 10, 9, 14, 9, 14, 21, 13, 21, 17, 13, 25, 22, 17, 25, 22, 18, 6, 18, 6, 26, 26, 5, 5, 24, 24, 7, 7, 10, 10, 9, 14, 9, 14, 21, 21, 13, 25, 17, 13, 22, 25, 17, 22, 6, 18, 6, 18, 26, 26, 5, 5, 24, 24, 7, 7, 10, 10, 9, 14, 9, 14, 13, 21, 13, 21, 22, 25, 17, 22, 25, 17, 6, 18, 6, 18, 26, 26, 5, 5, 24, 24, 7, 7, 10, 10, 9, 14, 9, 14, 21, 13, 25, 17, 21, 13, 25, 17, 22, 6, 18, 22, 6, 18, 26, 26, 5, 5, 24, 24, 7, 7, 10, 10, 14, 9, 14, 21, 9, 13, 21, 17, 25, 13, 22, 17, 25, 22, 18, 6, 18, 6, 26, 26, 5, 5, 24, 24, 7, 7, 10, 10, 9, 14, 9, 14, 21, 13, 21, 13, 22, 17, 25, 22, 17, 25, 18, 6, 18, 6, 26, 26, 5, 5, 24, 24, 7, 7, 10, 10, 9, 14, 9, 14, 13, 21, 13, 21, 25, 17, 22, 25, 17, 22, 6, 18, 6, 18, 26, 26, 5, 5, 24, 24, 7, 7, 6, 6, 5, 25, 5, 25, 7, 26, 7, 26, 24, 24, 6, 25, 6, 25, 5, 26, 5, 26, 7, 24, 7, 24, 25, 6, 25, 6, 26, 5, 26, 5, 24, 7, 24, 7};

const  uint8_t move_hexy_pos[MOVE_HEXY_SIZE] = {
1816 , 153 , 1816 , 53 , 1816 , 134 , 153 , 168 , 53 , 68 , 134 , 118 , 118 , 103 , 1816 , 160 , 1816 , 60 , 1816 , 164 , 160 , 151 , 60 , 51 , 164 , 178 , 151 , 181 , 51 , 81 , 178 , 193 , 1816 , 153 , 1816 , 53 , 1816 , 134 , 153 , 168 , 53 , 68 , 134 , 118 , 118 , 103 , 1816 , 160 , 1816 , 60 , 1816 , 164 , 160 , 151 , 60 , 51 , 164 , 178 , 151 , 181 , 51 , 81 , 178 , 193 , 1816 , 185 , 1816 , 1816 , 181 , 85 , 185 , 83 , 168 , 1816 , 83 , 85 , 81 , 61 , 68 , 61 , 193 , 238 , 103 , 150 , 168 , 198 , 68 , 185 , 98 , 178 , 181 , 85 , 198 , 78 , 81 , 185 , 83 , 98 , 178 , 150 , 85 , 83 , 78 , 150 , 61 , 83 , 61 , 83 , 238 , 194 , 150 , 105 , 198 , 209 , 98 , 109 , 178 , 185 , 198 , 78 , 209 , 178 , 85 , 150 , 98 , 185 , 83 , 109 , 78 , 150 , 85 , 83 , 83 , 61 , 83 , 61 , 194 , 150 , 105 , 61 , 209 , 198 , 109 , 185 , 98 , 178 , 209 , 85 , 198 , 185 , 78 , 83 , 109 , 178 , 150 , 98 , 85 , 83 , 78 , 150 , 61 , 83 , 61 , 83 , 150 , 194 , 61 , 105 , 198 , 209 , 98 , 178 , 109 , 185 , 198 , 209 , 78 , 150 , 178 , 85 , 98 , 83 , 185 , 109 , 150 , 78 , 83 , 85 , 83 , 61 , 83 , 61 , 194 , 150 , 105 , 61 , 209 , 198 , 109 , 185 , 98 , 178 , 85 , 209 , 78 , 198 , 109 , 83 , 185 , 98 , 150 , 178 , 83 , 85 , 150 , 78 , 61 , 83 , 61 , 83 , 150 , 194 , 61 , 105 , 198 , 209 , 98 , 178 , 109 , 185 , 198 , 78 , 150 , 178 , 209 , 85 , 83 , 185 , 98 , 150 , 78 , 109 , 83 , 85 , 83 , 61 , 83 , 61 , 194 , 238 , 105 , 150 , 209 , 198 , 185 , 109 , 178 , 209 , 98 , 85 , 198 , 185 , 83 , 78 , 109 , 178 , 150 , 98 , 85 , 83 , 78 , 150 , 61 , 83 , 61 , 83 , 238 , 194 , 150 , 105 , 198 , 209 , 98 , 178 , 109 , 185 , 198 , 78 , 209 , 85 , 98 , 178 , 150 , 109 , 185 , 83 , 78 , 150 , 85 , 83 , 83 , 61 , 83 , 61 , 194 , 238 , 105 , 150 , 209 , 198 , 109 , 185 , 98 , 178 , 85 , 209 , 78 , 198 , 83 , 185 , 109 , 150 , 178 , 98 , 83 , 85 , 150 , 78 , 61 , 83 , 61 , 83 , 238 , 194 , 150 , 105 , 150 , 209 , 83 , 150 , 109 , 209 , 105 , 83 , 105 , 109 , 194 , 194 , 209 , 209 , 209 , 209 , 109 , 109 , 109 , 109 , 105 , 194 , 105 , 194 , 209 , 209 , 209 , 209 , 109 , 109 , 109 , 109 , 194 , 105 , 194 , 105 };



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

