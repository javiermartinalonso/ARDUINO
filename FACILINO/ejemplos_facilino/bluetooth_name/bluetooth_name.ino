#include <SoftwareSerial.h>
 int _bt_cmd=0;

/***   Global variables   ***/
SoftwareSerial blueToothSerial(2,4);

/***   Function declaration   ***/

void setup()
{
  //Set pins for bluetooth transmission/reception
  pinMode(2,INPUT);
  pinMode(4, OUTPUT);
  blueToothSerial.begin(9600);
  blueToothSerial.flush();
  //Set robot name
  String name = "DYOR";
  String str = "AT+NAME"+name+"\r\n";
  blueToothSerial.write(str.c_str());
}


void loop()
{


}

/***   Function definition   ***/
