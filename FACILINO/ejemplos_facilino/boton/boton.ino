/***   Global variables   ***/

/***   Function declaration   ***/

void setup()
{
  //Set button pin
  pinMode(2,INPUT);
  Serial.begin(9600);
}


void loop()
{
    if (digitalRead(2) == HIGH) {
      Serial.println("PULSADO");
     }else {
      Serial.println("NO PULSADO");
     }
    delay(100);
}

/***   Function definition   ***/
