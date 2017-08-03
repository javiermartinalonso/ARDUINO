//////////////////////////////////////////////////////////
byte sensorPin = 3;
byte indicator = 13;
int buzzer=8;// initialize digital IO pin that controls the buzzer

void setup()
{
  pinMode(sensorPin,INPUT);
  pinMode(indicator,OUTPUT);
  pinMode(buzzer,OUTPUT);// set pin mode as ―output‖
  Serial.begin(9600);
}
void loop()
{
  byte state = digitalRead(sensorPin);
  digitalWrite(indicator,state);
  
  if(state == 1)
  {
    Serial.println("Somebody is in this area!");

    digitalWrite(buzzer, HIGH); // produce sound
    delay(1000);
    digitalWrite(buzzer, LOW); // produce sound
    delay(1000);
  }
  else if(state == 0)
  {
    Serial.println("No one!");  
    digitalWrite(buzzer, LOW); // produce sound
  }

  delay(250);
}
//////////////////////////////////////////////////////////
