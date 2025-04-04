void setPWM(int a, int b) {
  OCR2A = a;
  OCR1B = b;
}

// --- Movement Functions ---

void Run_Straight() {
  IN1_HIGH; IN2_LOW;
  IN3_HIGH; IN4_LOW;
  setPWM(SpeedA, SpeedB);
}

void Stop() {
  IN1_LOW; IN2_LOW;
  IN3_LOW; IN4_LOW;
  setPWM(0, 0);
}

void OneWD_Turn_Left() {
  IN1_LOW; IN2_LOW;
  IN3_HIGH; IN4_LOW;
  setPWM(0, SpeedB);
}

void TwoWD_Turn_Left() {
  IN1_LOW; IN2_HIGH;
  IN3_HIGH; IN4_LOW;
  setPWM(105, 85);
}

void Slight_Left_1() {
  IN1_HIGH; IN2_LOW;
  IN3_HIGH; IN4_LOW;
  setPWM(SpeedMinA_1, SpeedB);
}
void Slight_Left_2() {
  IN1_HIGH; IN2_LOW;
  IN3_HIGH; IN4_LOW;
  setPWM(SpeedMinA_2, SpeedB);
}
void Slight_Left_3() {
  IN1_HIGH; IN2_LOW;
  IN3_HIGH; IN4_LOW;
  setPWM(SpeedMinA_3, SpeedB);
}
void Slight_Left_4() {
  IN1_HIGH; IN2_LOW;
  IN3_HIGH; IN4_LOW;
  setPWM(SpeedMinA_4, SpeedB);
}

void OneWD_Turn_Right() {
  IN1_HIGH; IN2_LOW;
  IN3_LOW; IN4_LOW;
  setPWM(SpeedA, 0);
}

void TwoWD_Turn_Right() {
  IN1_HIGH; IN2_LOW;
  IN3_LOW; IN4_HIGH;
  setPWM(80, 100);
}

void Slight_Right_1() {
  IN1_HIGH; IN2_LOW;
  IN3_HIGH; IN4_LOW;
  setPWM(SpeedA, SpeedMinB_1);
}
void Slight_Right_2() {
  IN1_HIGH; IN2_LOW;
  IN3_HIGH; IN4_LOW;
  setPWM(SpeedA, SpeedMinB_2);
}
void Slight_Right_3() {
  IN1_HIGH; IN2_LOW;
  IN3_HIGH; IN4_LOW;
  setPWM(SpeedA, SpeedMinB_3);
}
void Slight_Right_4() {
  IN1_HIGH; IN2_LOW;
  IN3_HIGH; IN4_LOW;
  setPWM(SpeedA, SpeedMinB_4);
}
