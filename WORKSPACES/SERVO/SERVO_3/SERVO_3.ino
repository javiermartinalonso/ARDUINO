#include <Servo.h>

Servo servo1;                         // Crear un objeto tipo Servo llamado servo1
Servo servo2;                         // Crear un objeto tipo Servo llamado servo2

int angulo = 0 ;

void setup()
{
  servo1.attach(9) ;             // Conectar servo1 al pin 9
  servo2.attach(10) ;           // Conectar servo1 al pin 10
}

void loop()
{
  for(angulo  = 0; angulo  <= 180; angulo  += 1)   //incrementa angulo 1 grado
  {
    servo1.write(angulo);
    servo2.write(angulo);    
    delay(25);
  }
  
  for(angulo  = 180; angulo  >=0; angulo  -=1 )    //decrementa angulo 1 grado
  {
    servo1.write(angulo);
    servo2.write(angulo);     
    delay(25);
  }
}
