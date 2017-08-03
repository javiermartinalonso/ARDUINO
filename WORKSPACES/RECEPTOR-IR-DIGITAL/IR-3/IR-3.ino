#include <IRremote.h>          //including libraries of remote control
const int RECV_PIN=12;   //pin 12 of IR remoter control receiver
IRrecv irrecv(RECV_PIN);      //defining pin 12 of IR remoter control
decode_results results;         //cache of decode of IR remoter control


void setup() 
{ 
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
} 

void loop() 
{  
 if (irrecv.decode(&results)) {
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }

      Serial.println(results.value, HEX);
  irrecv.resume(); // Receive the next value 
 }
    


 
  //delay(10);
}
