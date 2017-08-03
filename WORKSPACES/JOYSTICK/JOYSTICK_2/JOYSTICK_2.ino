#include <Servo.h>              // Incluir la librería Servo
Servo servo1;                   // Crear un objeto tipo Servo llamado servo1
int angulo = 90 ;               // Empezamos en el centro
int salto = 3 ;                 // Controla el salto por movimiento
int Eje_X = A1 ;
int Eje_Y = A2 ;
int boton = 4  , LED = 12 ;

void setup()
{
  servo1.attach(6) ;  // Conectar servo1 al pin 6
  pinMode( boton, INPUT_PULLUP) ;
}

void loop()
{
  int p = analogRead(A1);
  
  if ( p < 400 )                    // Si la lectura es menor de 400
     angulo = angulo - salto ;    // disminuimos el angulo
  else if (p>600)                   // Si mayor de 600
     angulo = angulo + salto ;    // Aumentamos el angulo
     
  servo1.write(angulo);             // Y este es el que mueve el servo
  delay (50);                       // Este delay regula la velocidad del movimiento

  if ( ! digitalRead(boton))
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
}
