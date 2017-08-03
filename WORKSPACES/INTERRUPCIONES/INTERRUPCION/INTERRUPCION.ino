int contador = 0;
int n = contador ;

void setup()
   {   Serial.begin(9600);
       attachInterrupt( 0, ServicioBoton, FALLING);
   }
void loop()
   {
       if (n != contador)
          {     Serial.println(contador);
                n = contador ;
          }
   }

void ServicioBoton() 
   {    contador++ ;
   }
