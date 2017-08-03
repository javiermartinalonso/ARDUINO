/* 
 *  https://github.com/nickchiaratti/ADXL345/blob/master/GetEulerAngles/GetEulerAngles.ino
*/
#include <Wire.h> // I2C library, gyroscope
#include <math.h>
// Accelerometer ADXL345
#define ACC (0xA7>>1)    //ADXL345 ACC address
const int Xcorrection = 0;    //Determine these by zeroing their values when they are not the axis measuring gravity
const int Ycorrection = 271;
const int Zcorrection = -906;
float Roll,Pitch;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  initAcc();
}
  
void loop()
{
  int hx,hy,hz;
  int acc[3];
  getAccelerometerData(acc);
  hz = acc[0];
  hy = acc[1];
  hx = acc[2];
  
  float R   = sqrt(pow(hx,2)+pow(hy,2)+pow(hz,2));
  Roll = -atan2(hx/R, hz/R)*180/M_PI;
  Pitch = -atan2(hy/R, hz/R)*180/M_PI;
  
  Serial.print(" X=");
  Serial.print(Roll);
  Serial.print(" Y=");
  Serial.print(Pitch);
  
  Serial.println(" ");
  delay(50); 
}

void initAcc() {
//Turning on the ADXL345
writeTo(ACC, 0x2D, 0x08);  //Power-saving features control
writeTo(ACC, 0x31, 0x0B);  //Data format control
writeTo(ACC, 0x2C, 0x0A);  //Data rate and power mode control
writeTo(ACC, 0x1E, 0x28);  //X-Axis offset
writeTo(ACC, 0x1F, 0x00);  //Y-Axis offset
writeTo(ACC, 0x20, 0x00);  //Z-Axis offset
//by default the device is in +-2g range reading
}

void getAccelerometerData(int * result) {
int regAddress = 0x32;    //first axis-acceleration-data register on the ADXL345
byte buff[6];
readFrom(ACC, regAddress, 6, buff); //read the acceleration data from the ADXL345
//each axis reading comes in 10 bit resolution, ie 2 bytes.  Least Significat Byte first!!
//thus we are converting both bytes in to one int
result[0] = ((((int)buff[1]) << 8) | buff[0])+ Xcorrection;   
result[1] = ((((int)buff[3]) << 8) | buff[2])+ Ycorrection;
result[2] = ((((int)buff[5]) << 8) | buff[4])+ Zcorrection;
}


void writeTo(int DEVICE, unsigned char address, unsigned char val) {
 Wire.beginTransmission(DEVICE); //start transmission to ACC 
 Wire.write(address);        // send register address
 Wire.write(val);        // send value to write
 Wire.endTransmission(); //end transmission
}


//reads num bytes starting from address register on ACC in to buff array
void readFrom(int DEVICE, unsigned char address, int num, unsigned char buff[]) {
Wire.beginTransmission(DEVICE); //start transmission to ACC 
Wire.write(address);        //sends address to read from
Wire.endTransmission(); //end transmission
Wire.beginTransmission(DEVICE); //start transmission to ACC
Wire.requestFrom(DEVICE, num);    // request 6 bytes from ACC
int i = 0;
while(Wire.available())    //ACC may send less than requested (abnormal)
  { 
  buff[i] = Wire.read(); // receive a byte
  i++;
  }
Wire.endTransmission(); //end transmission
}

