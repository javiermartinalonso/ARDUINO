/* FILE:	HCDotMatrix.cpp
   DATE:    19/03/13
   VERSION: 0.1
   AUTHOR:  Andrew Davies

Library for 8x8 dot matrix LED displays

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



#include "Arduino.h"
#include "HCDotMatrix.h"


/* Constructor to initiliase the GPIO as outputs and in the OFF state*/
HCDotMatrix::HCDotMatrix(byte R0,byte R1,byte R2,byte R3,byte R4,byte R5,byte R6,byte R7,
						 byte C0,byte C1,byte C2,byte C3,byte C4,byte C5,byte C6,byte C7)
{

  _PinOut_Row[0] = R0;
  _PinOut_Row[1] = R1;
  _PinOut_Row[2] = R2;
  _PinOut_Row[3] = R3;
  _PinOut_Row[4] = R4;
  _PinOut_Row[5] = R5;
  _PinOut_Row[6] = R6;
  _PinOut_Row[7] = R7;

  _PinOut_Col[0] = C0;
  _PinOut_Col[1] = C1;
  _PinOut_Col[2] = C2;
  _PinOut_Col[3] = C3;
  _PinOut_Col[4] = C4;
  _PinOut_Col[5] = C5;
  _PinOut_Col[6] = C6;
  _PinOut_Col[7] = C7;


  for (_Cur_Row = 0; _Cur_Row < 8; _Cur_Row++)
  {
    pinMode (_PinOut_Row[_Cur_Row], OUTPUT);
    digitalWrite(_PinOut_Row[_Cur_Row], LOW);
  }

  for (_Cur_Col = 0; _Cur_Col < 8; _Cur_Col++)
  {
    pinMode (_PinOut_Col[_Cur_Col], OUTPUT);
    digitalWrite(_PinOut_Col[_Cur_Col], HIGH);
  }

}

/* Does one refresh cycle of the display */
void HCDotMatrix::UpdateMatrix(void)
{

  /* Cycles through each row in turn */
  for (_Cur_Col = 0; _Cur_Col < 8; _Cur_Col++)
  {
    /* Sets the appropriate state for the current row to high to enable
       the row */
    digitalWrite(_PinOut_Col[_Cur_Col], LOW);

    /* Cycles through each LED for the current row */
    for (_Cur_Row = 0; _Cur_Row < 8; _Cur_Row++)
    {
      /* Sets the column state for the current LED to low to turn the
         LED on */
      digitalWrite(_PinOut_Row[_Cur_Row], ((_CurentBitmap[_Cur_Col] >> (7 - _Cur_Row)) & 1));

      /* Turns the LED off */
      digitalWrite(_PinOut_Row[_Cur_Row], LOW);
    }
    /* Disables the selected row */
    digitalWrite(_PinOut_Col[_Cur_Col], HIGH);
  }
}

/* Places the appropriate peice of the message string into the display buffer */
void HCDotMatrix::print(char TextString[], unsigned int xoffset)
{

  /* Finds length of string */
  _StringLength = strlen(TextString) - 1;


  /* Clears the display buffer */
  for (_Bufferindex = 0; _Bufferindex <= 7; _Bufferindex++)
   {
 	 _CurentBitmap[_Bufferindex] = 0;
   }

   /* Is the specified display position beyond the size of the text string ? */
   if (_StringLength <=  (xoffset >> 3))
   {
     _FirstCharIndex = _StringLength;
   } else
   {
     _FirstCharIndex = xoffset >> 3;
   }


   /* Matrix display is only ever big enough for parts of 2 characters so find
     start of first character */
   _FirstCharColOffset = xoffset - (_FirstCharIndex << 3);

   /* How many columns of that character to display */
   _FirstCharLength = 8 - _FirstCharColOffset;

   /* Finds how many colums of the second character to display */
   _SecondCharLength = 8 - _FirstCharLength;


   /* Copies the character bitmap data from the first character to the matrix buffer */
   _Bufferindex = 0;
   for (_RowIndex = _FirstCharColOffset; _RowIndex <= 7; _RowIndex++)
   {
 	 for (_ColIndex = 0 ; _ColIndex <= 7; _ColIndex++)
 	 {
 	   _CurentBitmap[_Bufferindex] |= (((Char_Set[TextString[_FirstCharIndex] - 32][_ColIndex] >> (7 - _RowIndex)) & 1)) << (7 - _ColIndex);
 	 }
  	_Bufferindex++;
   }


   /* Copies the character bitmap data from the second character to the matrix buffer */
   for (_RowIndex = 0; _RowIndex <= _SecondCharLength; _RowIndex++)
   {
     for (_ColIndex = 0 ; _ColIndex <= 7; _ColIndex++)
	 {
       if (_FirstCharIndex == _StringLength)
       {
	     _CurentBitmap[_Bufferindex] |= (((Char_Set[0][_ColIndex] >> (7 - _RowIndex)) & 1)) << (7 - _ColIndex);
	   } else
	   {
		 _CurentBitmap[_Bufferindex] |= (((Char_Set[TextString[_FirstCharIndex + 1] - 32][_ColIndex] >> (7 - _RowIndex)) & 1)) << (7 - _ColIndex);
	   }
     }

   _Bufferindex++;
   }
}