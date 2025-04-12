#include "Variables.h"
#include "Stage_Read_Sensor_value.h"
#include "Motor_Driver.h"
void setup() {
    Variable_Status();
}
void loop() {
    Read_Run_Button_Value(); 
    switch(RunAndSpeedMode){
        case 1:
          switch (currentMode) {
              case 1:
                  if (Start == 0) {  // Only check distance if robot hasn't started
                      digitalWrite(trigPin, LOW);
                      delayMicroseconds(2);
                      digitalWrite(trigPin, HIGH);
                      delayMicroseconds(10);
                      digitalWrite(trigPin, LOW);
                      long duration = pulseIn(echoPin, HIGH);
                      if (duration == 0) {
      //                    Serial.println("Không có phản hồi! Kiểm tra cảm biến.");
                          digitalWrite(LedR, HIGH);
                          delay(50);
                          digitalWrite(LedR, LOW);
                          delay(50);
                      } 
                      else {
                          long distance = duration * 0.034 / 2;
      //                    Serial.print("Khoảng cách đo được: ");
      //                    Serial.print(distance);
      //                    Serial.println(" cm");
      
                          if (distance < 20) {  
                              Stop();
                              Start = 0;
                              digitalWrite(LedG, LOW);
                              digitalWrite(LedR, HIGH);
                              delay(50);
                              digitalWrite(LedR, LOW);
                              delay(50);
                          } else {  
                              Start = 1;
                          }
                      }
                  } 
                  
                  if (Start == 1) {
                      Read_Sensor_Value();
                      Black_Line_Following(); 
                      Full_Black_Turn_Reset();
                  }
                  break;
                  
              case 2:
                  Stop();
                  Start = 0;
                  Turn_check = 0;
                  Turning = 0;
                  WhiteTurnRight = 0;     
                  WhiteTurnLeft = 0;
                  break;
              default:
                  // No active mode
                  break; 
          }
          break; 
        case 2:
          switch(currentMode){
              case 1:
                 SpeedMax = F_SpeedMax;
                 SpeedMin_1 = F_SpeedMin_1;
                 SpeedMin_2 = F_SpeedMin_2;
                 SpeedMin_3 = F_SpeedMin_3;
                 SpeedMin_4 = F_SpeedMin_4;
                 SpeedLech = F_SpeedLech;
                 Update_Motor_Speed();
                 break;
              case 2:
                 SpeedMax = S_SpeedMax;
                 SpeedMin_1 = S_SpeedMin_1;
                 SpeedMin_2 = S_SpeedMin_2;
                 SpeedMin_3 = S_SpeedMin_3;
                 SpeedMin_4 = S_SpeedMin_4;
                 SpeedLech = S_SpeedLech;
                 Update_Motor_Speed();
                 break;
          }
        break;
    }
}


