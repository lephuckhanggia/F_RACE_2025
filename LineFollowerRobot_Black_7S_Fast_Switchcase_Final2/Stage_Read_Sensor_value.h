void Read_Sensor_Value() {
  uint8_t sensor_values = PIND;  // Read all sensor values at once
  V_STL = (sensor_values >> 2) & 1;
  V_S1  = (sensor_values >> 3) & 1;
  V_S2  = (sensor_values >> 4) & 1;
  V_S3  = (sensor_values >> 5) & 1;
  V_S4  = (sensor_values >> 6) & 1;
  V_S5  = (sensor_values >> 7) & 1;
  V_STR = (PINB >> 0) & 1;  // Read STR separately from PORTB
}
void Read_Run_Button_Value() 
{
 V_But1 = digitalRead(But1);
 V_But2 = digitalRead(But2);
 if (V_But1 == LOW) {
        currentMode = 1;
    }
 if (V_But2 == LOW) {
        currentMode = 2;
        digitalWrite(Led1, LOW);
        digitalWrite(Led2, HIGH);
    }
}

//void printBinary(int num, int bits = 7) {
//    for (int i = bits - 1; i >= 0; i--) {
//        SensorValue = bitRead(num, i);
//    }
// 
//}
//void Print_Sensor_Value() 
//{
//  Serial.print(SensorPattern, BIN);
////  Serial.print(V_STL);
////  Serial.print(V_S1);
////  Serial.print(V_S2);  
////  Serial.print(V_S3);
////  Serial.print(V_S4);
////  Serial.print(V_S5);
////  Serial.print(V_STR);
//  Serial.print("    But1: ");
//  Serial.print(V_But1);
//  Serial.print(" But2: ");
//  Serial.print(V_But2);
//  Serial.print(" CurrentMode: ");
//  Serial.println(currentMode);
////  delay(50);
//}
