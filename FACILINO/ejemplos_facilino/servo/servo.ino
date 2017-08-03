#include <Servo.h>

Servo servo;

/***   Global variables   ***/

/***   Function declaration   ***/

void setup()
{
  //Attach servo to pin 3
  servo.attach(3);
}


void loop()
{
    //Alternate servo position
    servo.write(135);
    delay(2000);
    servo.write(45);
    delay(2000);
}

/***   Function definition   ***/
