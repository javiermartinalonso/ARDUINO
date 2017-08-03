#include <SoftwareSerial.h>
 int _bt_cmd=0;

/***   Global variables   ***/
SoftwareSerial blueToothSerial(2,4);

/***   Function declaration   ***/
void LEDMatrix_init(int cs, int din, int clk);
void writeRow(int cs, int din, int clk, int row, int data);
void maxAll (int cs, int din, int clk, int reg, int col);
void putByte (int din, int clk, int data);
void happy(int cs, int din, int clk);
void heart(int cs, int din, int clk);

void setup()
{
  //Set pins for bluetooth transmission/reception
  pinMode(2,INPUT);
  pinMode(4, OUTPUT);
  blueToothSerial.begin(9600);
  blueToothSerial.flush();
  //Set LED Matrix pins
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  //Initialize LED Matrix
  maxAll(10,12,11,11,7);
  maxAll(10,12,11,9,0);
  maxAll(10,12,11,12,1);
  maxAll(10,12,11,15,0);
  int i=0;
  for (i = 1; i <= 8; i++)
    maxAll(10,12,11,i,0);
  maxAll(10,12,11,10,15);

}


void loop()
{
    //Check received command
    if (blueToothSerial.available()>0  || _bt_cmd>0)
    {
      int cmd=blueToothSerial.read();

      if ((cmd==2)||(_bt_cmd==2)){
            happy(10,12,11);
      }
      if ((cmd==4)||(_bt_cmd==4)){
            heart(10,12,11);
      }
      if ((cmd==11)||(_bt_cmd==11)){
            _bt_cmd=11;
        tone(8,261,750);
        delay(750);
        noTone(8);
        delay(200);
      }
    }
}

/***   Function definition   ***/
void LEDMatrix_init(int cs, int din, int clk) {
  maxAll(cs,din,clk,11,7);
  maxAll(cs,din,clk,9,0);
  maxAll(cs,din,clk,12,1);
  maxAll(cs,din,clk,15,0);
  int i=0;
  for (i = 1; i <= 8; i++) {
    maxAll(cs,din,clk,i, 0);
  }
  maxAll(cs,din,clk,10,15);
}
void writeRow(int cs, int din, int clk, int row, int data) {
  digitalWrite(cs,LOW);
  putByte(din,clk,row);
  putByte(din,clk,data);
  digitalWrite(cs,LOW);
  digitalWrite(cs,HIGH);
}
void maxAll (int cs, int din, int clk, int reg, int col) {
  digitalWrite(cs,LOW);
  putByte(din,clk,reg);
  putByte(din,clk,col);
  digitalWrite(cs,LOW);
  digitalWrite(cs,HIGH);
}
void putByte (int din, int clk, int data) {
  byte i = 8;
  byte mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);
    digitalWrite(clk,LOW);
    if (data & mask){
      digitalWrite(din,HIGH);
    }
    else{
      digitalWrite(din,LOW);
    }
    digitalWrite(clk,HIGH);
    --i;
  }
}
void happy(int cs, int din, int clk) {
  writeRow(cs,din,clk,1, 12);
  writeRow(cs,din,clk,2, 24);
  writeRow(cs,din,clk,3, 48);
  writeRow(cs,din,clk,4, 48);
  writeRow(cs,din,clk,5, 48);
  writeRow(cs,din,clk,6, 48);
  writeRow(cs,din,clk,7, 24);
  writeRow(cs,din,clk,8, 12);
}
void heart(int cs, int din, int clk) {
  writeRow(cs,din,clk,1, 12);
  writeRow(cs,din,clk,2, 30);
  writeRow(cs,din,clk,3, 62);
  writeRow(cs,din,clk,4, 124);
  writeRow(cs,din,clk,5, 124);
  writeRow(cs,din,clk,6, 62);
  writeRow(cs,din,clk,7, 30);
  writeRow(cs,din,clk,8, 12);
}
