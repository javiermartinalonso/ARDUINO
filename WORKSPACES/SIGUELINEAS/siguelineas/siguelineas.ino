const int sensorPin = 3;     // el número del pin del sensor
const int ledPin =  13;      // el número del pin del LED
int sensorState = 0;         // variable para leer el estado del sensor
void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(sensorPin, INPUT); }
void loop(){
  // read the state of the sensor value:
  sensorState = digitalRead(sensorPin);
  // if the sensorState is HIGH:
  if (sensorState == HIGH) {     
     digitalWrite(ledPin, HIGH);  
  } 
  else {digitalWrite(ledPin, LOW); 
  }}  
