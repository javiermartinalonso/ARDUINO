////////#include <LiquidCrystal_I2C.h>        //including libraries of I2C-LCD1602 liquid crystal 
//#include <Wire.h>                           //including libraries of I2C

#include <IRremote.h>                         //including libraries of remote control
#define RECV_PIN 12                           //pin 12 of IR remoter control receiver
IRrecv irrecv(RECV_PIN);                      //defining pin 12 of IR remoter control
decode_results results;                       //cache of decode of IR remoter control

#define IR_Go                 0x00ff629d      //going forward
#define IR_Back               0x00ffa857      //going backward
#define IR_Left               0x00ff22dd      //turning left
#define IR_Right              0x00ffc23d      //turning right
#define IR_Stop               0x00ff02fd      //OK stop 
#define IR_Servo_L            0x00ff6897      // 1 servo turning left
#define IR_Servo_R            0x00ff9867      // 2 servo turning right
#define IR_Speed_UP           0x00ffb04f      // 3 increasing speed
#define IR_Speed_DOWN         0x00ff7a85      // 6 decreasing speed

#define IR_LineTracking       0x00ff52ad      // # function of line tracking 
#define IR_Self_Control       0x00ff4ab5      // 0 ultrasonic distance detecting
#define IR_IR_Control         0x00ff42bd      // * mando control / quitting from remote control
#define IR_Bluetooth_Control  0x00ff38c7      // 8 bluetooth

#define IR_ESC                0x00ff10ef      // 7 quitting from remote control

/*
0x00ff30cf      // 4

0x00ff18e7      // 5

0x00ff5aa5         //  9


*/

#define SensorLeft    6             //sensor left pin of line tracking module 
#define SensorMiddle  9             //sensor middle pin of line tracking module
#define SensorRight   11            //sensor right pin of line tracking module
unsigned char SL;                   //state of left sensor of line tracking module
unsigned char SM;                   //state of middle sensor of line tracking module
unsigned char SR;                   //state of right sensor of line tracking module

//ULTRASONIDOS
int inputPin=A0;                    // ultrasonic module   ECHO to A0
int outputPin=A1;                   // ultrasonic module  TRIG to A1


unsigned char Bluetooth_val;                // ultrasonic module  TRIG to A1


////////LiquidCrystal_I2C lcd(0x27,16,2);   //defining liquid crystal

#define Lpwm_pin  5                           //pin of controlling speed   ---- ENA of motor driver board

int pinLB=2;                                  //pin of controlling turning ---- IN1 of motor driver board
int pinLF=4;                                  //pin of controlling turning ---- IN2 of motor driver board
int pinRB=7;                                  //pin of controlling turning ---- IN3 of motor driver board
int pinRF=8;                                  //pin of controlling turning ---- IN4 of motor driver board

#define Rpwm_pin  10                          //pin of controlling speed   ---- ENB of motor driver board

unsigned char Lpwm_val = 250;                  //initialized left wheel speed at 250
unsigned char Rpwm_val = 250;                  //initialized right wheel speed at 250

int Car_state=0;                              //the working state of car
int servopin=3;                               //defining digital port pin 3, connecting to signal line of servo motor
int myangle;                                  //defining variable of angle
int pulsewidth;                               //defining variable of pulse width
unsigned char angleServoUltrasonic=60;                     //initialized angle of motor at 60°


void Sensor_IO_Config()     //IO initialized function of three line tracking , all setting at input
{
  pinMode(SensorLeft,INPUT);
  pinMode(SensorMiddle,INPUT);
  pinMode(SensorRight,INPUT);
}

void Sensor_Scan(void) //function of reading-in signal of line tracking module 
{
  SL = digitalRead(SensorLeft);
  SM = digitalRead(SensorMiddle);
  SR = digitalRead(SensorRight);
}

