//**********************************************************************************
//Ejemplo de como usar RFID RC522
//**********************************************************************************

#include <SPI.h>
#include <RFID.h>

RFID rfid(10,5); 

int TarjetaUno[5];

void setup()
{ 
  Serial.begin(9600);
  SPI.begin(); 
  rfid.init(); 
  
  TarjetaUno[0] = 132;
  TarjetaUno[1] = 86;
  TarjetaUno[2] = 118;
  TarjetaUno[3] = 26;
  TarjetaUno[4] = 190;
  
}

void loop()
{ 
 
    if (rfid.isCard()) {
      Serial.println("DENTRO");
          if (rfid.readCardSerial()) { 
            Serial.println(rfid.serNum[0]);
            Serial.println(rfid.serNum[1]);
            Serial.println(rfid.serNum[2]);
            Serial.println(rfid.serNum[3]);
            Serial.println(rfid.serNum[4]);
            
                if (rfid.serNum[0] == TarjetaUno[0] && rfid.serNum[1] == TarjetaUno[1] && rfid.serNum[2] == TarjetaUno[2] && rfid.serNum[3] == TarjetaUno[3] && rfid.serNum[4] == TarjetaUno[4]) 
                {
                    Serial.println("La tarjeta es valida");
                   delay(500);
                }   
                 else
                {
                     Serial.println("La tarjeta no es valida");
                    delay(500);
                 } 
          }
    }  
    rfid.halt();
}
