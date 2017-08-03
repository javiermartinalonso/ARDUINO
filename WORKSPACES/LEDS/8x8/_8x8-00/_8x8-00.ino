void setup() 
   {   
        //for (int j=2; j<14; j++)
        //  pinMode(j, OUTPUT);


        
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
   }

void loop()
   {
        for (int j=2; j<10; j++)
           {
              digitalWrite(j, HIGH);     //Levantamos la columna
              for (int k= 10 ; k<18 ; k++)
                 {
                  if (k<=13)
                  {
                     digitalWrite(k, LOW);   //Encendemos el punto
                     delay(2500);
                     digitalWrite(k, HIGH);  //Apagamos el punto
                  }
                  else
                  {
                     int l = k + 16;
                     digitalWrite(l, LOW);   //Encendemos el punto
                     delay(2500);
                     digitalWrite(l, HIGH);  //Apagamos el punto
                    
                  }
                 }
              digitalWrite(j, LOW);                //Bajamos la columna
           }
    }