void servopulse(int servopin,int myangle) //defining a function of pulse
{
  pulsewidth=(myangle*11)+500; //converting angle into pulse width value at 500-2480 
  digitalWrite(servopin,HIGH); //increasing the level of motor interface to upmost
  delayMicroseconds(pulsewidth); //delaying microsecond of pulse width value
  digitalWrite(servopin,LOW); //decreasing the level of motor interface to the least
  delay(20-pulsewidth/1000);
}

void Set_servopulse(int set_val)
{
  for(int i=0;i<=10;i++)  //giving motor enough time to turn to assigning point
    servopulse(servopin,set_val); //invokimg pulse function
}

void M_Control_IO_config(void)
{
  pinMode(pinLB,OUTPUT); // /pin 2
  pinMode(pinLF,OUTPUT); // pin 4
  pinMode(pinRB,OUTPUT); // pin 7
  pinMode(pinRF,OUTPUT);  // pin 8
  pinMode(Lpwm_pin,OUTPUT);  // pin 11 (PWM) 
  pinMode(Rpwm_pin,OUTPUT);  // pin10(PWM)   
}

//function of setting speed
void Set_Speed(unsigned char Left,unsigned char Right) 
{
  analogWrite(Lpwm_pin,Left);
  analogWrite(Rpwm_pin,Right);
}



//Acelerar
void Acelerate() 
{

// ajuste para prevenir el zumbido de motores a muy baja velocidad
//if motorSpeed1 < 8) motorSpeed1 = 0;
//if motorSpeed2 < 8) motorSpeed2 = 0;
  
  for (int i = 0; i < 256; i++)
  {
    analogWrite(Lpwm_pin,i);
    analogWrite(Rpwm_pin,i);
  }
}

//  going forward
void advance()    
{
  digitalWrite(pinRB,LOW);  // making motor move towards right rear
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinLB,LOW);  // making motor move towards left rear
  digitalWrite(pinLF,HIGH); 
  
  Car_state = 1; 
  show_state();   
}

//turning right(dual wheel)
void turnR()        
{
  digitalWrite(pinRB,LOW);  //making motor move towards right rear
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinLB,HIGH);
  digitalWrite(pinLF,LOW);  //making motor move towards left front
  
  Car_state = 4;
  show_state();
}

//turning left(dual wheel)    
void turnL()         
{
  digitalWrite(pinRB,HIGH);
  digitalWrite(pinRF,LOW );   //making motor move towards right front
  digitalWrite(pinLB,LOW);    //making motor move towards left rear
  digitalWrite(pinLF,HIGH);
  
  Car_state = 3;
  show_state();
}   

//stop
void stopp()        
{
  digitalWrite(pinRB,HIGH);
  digitalWrite(pinRF,HIGH);
  digitalWrite(pinLB,HIGH);
  digitalWrite(pinLF,HIGH);
  
  Car_state = 5;
  show_state();
}

//back up
void back()         
{
  digitalWrite(pinRB,HIGH);  //making motor move towards right rear     
  digitalWrite(pinRF,LOW);
  digitalWrite(pinLB,HIGH);  //making motor move towards left rear
  digitalWrite(pinLF,LOW);
  
  Car_state = 2;
  show_state() ;    
}


void show_state(void)
{
  //lcd.setCursor(0, 1);

  switch(Car_state)
  {
    case 1:
      //lcd.print(" Go  ");
      Serial.print(" \r\n GO");
    break;
    
    case 2:
      //lcd.print("Back ");
      Serial.print(" \r\n Back");
    break;
    
    case 3:
      //lcd.print("Left ");
      Serial.print(" \r\n Left");
    break;
    
    case 4:
      //lcd.print("Right");
      Serial.print(" \r\n Right");
    break;
    
    case 5:
      //lcd.print("Stop ");
      Serial.print(" \r\n Stop"); 
    break;
    
    default:
    break;
  }
}

