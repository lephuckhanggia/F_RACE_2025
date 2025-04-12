int RunAndSpeedMode = 0;
int currentMode = 0;
//Speed Fast
int F_SpeedMax = 100;   //90  //70 
int F_SpeedMin_1 = 50;    //50  //40
int F_SpeedMin_2 = 25;    //30  //20
int F_SpeedMin_3 = 10;    //15  //10
int F_SpeedMin_4 = 0;   //5;  //0
int F_SpeedLech = 20; 

//Speed Slow
int S_SpeedMax = 80;   //90  //70 
int S_SpeedMin_1 = 40;    //50  //40
int S_SpeedMin_2 = 20;    //30  //20
int S_SpeedMin_3 = 10;    //15  //10
int S_SpeedMin_4 = 0;   //5;  //0
int S_SpeedLech = 20; 

//Speed Mode
int SpeedMax;
int SpeedMin_1;
int SpeedMin_2;
int SpeedMin_3;
int SpeedMin_4;
int SpeedLech;

//A-Phai B-Trai
int SpeedA;
int SpeedB;
int SpeedMinA_1; 
int SpeedMinB_1; 
int SpeedMinA_2;
int SpeedMinB_2;
int SpeedMinA_3; 
int SpeedMinB_3; 
int SpeedMinA_4; 
int SpeedMinB_4; 

//Others
int Full_Black_Reset_Time = 200;    //150-200
int Turn_check = 0;
int Turning = 0;
int Time = 0;
int Start = 0;
int WhiteTurnRight = 0;
int WhiteTurnLeft = 0;
uint8_t SensorPattern5 = 255;
uint8_t SensorPattern7 = 255;
bool PatternMatched = false;
unsigned long blackExitTime = 0;
bool inFullBlack = false;

//Sensors
#define STL 2//A0
#define S1 3//8
#define S2 4//9
#define S3 5//10 
#define S4 6//11
#define S5 7//12
#define STR 8//A1

int V_STL ,V_S1, V_S2, V_S3, V_S4, V_S5, V_STR;

//L298n driver
#define EnA 11  // D11 → OC2A → Timer2
#define In1 A0  // PC0
#define In2 A1  // PC1
#define In3 9   // PB1
#define In4 12  // PB4
#define EnB 10  // D10 → OC1B → Timer1

// Bit Macros for Motor Direction
#define IN1_HIGH PORTC |= (1 << PC0)
#define IN1_LOW  PORTC &= ~(1 << PC0)

#define IN2_HIGH PORTC |= (1 << PC1)
#define IN2_LOW  PORTC &= ~(1 << PC1)

#define IN3_HIGH PORTB |= (1 << PB1)
#define IN3_LOW  PORTB &= ~(1 << PB1)

#define IN4_HIGH PORTB |= (1 << PB4)
#define IN4_LOW  PORTB &= ~(1 << PB4)

//Stage_button
#define But1 0
#define But2 A7
#define But3 A6
int V_But2, V_But3;
bool V_But1;

//Led_stage_button
#define LedG A4 // GREEN
#define LedY A3// Yellow
#define LedR 13

#define trigPin A5   // Chân trig nối với D8
#define echoPin A2   // Chân echo nối với D9

void Variable_Status() {
  pinMode(STL, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(STR, INPUT);

  pinMode(But1, INPUT_PULLUP);

  pinMode(LedG, OUTPUT);
  pinMode(LedY, OUTPUT);
  pinMode(LedR, OUTPUT);

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set motor direction pins as output
  DDRC |= (1 << PC0) | (1 << PC1);      // In1, In2 (A0, A1)
  DDRB |= (1 << PB1) | (1 << PB4);      // In3, In4 (D9, D12)

  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);

  // Timer2 for EnA (D11)
  TCCR2A = _BV(COM2A1) | _BV(WGM21) | _BV(WGM20); // Fast PWM, non-inverting
  TCCR2B = _BV(CS22); // Prescaler 64 → ~976 Hz
  OCR2A = 0;

  // Timer1 for EnB (D10)
  TCCR1A = _BV(COM1B1) | _BV(WGM10); // Fast PWM 8-bit, non-inverting
  TCCR1B = _BV(WGM12) | _BV(CS11) | _BV(CS10); // Prescaler 64
  OCR1B = 0;
}
