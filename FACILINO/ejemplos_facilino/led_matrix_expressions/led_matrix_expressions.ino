/***   Global variables   ***/

/***   Function declaration   ***/
void LEDMatrix_init(int cs, int din, int clk);
void writeRow(int cs, int din, int clk, int row, int data);
void maxAll (int cs, int din, int clk, int reg, int col);
void putByte (int din, int clk, int data);
void happy(int cs, int din, int clk);
void angry(int cs, int din, int clk);
void sad(int cs, int din, int clk);
void heart(int cs, int din, int clk);

void setup()
{
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
    happy(10,12,11);
    delay(1000);
    angry(10,12,11);
    delay(1000);
    sad(10,12,11);
    delay(1000);
    heart(10,12,11);
    delay(1000);
    heart(10,12,11);
    delay(1000);
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
void angry(int cs, int din, int clk) {
  writeRow(cs,din,clk,1, 2);
  writeRow(cs,din,clk,2, 68);
  writeRow(cs,din,clk,3, 36);
  writeRow(cs,din,clk,4, 16);
  writeRow(cs,din,clk,5, 16);
  writeRow(cs,din,clk,6, 36);
  writeRow(cs,din,clk,7, 68);
  writeRow(cs,din,clk,8, 2);
}
void sad(int cs, int din, int clk) {
  writeRow(cs,din,clk,1, 48);
  writeRow(cs,din,clk,2, 24);
  writeRow(cs,din,clk,3, 12);
  writeRow(cs,din,clk,4, 12);
  writeRow(cs,din,clk,5, 12);
  writeRow(cs,din,clk,6, 12);
  writeRow(cs,din,clk,7, 24);
  writeRow(cs,din,clk,8, 48);
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
