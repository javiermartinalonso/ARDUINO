//////////////////////////////////////////////////////////
#include <Servo.h>
// define a header file. Special attention here, you can call the servo function directly from Arduino's software menu bar Sketch>Importlibrary>Servo, 
//or input #include <Servo.h>. Make sure there is a space between #include and <Servo.h>. Otherwise, it will cause compile error.
Servo myservo;// define servo variable name

int val;

void setup()
{
  myservo.attach(9);// select servo pin(9 or 10)
  Serial.begin(9600);// connect to serial port, set baud rate at ―9600‖
  Serial.println("servo=o_seral_simple ready" ) ;
}

void loop()
{
  val=Serial.read();// read serial port value
  if (Serial.available())
  {
      myservo.write(val);// set rotate angle of the motor

    Serial.print("moving servo to ");
    Serial.print(val);
    Serial.println();
  }

}
//////////////////////////////////////////////////////////
