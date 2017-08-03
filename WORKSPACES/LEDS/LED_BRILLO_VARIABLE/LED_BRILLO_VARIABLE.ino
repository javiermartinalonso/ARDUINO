int ledPin = 10; // define digital pin 10.

void setup()                                     
{ 
   pinMode( ledPin, OUTPUT) ;  
}

void loop()
{
  /*
   * Aquí aprovecho ( por pura vagancia) para hacer el ciclo de subir y bajar el brillo del LED con un único bucle. La función abs(num), 
   * devuelve el valor absoluto o sin signo de un número num, y por eso mientras que i viaja de -255 a 255, abs(i) 
   * va de 255 a 0 y vuelta a subir a 255. ¿Que os parece el truco?
   */
   for ( int i= -255 ; i<255 ; i++)
   {
       analogWrite (ledPin, abs(i)) ;
       delay( 10);
   }
}
