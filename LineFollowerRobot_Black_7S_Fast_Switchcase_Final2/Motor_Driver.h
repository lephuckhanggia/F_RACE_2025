void Run_Straight() 
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, SpeedA);
  analogWrite(EnB, SpeedB);
}
void Stop()
{
digitalWrite(In1, LOW);
digitalWrite(In2, LOW);
digitalWrite(In3, LOW);
digitalWrite(In4, LOW);
analogWrite(EnA, 0); 
analogWrite(EnB, 0);
}
void OneWD_Turn_Left()
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, 0 );
  analogWrite(EnB, SpeedB);
}
void TwoWD_Turn_Left()
{
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, 100 );
  analogWrite(EnB, 80  );
}
void Slight_Left_1()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, SpeedMinA_1);
  analogWrite(EnB, SpeedB);
}
void Slight_Left_2()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, SpeedMinA_2);
  analogWrite(EnB, SpeedB);
}
void Slight_Left_3()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, SpeedMinA_3);
  analogWrite(EnB, SpeedB);
}
void Slight_Left_4()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, SpeedMinA_4);
  analogWrite(EnB, SpeedB);
}

void OneWD_Turn_Right()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  analogWrite(EnA, SpeedA);
  analogWrite(EnB, 0 );
}
void TwoWD_Turn_Right()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(EnA, 75 );
  analogWrite(EnB, 95 );
}
void Slight_Right_1()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, SpeedA);
  analogWrite(EnB, SpeedMinB_1);
}
void Slight_Right_2()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, SpeedA);
  analogWrite(EnB, SpeedMinB_2);
}
void Slight_Right_3()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, SpeedA);
  analogWrite(EnB, SpeedMinB_3);
}
void Slight_Right_4()
{
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(EnA, SpeedA);
  analogWrite(EnB, SpeedMinB_4);
}
