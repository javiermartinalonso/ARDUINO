int LED = 10 ; int boton = 2 ;
bool estado = false ;
void setup()
{
   pinMode( LED, OUTPUT) ;
   pinMode( boton , INPUT_PULLUP) ;
   digitalWrite(LED , LOW) ; // Apagamos el LED al empezar
}
void loop()
{ 
    bool  valor =  digitalRead(boton) ;                 //leemos el botón: false  =  LOW
    if ( valor == false )                               // esto es que han pulsado el botón
    {
        estado = ! estado ;                       // cambiamos el estado
        digitalWrite(LED, estado) ;            // escribimos el nuevo valor
        delay(250) ;
    }
}
