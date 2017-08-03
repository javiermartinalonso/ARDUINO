/* FILE:    ARD_Dot_Matrix_Example_2
   DATE:    19/03/13
   VERSION: 0.1

REVISIONS:

19/09/13 Created version 0.1

This is an example of how to use the 8x8 LED dot matrix display module (HCOPTO0011).
This example uses the HCTimer2 library as well as the HCDotMatrix library to keep 
the LED's regularly updated whilst keeping the main loop completely free for other 
code.

To connect the LED module to an Arduino development board please follow 
the pinout below:

MATRIX LED    ARDUINO

R1            D9
R2            D4
R3            A0 (D14)
R4            D6
R5            D10
R6            A1 (D15)
R7            D11
R8            A3 (D17)

C1*           D5
C2*           D12
C3*           D13 
C4*           D8
C5*           A2 (D16)
C6*           D7
C7*           D3
C8*           D2

* ALL MATRIX COLOUMN PINS MUST BE CONNECTED TO THE ARDUINO BOARD VIA A 220R
RESISTOR OTHERWISE YOU MAY RISK DAMAGING THE MODULE.

HCOPTO0011 8X8 MATRIX LED PINOUT:

PIN  1   2   3   4   5   6   7   8
LED  C8  C7  R2  C1  R4  C6  C4  R1

PIN  9   10  11  12  13  14  15  16
LED  R5  R7  C2  C3  R8  C5  R6  R3


You may copy, alter and reuse this code in any way you like, but please leave
reference to HobbyComponents.com in your comments if you redistribute this code.
This software may not be used directly for the purpose of selling products that
directly compete with Hobby Components Ltd's own range of products.

THIS SOFTWARE IS PROVIDED "AS IS". HOBBY COMPONENTS MAKES NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ACCURACY OR LACK OF NEGLIGENCE.
HOBBY COMPONENTS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR ANY DAMAGES,
INCLUDING, BUT NOT LIMITED TO, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
REASON WHATSOEVER.
*/

/* Include the 7 segment display library */
#include <HCDotMatrixAComun.h>

/* Include the HCTimer2 library */
#include <HCTimer2.h>

/* Create an instance of HCDotMatrix(pinout). Where pinout is the DIO pin 
   connections to the module in the order of R0...R7 and C0...C7 */
HCDotMatrixAComun HCDotMatrix(2,3,4,5,6,7,8,9,10,11,12,13,30,31,32,33);

int TextPosition;

void setup()
{  
  /* Initialise the HCTimer2 library with a 2.04mS interval. 
     See HCTimer2 library for more information */ 
  HCTimer2Init(T2_CLK_DIV_128, 254);
}

/* Main program */
void loop()
{
  for (TextPosition = 0; TextPosition <= (8*10); TextPosition++)
  {
    /* Output a string to the matrix buffer and specify the display 
       column position */
    HCDotMatrix.print("WWW.HOBBYCOMPONENTS.COM", TextPosition);
    delay(1600);
  }
}


/* Use the HCTimer2 Timer 2 interrupt to constantly refresh the 
   matrix LED display. */
void HCTimer2()
{
   /* Output the current buffer to the matrix */
   HCDotMatrix.UpdateMatrix();
}
