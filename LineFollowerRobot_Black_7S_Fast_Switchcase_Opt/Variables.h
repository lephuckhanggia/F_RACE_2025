int currentMode = 0;

//Speed
int SpeedMax = 140;   //90  //70 
int SpeedMin_1 = 100;    //50  //40
int SpeedMin_2 = 70;    //30  //20
int SpeedMin_3 = 30;    //15  //10
int SpeedMin_4 = 5;   //5;  //0
int SpeedLech = 0; 

//A-Trai B-Phai
int SpeedA = SpeedMax  ;
int SpeedB = SpeedMax+ SpeedLech ;
int SpeedMinA_1 = SpeedMin_1;
int SpeedMinB_1 = SpeedMin_1+ SpeedLech ;
int SpeedMinA_2 = SpeedMin_2 ;
int SpeedMinB_2 = SpeedMin_2+ SpeedLech;
int SpeedMinA_3 = SpeedMin_3 ;
int SpeedMinB_3 = SpeedMin_3+ SpeedLech;
int SpeedMinA_4 = SpeedMin_4 ;
int SpeedMinB_4 = SpeedMin_4+ SpeedLech;

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
#define But2 A3
bool V_But1, V_But2;

//Led_stage_button
#define Led1 A4 // GREEN
#define Led2 13// RED

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
  pinMode(But2, INPUT_PULLUP);

  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);

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