void Black_Line_Following() {
//    if (WhiteTurnRight == 1) {
//        PORTC |= (1 << PC4);   // Turn ON LedG (GREEN, A4)
//        PORTB &= ~(1 << PB5);  // Turn OFF LedY (RED, 13)
//    } 
//    else if (WhiteTurnLeft == 1) {
//        PORTB |= (1 << PB5);   // Turn ON LedY (RED, Digital Pin 13)
//        PORTC &= ~(1 << PC4);  // Turn OFF LedG (GREEN, A4)
//    } 
//    else {
//        PORTB &= ~(1 << PB5);  // Turn OFF LedY (RED, 13)
//        PORTC &= ~(1 << PC4);  // Turn OFF LedG (GREEN, A4)
//    }
    PatternMatched = false;
    SensorPattern7 = (V_STL << 6) | (V_S1 << 5) | (V_S2 << 4) | (V_S3 << 3) | (V_S4 << 2) | (V_S5 << 1) | V_STR;
    switch (SensorPattern7) {
        case 0b0111111:   //Prepare to turn Right
        case 0b0011111:   
        case 0b0001111:
        case 0b0011101:   //Sperated line turn Right
        case 0b0110011:
        case 0b0100111:
            if (Turn_check == 1) {
                WhiteTurnRight = 1;
                WhiteTurnLeft = 0;
                Turning = 1;
                Run_Straight();
            }
            PatternMatched = true;
            break;

        case 0b1111110:    //Prepare to turn Left         
        case 0b1111100:
        case 0b1111000:
        case 0b1011100:   //Seperated line turn Left
        case 0b1001100:
        case 0b1011000:
            if (Turn_check == 1) {
                WhiteTurnLeft = 1;
                WhiteTurnRight = 0;
                Turning = 1;
                Run_Straight();
            }
            PatternMatched = true;
            break;
        case 0b0000000:   
            if (WhiteTurnRight == 1) {    //TurningRight
                Turning = 1;
                TwoWD_Turn_Right();
                Turn_check = 0;
            }
            if (WhiteTurnLeft == 1) {   //Turning Left
                Turning = 1;
                TwoWD_Turn_Left();
                Turn_check = 0;
            }
            PatternMatched = true;
            break;
        case 0b1111111:   //Full_Black_Reset_Turning_Conditions                
                inFullBlack = true;  // Set flag when in full black
                blackExitTime = millis();  // Start the timer
                PatternMatched = true;
                Run_Straight();
                break;
        case 0b0111110:   //Straight
            Turn_check = 0;
            Run_Straight();
            WhiteTurnRight = 0;
            WhiteTurnLeft = 0;
        case 0b0011100:
        case 0b1100011:   //Brige Straight
            Turn_check = 1;
            Run_Straight();
            Turning = 0;
            PatternMatched = true;
            break; 
        case 0b0011000:   // Left1
        case 0b0010000:   // Left2
        case 0b0111100:   //Big Line Left
//        case 0b1101111:   // Brige Left1
//        case 0b1100111:   //Brige Left2
            if (Turning == 0) {
                Turn_check = 1;
                Slight_Left_1();
                Turning = 0;
            }
            PatternMatched = true;
            break;
        case 0b0111000:   // Left3
//        case 0b1000111:   // Brige Left3
            if (Turning == 0) {
                Turn_check = 1;
                Slight_Left_2();
                Turning = 0;
            }
            PatternMatched = true;
            break;
        case 0b0110000:  // Left4
            if (Turning == 0) {          
               Turn_check = 1;
               Slight_Left_3();
               Turning = 0;
            }
            PatternMatched = true;
            break;
        case 0b0100000:  // Left5
            Turn_check = 1;
            Slight_Left_3();
            Turning = 0;
            WhiteTurnRight = 0;
            WhiteTurnLeft = 0;
            PatternMatched = true;
            break;
        case 0b1100000:  // Left6
            if (Turning == 0) {
                Turn_check = 1;
                Slight_Left_4();
                Turning = 0;
            }
            PatternMatched = true;
            break;
        case 0b1000000:   //Left7
            if (Turning == 0) {
              OneWD_Turn_Left();
              Turn_check = 1;
              Turning = 0;
            }
//            WhiteTurnRight = 0;
//            WhiteTurnLeft = 0;
            PatternMatched = true;
            break;            
        case 0b0000100:   // Right1            
        case 0b0001100:   // Right2   
        case 0b0011110:   //Big Line Right         
//        case 0b1111011:   // Brige Right1
//        case 0b1110011:   //Brige Right2
            if (Turning == 0) {
                Turn_check = 1;
                Slight_Right_1();
                Turning = 0;
            }
            PatternMatched = true;
            break;
        case 0b0001110:  // Right3
            if (Turning == 0) {
                Turn_check = 1;
                Slight_Right_2();
                Turning = 0;
            }
            PatternMatched = true;
            break;
        case 0b0000110:  // Right4
            if (Turning == 0) {
                Turn_check = 1;
                Slight_Right_3();
                Turning = 0;
            }
            PatternMatched = true;
            break;
        case 0b0000010:  // Right5
            Turn_check = 1;
            Slight_Right_3();
            Turning = 0;
            WhiteTurnRight = 0;
            WhiteTurnLeft = 0;
            PatternMatched = true;
            break;
        case 0b0000011:  // Right6
            if (Turning == 0) {
                Turn_check = 1;
                Slight_Right_4();
                Turning = 0;
            }      
            PatternMatched = true;    
            break;
        case 0b0000001:   //Right7
            if (Turning == 0) {
              OneWD_Turn_Right();
              Turn_check = 1;
              Turning = 0;
//              WhiteTurnRight = 0;
//              WhiteTurnLeft = 0;
            }
            PatternMatched = true;
            break;
        default:
//          Run_Straight();
            break;
    }            
    if (!PatternMatched) {
        SensorPattern5 = (V_S1 << 4) | (V_S2 << 3) | (V_S3 << 2) | (V_S4 << 1) | V_S5;
        switch (SensorPattern5) {
        case 0b10001:  // Sensors detect "10001"
            Run_Straight();
            Turn_check = 0; 
            Turning = 0;
            break;

        case 0b11001:  // Sensors detect "11001"
            Slight_Right_1();
            Turn_check = 0;
            Turning = 0;
            break;

        case 0b10011:  // Sensors detect "10011"
            Slight_Left_1();
            Turn_check = 0;
            Turning = 0;
            break;
        default:
//            Run_Straight();
            break;
    } 
  }
}
void Full_Black_Turn_Reset(){
  if (inFullBlack && millis() - blackExitTime > Full_Black_Reset_Time) {  // Wait 300ms after exiting full black
    WhiteTurnRight = 0;
    WhiteTurnLeft = 0;
    Turning = 0;
    inFullBlack = false;  // Reset flag
  }
}
void Update_Motor_Speed() {
    SpeedA = SpeedMax;
    SpeedB = SpeedMax + SpeedLech;
    SpeedMinA_1 = SpeedMin_1;
    SpeedMinB_1 = SpeedMin_1 + SpeedLech;
    SpeedMinA_2 = SpeedMin_2;
    SpeedMinB_2 = SpeedMin_2 + SpeedLech;
    SpeedMinA_3 = SpeedMin_3;
    SpeedMinB_3 = SpeedMin_3 + SpeedLech;
    SpeedMinA_4 = SpeedMin_4;
    SpeedMinB_4 = SpeedMin_4 + SpeedLech;
}
