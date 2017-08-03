/***   Global variables   ***/

/***   Function declaration   ***/

void setup()
{
  //Analog sensor connected to A0
  pinMode(A0,INPUT);
  //Built-in LED connected to pin 13
  pinMode(13,OUTPUT);
}


void loop()
{
    if (analogRead(A0) <= 500) {
      digitalWrite(13,HIGH);
     }else {
      digitalWrite(13,LOW);
     }
    delay(100);

}

/***   Function definition   ***/
