void setup() {
  for (int i =9 ; i<12 ; i++)
    pinMode(i, OUTPUT);
}

void loop() 
{
  //Color(255 ,0 ,0) ;
  //delay(500); 
  //Color(0,255 ,0) ;
  //delay(500);
  //Color(0 ,0 ,255) ;
  //delay(500);
  //Color(0,0,0);
  //delay(1000);
//Color(128,255,0);
 Color(random(255), random(255), random(255)) ;
  delay(500);
}

void Color(int R, int G, int B)
{     
    analogWrite(11 , R) ;   // Red    - Rojo
    analogWrite(9, G) ;   // Green - Verde
    analogWrite(10, B) ;   // Blue - Azul
}
