//////////////////////////////////////////////////////////
// set an array to store character of ―0‖
unsigned char Text[]={0x00,0x1c,0x22,0x22,0x22,0x22,0x22,0x1c};

void Draw_point(unsigned char x,unsigned char y)// point drawing function
{ clear_();
  digitalWrite(x+2, LOW);

   int fila = y+10;
        
          if (fila > 13)
          {
            fila = fila + 16;
          }
          
  digitalWrite(fila, HIGH);
  delay(1);
}

void show_num(void)// display function, call point drawing function
{
  unsigned char i,j,data;
  for(i=0;i<8;i++)
  {
    data=Text[i];

    for(j=0;j<8;j++)
    {
      if(data & 0x01)Draw_point(j,i);
        data>>=1;
     }
  }
}
/*
void setup()
{
  int i = 0 ;
  
  for(i=2;i<18;i++)
  {
    pinMode(i, OUTPUT);
  }
  
  clear_();
}
*/

 void setup()                                        
 {   
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(30, OUTPUT);
    pinMode(31, OUTPUT);
    pinMode(32, OUTPUT);
    pinMode(33, OUTPUT);     
    Serial.begin(9600);

    clear_();
 }
 
void loop()
{ 
  show_num();
}

void clear_(void)// clear screen
{
   for(int i=2;i<10;i++)
      digitalWrite(i, HIGH);

   for(int i=0;i<8;i++)
   {
     int fila = i + 10;
        
     if (fila > 13)
     {
        fila = fila + 16;
     }
          
      digitalWrite(fila, LOW);
   }
}
//////////////////////////////////////////////////////////
