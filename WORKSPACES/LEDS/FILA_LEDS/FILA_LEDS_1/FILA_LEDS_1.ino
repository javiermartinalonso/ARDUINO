void setup() 
{
  int i = 0 ; // Inicializamos la variable i como un entero
  for ( i = 6 ; i < 14 ; i++)
    pinMode( i , OUTPUT) ;
}

void loop() 
{
  int i = 0 ; // Inicializamos la variable i como un entero
  
  for ( i = 6 ; i < 14 ; i++)
  {
    digitalWrite( i , HIGH) ;
    delay (100) ;
    digitalWrite( i , LOW);
    delay (100) ;
  }
}
