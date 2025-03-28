int currentMode = 0;

//Speed
int SpeedMax = 70;  //70 
int SpeedMin_1 = 40;  //40
int SpeedMin_2 = 20;  //20
int SpeedMin_3 = 10;  //10
int SpeedMin_4 = 0;  //0
int SpeedLech = 0; //15

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
int Turn90Delay = 0;    //150-200
int Turn_check = 0;
int Turning = 0;
int Time = 0;
int Start = 0;
int WhiteTurnRight = 0;
int WhiteTurnLeft = 0;
uint8_t SensorPattern = 255;
unsigned long whiteTurnRightTime = 0;  // Time when WhiteTurnRight was set
const unsigned long turnDuration = 3000; // 3 seconds
//unsigned long turnStartTime = 0;
//bool turning = false;

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
#define EnA 11// 6
#define In1 A0//5
#define In2 A1//7
#define In3 9//2
#define In4 12//4
#define EnB 10//3

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
  
  pinMode(EnA, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(EnB, OUTPUT);

  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
