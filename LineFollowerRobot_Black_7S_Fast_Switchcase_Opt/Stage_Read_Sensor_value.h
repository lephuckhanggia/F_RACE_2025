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
  V_But2 = analogRead(But2);
  V_But3 = analogRead(But3);
  if (V_But1 == LOW) {
    PORTC |= (1 << PC4);
    PORTC &= ~(1 << PC3);
    PORTB &= ~(1 << PB5);
    currentMode = 1;
  }
  if (V_But3 < 100){
    PORTC &= ~(1 << PC4);
    PORTC &= ~(1 << PC3);
    PORTB |= (1 << PB5);
    currentMode = 2;
  }
  if (V_But2 > 900){
    PORTC |= (1 << PC3);
    RunAndSpeedMode = 1;
  }

  if (V_But2 < 100){
    PORTC |= (1 << PC3);
    delay(50);
    PORTC &= ~(1 << PC3);
    delay(50);
    RunAndSpeedMode = 2;
  }
}
//void Print_Sensor_Value() 
//{
//  Serial.print(V_STL);
//  Serial.print(V_S1);
//  Serial.print(V_S2);  
//  Serial.print(V_S3);
//  Serial.print(V_S4);
//  Serial.print(V_S5);
//  Serial.print(V_STR);
//  Serial.print("    But1: ");
//  Serial.print(V_But1);
//  Serial.print(" But2: ");
//  Serial.print(V_But2);
//  Serial.print(" But3: ");
//  Serial.print(V_But3);
//  Serial.print(" CurrentMode: ");
//  Serial.print(currentMode);
//  Serial.print(" RunAndSpeedMode: ");
//  Serial.print(RunAndSpeedMode);
//  Serial.print(" SpeedMax: ");
//  Serial.println(SpeedMax);
//}
