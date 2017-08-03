int ENA=5;
int IN1=6;
int IN2=7;
int IN3=8;
int IN4=9;
int ENB=10;

void setup()
{
  for (int i = 5; i <11; i ++)
  {
    pinMode(i, OUTPUT);  
  }
}

void loop()
{
  // rotate CW
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);  
  analogWrite(ENA,200);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,200);
  delay(1000);
  // pause for 1S
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  delay(1000);
  // rotate CCW
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,100);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENB,100);
  delay(1000);
  // pause for 1S
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  delay(1000);
}
