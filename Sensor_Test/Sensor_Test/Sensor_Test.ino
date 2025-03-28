//Sensors
#define STL A0
#define S1 8
#define S2 9
#define S3 10 
#define S4 11
#define S5 12
#define STR A1


int V_STL ,V_S1, V_S2, V_S3, V_S4, V_S5, V_STR, V_SB;

void setup() {
  // put your setup code here, to run once:
  pinMode(STL, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(STR, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  V_STL = digitalRead(STL);
  V_S1 = digitalRead(S1);
  V_S2 = digitalRead(S2);
  V_S3 = digitalRead(S3);
  V_S4 = digitalRead(S4);
  V_S5 = digitalRead(S5);
  V_STR = digitalRead(STR);
  Serial.print("  STL: ");
  Serial.print(V_STL);
  Serial.print("  S1: ");
  Serial.print(V_S1);
  Serial.print("  S2: ");
  Serial.print(V_S2);  
  Serial.print("  S3: ");
  Serial.print(V_S3);
  Serial.print("  S4: ");
  Serial.print(V_S4);
  Serial.print("  S5: ");
  Serial.print(V_S5);
  Serial.print("  STR: ");
  Serial.println(V_STR);
}