/*              
void LCD1602_init(void)            //including initialized function of liquid crystal
{
  lcd.init();  //invoking initialized function of LCD in LiquidCrystal_I2C.h  
  delay(10);  //delaying for 10 millisecond
  lcd.backlight(); //open backlight of LCD1602
  lcd.clear();    //clear screen
}  
*/
void Show_V(unsigned char V)
{
     //lcd.setCursor(11, 0);
     //lcd.print("V=    ");
     //lcd.setCursor(13, 0);
     //lcd.print(V,DEC);
     
     Serial.print("\n Speed = ");
     Serial.print(V,DEC); 
}

void showAngleServoUltrasonic(unsigned char asu)
{
     //lcd.setCursor(6,1);
     //lcd.print("C=    ");
     //lcd.setCursor(8, 1);
     //lcd.print(asu,DEC);
     
     Serial.print("\n AngleServoUltrasonic = ");
     Serial.print(asu,DEC); 
}

void LineTracking_Mode(void) //function of line tracking 
{

     Serial.print("\n LineTracking_Mode = function of line tracking");
  
  //lcd.setCursor(0, 0);  //setting cursor in the first row and column
  //lcd.print("LineTracking_Mode           ");
  Sensor_Scan();
  
  if (SM == HIGH)// middle sensor in black area
  {
    if (SL == LOW & SR == HIGH) // black on left, white on right, turn left
    {
      turnR();
    }
    else if (SR == LOW & SL == HIGH) // white on left, black on right, turn right
    {
      turnL();
    }
    else // white on both sides, going forward
    {
      advance();
    }
  }
  else // middle sensor on white area
  {
    if (SL== LOW & SR == HIGH)// black on left, white on right, turn left
    {
      turnR();
    }
    else if (SR == LOW & SL == HIGH) // white on left, black on right, turn right
    {
      turnL();
    }
    else // all white, stop
    {
      back();
      
      delay(100);
      
      stopp() ; 
    }
  }
}


void Self_Control(void)//self-going, ultrasonic obstacle avoidance
{

  Serial.print("\n Self_Control = ultrasonic obstacle avoidance");
      
  int H;
  
  //lcd.setCursor(0, 0);  //setting cursor in the first row and column
  //lcd.print("Self_Ctr        ");
  Show_V(Lpwm_val);
  Set_servopulse(angleServoUltrasonic);
  showAngleServoUltrasonic(angleServoUltrasonic); 
  H = Ultrasonic_Ranging(1);
  delay(300);   
  
  if(Ultrasonic_Ranging(1) < 35)         
  {
    stopp();    
              
    delay(100);
    
    back();       
            
    delay(50);
  }
     
  if(Ultrasonic_Ranging(1) < 60)        
  {
    stopp();  
    
    delay(100);   
             
    Set_servopulse(5);
    showAngleServoUltrasonic(5);
    int L = ask_pin_L(2);
    
    delay(300);      
    
    Set_servopulse(177);
    showAngleServoUltrasonic(177);
    int R = ask_pin_R(3);
    
    delay(300);      
    
    if(ask_pin_L(2) > ask_pin_R(3))   
    {
      back(); 
    
      delay(100);      
      
      turnL();
      
      delay(400);                  
      
      stopp();  
      
      delay(50);            
      
      Set_servopulse(angleServoUltrasonic);
      showAngleServoUltrasonic(angleServoUltrasonic); 
      H = Ultrasonic_Ranging(1);
      
      delay(500); 
    }
    
    if(ask_pin_L(2)  <= ask_pin_R(3))   
    {
      back();  
      
      delay(100);  
      
      turnR(); 
      
      delay(400);   
      
      stopp();  
      
      delay(50);            
      
      Set_servopulse(angleServoUltrasonic);
      showAngleServoUltrasonic(angleServoUltrasonic); 
      H = Ultrasonic_Ranging(1);
      
      delay(300);        
    } 
      
    if (ask_pin_L(2)  < 35 && ask_pin_R(3)< 35)   
    {
      stopp();            
      
      delay(50);
      
      back(); 
      
      delay(50);                   
    }          
  }
  else                      
  {
    advance();                
  }                 
}

