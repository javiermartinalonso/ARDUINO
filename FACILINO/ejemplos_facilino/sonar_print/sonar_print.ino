/***   Global variables   ***/

/***   Function declaration   ***/
long US_init(int trigger_pin, int echo_pin);
long distance(int trigger_pin, int echo_pin);

void setup()
{
  //Set sonar pins
  pinMode( 7 , INPUT );
  pinMode( 13 , OUTPUT );
  //Enable serial communication through pins 0 and 1 (USB)
  Serial.begin(9600);
}


void loop()
{
    Serial.println(distance(13,7));
    delay(60);
}

/***   Function definition   ***/
long US_init(int trigger_pin, int echo_pin)
{
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  long microseconds = pulseIn(echo_pin ,HIGH);
  return microseconds;
}
long distance(int trigger_pin, int echo_pin)
{
  long microseconds = US_init(trigger_pin, echo_pin);
  long distance;
  distance = microseconds/29/2;
  if (distance == 0){
    distance = 999;
  }
  return distance;
}
