void setup() 
{
  int i = 0 ; // Inicializamos la variable i como un entero
  for ( i = 6 ; i < 14 ; i++)
    pinMode( i , OUTPUT) ;
}

void loop() 
{
  int i = 0 ; // Inicializamos la variable i como un entero
  
  for ( int i = 6 ; i < 14 ; i++) // Definimos la variable i sobre la marcha
  {
      digitalWrite( i , HIGH) ;
      delay (100) ;
      digitalWrite( i , LOW);
      delay (100) ;
  }
  
  for ( int i = 12 ; i >6 ; i--) // Definimos la variable i sobre la marcha
  {
     digitalWrite( i , HIGH) ;
     delay (100) ;
     digitalWrite( i , LOW);
     delay (100) ;
  }
}