int Ultrasonic_Ranging(unsigned char Mode)//function of ultrasonic distance detecting ，MODE=1，displaying，no displaying under other situation
{ 
  int old_distance;
  digitalWrite(outputPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(outputPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(outputPin, LOW);    
  int distance = pulseIn(inputPin, HIGH);  // reading the duration of high level
  distance= distance/58;   // Transform pulse time to distance   
  
  if(Mode==1)
  {
    //lcd.setCursor(11, 1);
    //lcd.print("H=    ");
    //lcd.setCursor(13, 1);
    //lcd.print(distance,DEC);
    
    Serial.print("\n H = ");
    Serial.print(distance,DEC); 
    
    return distance;
  }
  else  
    return distance;
} 

int ask_pin_L(unsigned char Mode)    
{ 
  int old_Ldistance;
  digitalWrite(outputPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(outputPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(outputPin, LOW);    
  int Ldistance = pulseIn(inputPin, HIGH); 
  Ldistance= Ldistance/58;   // Transform pulse time to distance   
  
  if(Mode==2)
  {
    //lcd.setCursor(11, 1);
    //lcd.print("L=    ");
    //lcd.setCursor(13, 1);
    //lcd.print(Ldistance,DEC);
    
    Serial.print("\n L = ");
    Serial.print(Ldistance,DEC); 
    
    return Ldistance;
  }
  else  
    return Ldistance;
} 

int ask_pin_R(unsigned char Mode)   
{ 
  int old_Rdistance;
  digitalWrite(outputPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(outputPin, HIGH); // 
  delayMicroseconds(10); 
  digitalWrite(outputPin, LOW);    
  int Rdistance = pulseIn(inputPin, HIGH); 
  Rdistance= Rdistance/58;   // Transform pulse time to distance   
  
  if(Mode==3)
  {
    //lcd.setCursor(11, 1);
    //lcd.print("R=    ");
    //lcd.setCursor(13, 1);
    //lcd.print(Rdistance,DEC);
    
    Serial.print("\n R = ");
    Serial.print(Rdistance,DEC); 
    
    return Rdistance;
  }
  else  
    return Rdistance;
} 

void IR_Control(void)   //remote control，when pressing“#”，it quitting from the mode
{

  Serial.print("\n IR_Control = IR_Control");

  
  unsigned long Key;
  //lcd.setCursor(0,0);  //setting cursor in the first row and column
  //lcd.print("IR_Ctr          ");
  
  while(Key!=IR_ESC)
  {
    if(irrecv.decode(&results))  //to judge whether serial port receive data
    {
      Key = results.value;
      
      switch(Key)
      {
        case IR_Go:advance();   //UP
        break;
        
        case IR_Back: back();   //back
        break;
        
        case IR_Left:turnL();   //Left    
        break;
        
        case IR_Right:turnR(); //Righ
        break;
        
        case IR_Stop:stopp();   //stop
        break;

        //motor turning left
        case IR_Servo_L: if(angleServoUltrasonic<=180)
        {  
          angleServoUltrasonic+=10;
          Set_servopulse(angleServoUltrasonic);
          showAngleServoUltrasonic(angleServoUltrasonic);
        }             
        break;

        //motor turning right 
        case IR_Servo_R: if(angleServoUltrasonic-10>=0)
        {  
          angleServoUltrasonic-=10;
          Set_servopulse(angleServoUltrasonic);
          showAngleServoUltrasonic(angleServoUltrasonic);
        } 
        break;

        //increasing speed
        case IR_Speed_UP:if(Rpwm_val+10<=250&&Rpwm_val+10<=250)
        {  
          Lpwm_val+=10; Rpwm_val+=10;
          Set_Speed(Lpwm_val,Rpwm_val);
          Show_V(Lpwm_val);
        }
        break;

        //decreasing speed
        case IR_Speed_DOWN:if(Rpwm_val-10>=0&&Rpwm_val-10>=0)
        {  
          Lpwm_val-=10; Rpwm_val-=10;
          Set_Speed(Lpwm_val,Rpwm_val);
          Show_V(Lpwm_val);
        }
        break;
        
        default: 
        break;      
      } 
      
      irrecv.resume(); // Receive the next value
    } 
  }
  
  //lcd.clear();
  //lcd.setCursor(0, 0);  //setting cursor in the first row and column
  //lcd.print("  Wait  Signal  ");
  stopp();
}

/*
void Bluetooth_Control() //Bluetooth remote control
{
  //lcd.setCursor(0, 0);  //setting cursor in the first row and column
  //lcd.print("BluetoothControl");
  
  if(Serial.available()) //to judge whether serial port receive data
  {
    Bluetooth_val=Serial.read();  //reading value of Bluetooth serial port, giving the value to val
    
    switch(Bluetooth_val)
    {
      case 'U':
        advance(); //UP
      break;
      
      case 'D': 
        back();   //back
      break;
      
      case 'L':
        turnL();   //Left
      break;
      
      case 'R':
        turnR();  //Right
      break;
      
      case 'S':
        stopp();    //stop
      break;   
    }
  } 
}
*/

void setup() 
{ 
  pinMode(servopin,OUTPUT);               //setting motor interface as output
  //lcd1602_init();                       //initializing 1602
  M_Control_IO_config();                  //motor controlling the initialization of IO
  Set_Speed(Lpwm_val,Rpwm_val);           //setting initialized speed
  Set_servopulse(angleServoUltrasonic);   //setting initialized motor angle
  Sensor_IO_Config();                     //initializing IO of line tracking module 
  irrecv.enableIRIn();                    //starting receiving IR remote control signal
  pinMode(inputPin, INPUT);               //starting receiving IR remote control signal
  pinMode(outputPin, OUTPUT);             //IO of ultrasonic module
  Serial.begin(9600);                     //initialized serial port , using Bluetooth as serial port, setting baud 
  //lcd.setCursor(0, 0);                  //setting cursor at 0.0
  //lcd.print("  Wait  Signal  ");        //LCD printing character string
  stopp();                                //stop
} 

void loop() 
{  


  //Serial.println("valor en crudo:  "); // Receive the next value
  //Serial.print(irrecv.resume().to ); // Receive the next value
      
  if (irrecv.decode(&results)) 
  {
    //Serial.println("value: "); // Receive the next value  
    //Serial.print(results.value); // Receive the next value
      
    //when receiving a button
    if(results.value == IR_LineTracking) 
    { 
      Serial.println("IR_LineTracking");
      Serial.print(results.value);
      
      while(IR_LineTracking)
      { 
        LineTracking_Mode();     //pressing “OK” on remote controller, and entering remote control mode
      }   
    } 
  
    if(results.value == IR_Self_Control) 
    {
      while(IR_Self_Control)
      {
        Serial.println("IR_Self_Control");
        Serial.print(results.value);
      
        Self_Control();   //pressing “OK” on remote controller, and entering remote control mode        } 
      }
    }
     
    if(results.value == IR_IR_Control) 
    { 
        while(IR_IR_Control)
        {

          Serial.println("IR_IR_Control");
          Serial.print(results.value);
                  
          IR_Control();   //pressing “OK” on remote controller, and entering remote control mode        } 
        }
    }   
     
        
    if(results.value == IR_Bluetooth_Control) 
    {
      while(IR_Bluetooth_Control)
      {
        Serial.println("IR_Bluetooth_Control");
        Serial.print(results.value);
        ////Bluetooth_Control();  //pressing “OK” on remote controller, and entering remote control mode
      }  
    } 

        
    irrecv.resume(); // Receive the next value 
    Serial.println(results.value, HEX);
 
    //delay(10);
  }


}

