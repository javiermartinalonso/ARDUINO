#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 53

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key; 
// Init array that will store new NUID 
byte nuidPICC[3];

int ledPin = 7; // define digital pin 10.

void setup() 
{ 
    pinMode(ledPin, OUTPUT);// define pin with LED connected as output.
    
  Serial.begin(9600);
  SPI.begin();          // Init SPI bus
  rfid.PCD_Init();      // Init MFRC522 

  for (byte i = 0; i < 6; i++) 
  {  
    key.keyByte[i] = 0xFF;
  }

  Serial.println(F("This code scan the MIFARE Classsic NUID."));
  Serial.print(F("Using the following key:"));
  printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
}



// ------------------------------------------------------------------
void printHex(byte *buffer, byte bufferSize) 
{
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

void printDec(byte *buffer, byte bufferSize) 
{
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
//------------------------------------------------------------------

void loop() {

  // Buscamos tarjetas
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // SI la encuentra la leemos
  if ( ! rfid.PICC_ReadCardSerial())
    return;

    digitalWrite(ledPin, HIGH); // set the LED on.
    delay(100); // wait for a second.
    
  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) 
      {
        Serial.println(F("Your tag is not of type MIFARE Classic."));
        return;
      }

  if (rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3] ) 
    {
        Serial.println(F("A new card has been detected."));
    
        Serial.println(F("The NUID tag is:"));
        Serial.print(F("In hex: "));
        printHex(rfid.uid.uidByte, rfid.uid.size);
        Serial.println();
        Serial.print(F("In dec: "));
        printDec(rfid.uid.uidByte, rfid.uid.size);
        Serial.println();
     
       rfid.PICC_HaltA();
       rfid.PCD_StopCrypto1();
    }

        digitalWrite(ledPin, LOW); // set the LED on.
    
    delay(600);
}



