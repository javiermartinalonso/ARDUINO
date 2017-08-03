/*
  CORAZON
  simule el latido de un corazón La idea básica es hacer que la luz parpadee al ritmo de los latidos del corazón, es decir, dos parpadeos rápidos seguidos de una pausa larga.
 */


void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);  
  delay(500);              
  digitalWrite(13, LOW); 
  delay(500);   
  digitalWrite(13, HIGH);  
  delay(500);             
  digitalWrite(13, LOW); 
  delay(1000);              
}
