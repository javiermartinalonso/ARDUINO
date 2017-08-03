//////////////////////////////////////////////////////////
int ledPin = 10; // define digital pin 10.
void setup()
{
  pinMode(ledPin, OUTPUT);// define pin with LED connected as output.
}
void loop()
{
  digitalWrite(ledPin, HIGH); // set the LED on.
  delay(1000); // wait for a second.
  digitalWrite(ledPin, LOW); // set the LED off.
  delay(1000); // wait for a second
}
//////////////////////////////////////////////////////////
