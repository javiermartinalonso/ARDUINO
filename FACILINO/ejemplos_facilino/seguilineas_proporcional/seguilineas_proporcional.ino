#include <Servo.h>

Servo servos[13];

/***   Global variables   ***/

int _white=800;
int _black=30;

/***   Function declaration   ***/
void move_base(int l, int r, int speed, int advance, int turn);
int follow(int light, int gain);

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
    move_base(9,5,50,50,follow(analogRead(A0),10));

}

/***   Function definition   ***/
void move_base(int l, int r, int speed, int advance, int turn)
{
servos[l].write(90-(int)(65.0*(float)(speed*(advance+turn))/10000.0));
servos[r].write(90+(int)(65.0*(float)(speed*(advance-turn))/10000.0));
delay(20);
};
int follow(int light, int gain)
{
  return (int)(((float)(gain)/100.0)*((float)((_white-_black)/2+_black)-(float)(light)));
}
