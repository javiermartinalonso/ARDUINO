int LED = 10 ; int boton = 2 ;
  bool estado = true ;
  bool estado_anterior = true ;

void setup()
{ 
     pinMode(boton, INPUT_PULLUP);        //Hemos eliminado R3 
     pinMode(LED, OUTPUT);
}

void loop()
{
     estado = digitalRead(boton);
     if (estado != estado_anterior)      //hay cambio : Han pulsado o soltado
      {
         if (estado == LOW)            //Al pulsar botón cambiar LED, pero no al soltar
               digitalWrite(LED, !digitalRead(LED));
         estado_anterior = estado ;     // Para recordar el ultimo valor
      }
 }
