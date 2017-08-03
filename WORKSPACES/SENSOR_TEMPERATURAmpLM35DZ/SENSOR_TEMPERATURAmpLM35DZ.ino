int Sensor = 0 ; // Prog_15_1 
     int umbral = 25 ;
     
     void setup()
        {
            Serial.begin(9600);
            pinMode(11,OUTPUT);
        }
     void loop()
       {
            int lectura = analogRead(Sensor);
            float voltaje = 5.0 /1024 * lectura ; // Atencion aqui
            // float temp = voltaje * 100 ; para el LM35DZ 
            float temp = voltaje * 100 ; Serial.println(temp) ; 
            if (temp >= umbral) 
                digitalWrite(11, HIGH) ; 
            else digitalWrite(11,LOW); 
                delay(1000); }
