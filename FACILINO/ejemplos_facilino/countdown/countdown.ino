/***   Global variables   ***/

/***   Function declaration   ***/
void LEDMatrix_init(int cs, int din, int clk);
void writeRow(int cs, int din, int clk, int row, int data);
void maxAll (int cs, int din, int clk, int reg, int col);
void putByte (int din, int clk, int data);
void expression(int cs, int din, int clk, int col1, int col2, int col3, int col4, int col5, int col6, int col7, int col8);
void uno (int tiempo);
void tres (int tiempo);
void cinco (int tiempo);
void sierte (int tiempo);
void nueve (int tiempo);
void cero (int tiempo);
void dos (int tiempo);
void cuatro (int tiempo);
void seis (int tiempo);
void ocho (int tiempo);
void diez (int tiempo);
void o (int tiempo);
void oo (int tiempo);
void ooo (int tiempo);
void oooo (int tiempo);

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

  // Switch of the LED Matrix
  expression(10,12,11,0,0,0,0,0,0,0,0);
  //Numbers
  diez(1000);
  nueve(1000);
  ocho(1000);
  sierte(1000);
  seis(1000);
  cinco(1000);
  cuatro(1000);
  tres(1000);
  dos(1000);
  uno(1000);
  cero(1000);
  //Growing square
  o(200);
  oo(200);
  ooo(200);
  //Switch off the LED Matrix
  expression(10,12,11,0,0,0,0,0,0,0,0);

}


void loop()
{


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
void expression(int cs, int din, int clk, int col1, int col2, int col3, int col4, int col5, int col6, int col7, int col8) {
  writeRow(cs,din,clk,1, col1);
  writeRow(cs,din,clk,2, col2);
  writeRow(cs,din,clk,3, col3);
  writeRow(cs,din,clk,4, col4);
  writeRow(cs,din,clk,5, col5);
  writeRow(cs,din,clk,6, col6);
  writeRow(cs,din,clk,7, col7);
  writeRow(cs,din,clk,8, col8);
}
void uno (int tiempo) {
  expression(10,12,11,0,4,134,255,255,128,0,0);
  delay(tiempo);
 }
void tres (int tiempo) {
  expression(10,12,11,0,66,195,129,153,255,102,0);
  delay(tiempo);
 }
void cinco (int tiempo) {
  expression(10,12,11,7,143,137,137,137,137,249,113);
  delay(tiempo);
 }
void sierte (int tiempo) {
  expression(10,12,11,131,195,97,49,25,13,7,3);
  delay(tiempo);
 }
void nueve (int tiempo) {
  expression(10,12,11,78,223,145,145,145,145,255,126);
  delay(tiempo);
 }
void cero (int tiempo) {
  expression(10,12,11,126,255,129,129,129,129,255,126);
  delay(tiempo);
 }
void dos (int tiempo) {
  expression(10,12,11,128,198,227,177,153,143,134,128);
  delay(tiempo);
 }
void cuatro (int tiempo) {
  expression(10,12,11,24,28,22,147,255,255,144,0);
  delay(tiempo);
 }
void seis (int tiempo) {
  expression(10,12,11,126,254,139,137,137,137,248,112);
  delay(tiempo);
 }
void ocho (int tiempo) {
  expression(10,12,11,118,255,137,137,137,137,255,118);
  delay(tiempo);
 }
void diez (int tiempo) {
  expression(10,12,11,144,248,248,128,112,136,136,112);
  delay(tiempo);
 }
void o (int tiempo) {
  expression(10,12,11,0,0,36,24,24,36,0,0);
  delay(tiempo);
 }
void oo (int tiempo) {
  expression(10,12,11,0,66,60,36,36,60,66,0);
  delay(tiempo);
 }
void ooo (int tiempo) {
  expression(10,12,11,129,126,66,66,66,66,126,129);
  delay(tiempo);
 }
void oooo (int tiempo) {
  expression(10,12,11,255,129,129,129,129,129,129,255);
  delay(tiempo);
 }
