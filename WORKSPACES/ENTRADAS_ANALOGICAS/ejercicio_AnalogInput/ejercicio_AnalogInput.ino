/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 10
 * LED cathode (short leg) attached to ground


 */

int sensorPin = A2;    // select the input pin for the potentiometer
int ledPin = 10;      // select the pin for the LED
int buzzerPin = 8;      // select the pin for buzzer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
   Serial.begin(9600);// set the baud rate at 9600 to match the software set up. When connected to a specific device, (e.g. bluetooth), the baud rate needs to be the same with it.
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);

    pinMode(buzzerPin, OUTPUT);


}

void loop() {

  unsigned int i;//define variable
        
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);

  Serial.println(sensorValue);// display value

  switch (sensorValue) {
    case 0 ... 256:
        // turn the ledPin off:
        digitalWrite(ledPin, LOW);
        digitalWrite(buzzerPin, LOW);
      break;
    case 257 ... 512:
        digitalWrite(ledPin, HIGH);
        //digitalWrite(buzzerPin, HIGH);        
        // stop the program for <sensorValue> milliseconds:
        //delay(sensorValue);

        for(i=0;i<80;i++)// output a frequency sound
        { 
          digitalWrite(buzzerPin,HIGH);// sound
          delay(1);//delay1ms
          digitalWrite(buzzerPin,LOW);//not sound
          delay(1);//ms delay
        }
      break;
    default: 
        // turn the ledPin on
        digitalWrite(ledPin, HIGH);
        digitalWrite(buzzerPin, HIGH);
        // stop the program for <sensorValue> milliseconds:
        delay(sensorValue);
        // turn the ledPin off:
        digitalWrite(ledPin, LOW);
        digitalWrite(buzzerPin, LOW);        
        // stop the program for for <sensorValue> milliseconds:
        delay(sensorValue);
    break;
  }
}
