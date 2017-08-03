// Parar servo (trucado)
// Envia el dato de 90 grados, posicin parado en un servo trucado
// Por Iñigo Zuluaga
// www.txapuzas.blogspot.com
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo.write(90);               // tell servo to go to position in variable 'pos'
} 
 
 
void loop() 
{   
} 
