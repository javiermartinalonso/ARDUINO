#include <Servo.h>          // Incluir la librería Servo
Servo servo1;               // Crear un objeto tipo Servo llamado servo1
Servo servo2;               // Crear un objeto tipo Servo llamado servo2

int angulo = 0 ;

void setup()
{
   servo1.attach(9) ;  // Conectar servo1 al pin 9
   servo1.attach(10) ;  // Conectar servo1 al pin 10
}

void loop()
{
  angulo  = map( analogRead(A0), 0, 1024, 0, 180);
  servo1.write(angulo);
  servo2.write(angulo);
  delay(250);
}
