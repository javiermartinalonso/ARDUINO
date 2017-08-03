#include <Servo.h>

Servo servo;

/***   Global variables   ***/

/***   Function declaration   ***/

void setup()
{
  //Attach servo to pin 5
  servo.attach(5);
}


void loop()
{
    int speed=0;
    //Increasing speed forward
    for (speed = 0; speed <= 100; speed++) {
      servo.write(((45-90)*speed/100)+90);  //45 could be replaced by 25
      delay(100);
    }
    //Stop servo
    servo.write(90);
    delay(1000);
    //Full forward speed
    servo.write(0);
    delay(1000);
    //Stop servo
    servo.write(90);
    delay(1000);
    //Increasing speed backward
    for (speed = 0; speed <= 100; speed++) {
      servo.write(((135-90)*speed/100)+90);  //135 could be replaced by 155
      delay(100);
    }
    //Stop servo
    servo.write(90);
    delay(1000);
    //Full backward speed
    servo.write(180);
    delay(1000);
    //Stop servo
    servo.write(90);
    delay(1000);
}

/***   Function definition   ***/
