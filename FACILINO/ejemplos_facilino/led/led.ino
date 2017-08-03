/***   Global variables   ***/

/***   Function declaration   ***/

void setup()
{
}


void loop()
{
    //Toggle built-in LED
    pinMode(13,INPUT);
    if (digitalRead(13) == HIGH) {
      pinMode(13,OUTPUT);
      digitalWrite(13,LOW);
     }else {
      pinMode(13,OUTPUT);
      digitalWrite(13,HIGH);
     }
    delay(500);
}

/***   Function definition   ***/
