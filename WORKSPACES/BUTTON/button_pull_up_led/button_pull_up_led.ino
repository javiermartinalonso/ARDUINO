int LED = 10 ;
int LED_INTERNO = 13 ;
int boton = 2;

void setup()
{
     pinMode( LED, OUTPUT) ; // LED como salida
     pinMode( LED_INTERNO, OUTPUT) ; // LED como salida
     pinMode( boton  , INPUT) ;            //botón  como entrada
}

 void loop()
{
    int valor = digitalRead(boton) ;          // leemos el valor de boton en valor
    digitalWrite( LED, valor) ; 
    digitalWrite( LED_INTERNO, valor) ; 
}
