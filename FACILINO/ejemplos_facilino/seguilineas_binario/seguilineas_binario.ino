#include <Servo.h>

Servo servos[13];

/***   Global variables   ***/

int _white=800;
int _black=30;

/***   Function declaration   ***/
void move_base(int l, int r, int speed, int advance, int turn);

void setup()
{
  servos[9].attach(9);
  servos[5].attach(5);
    move_base(9,5,0,0,0);
  _white=30;
  _black=730;

}


void loop()
{
    if(analogRead(A0)<(0.4*(_black-_white)+_white))
    {
    }
    else if(analogRead(A0)<(0.6*(_black-_white)+_white))
    {
    }
    else
    {  move_base(9,5,40,0,-100);

    }

}

/***   Function definition   ***/
void move_base(int l, int r, int speed, int advance, int turn)
{
servos[l].write(90-(int)(65.0*(float)(speed*(advance+turn))/10000.0));
servos[r].write(90+(int)(65.0*(float)(speed*(advance-turn))/10000.0));
delay(20);
};
