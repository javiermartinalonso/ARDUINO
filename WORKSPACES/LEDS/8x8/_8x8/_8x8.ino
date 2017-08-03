/* FILE: ARD_HC_Dot_Matrix_Example_1 
   FECHA: 19/09/13 
   VERSION: 0.1 

revisiones: 

19/09/13 Creado versión 0.1 

Este es un ejemplo de cómo utilizar el 8x8 Hobby componentes LED de matriz de puntos 
módulo de visualización (HCOPTO0011) 

para conectar el módulo LED a una placa de desarrollo Arduino siga 
el pinout a continuación: 

MATRIX LED ARDUINO 

R1 D9 
R2 D4 
R3 A0 (D14) 
R4 D6 
R5 D10 
R6 A1 (D15) 
R7 D11 
R8 A3 (D17) 

C1 * D5 
C2 * D12 
C3 * D13 
C4 * D8 
C5 * A2 (D16) 
C6 * D7 
C7 * D3 
C8 * D2 

* ALL MATRIX de Coloumn PINS DEBE CONECTARSE A LA ARDUINO BOARD VIA A 220R 
RESISTENCIA DE OTRO MODO PUEDE el riesgo de dañar el módulo. 

HCOPTO0011 8X8 MATRIX LED PINOUT: 

PIN 1 2 3 4 5 6 7 8 
LED C8 C7 R2 C1 R4 C6 C4 R1 

PIN 9 10 11 12 13 14 15 16 
LED R5 R7 C2 C3 R8 C5 R6 R3 


Puede copiar, alterar y reutilizar este código de ninguna manera se quiere, pero por favor deje 
referencia a HobbyComponents.com en sus comentarios si redistribuye este código. 
Este software no puede ser utilizado directamente para el propósito de la venta de productos que 
compiten directamente con la propia gama de productos de Hobby Components Ltd. 

ESTE SOFTWARE se proporciona "tal cual". HOBBY COMPONENTES NO OFRECE GARANTÍAS, 
explícita, implícita o estatutaria, incluida, pero no limitado a, las garantías implícitas de 
COMERCIALIZACIÓN Y APTITUD PARA UN FIN DETERMINADO, EXACTITUD O AUSENCIA DE NEGLIGENCIA. 
HOBBY COMPONENTES no podrán, en ningún caso, RESPONSABLES DE CUALQUIER DAÑO, 
INCLUYENDO, pero no limitado a, daños especiales, incidentales O DERIVADOS DE CUALQUIER 
RAZÓN. 
*/ 

/* Incluyen la biblioteca de visualización de 7 segmentos */ 
#include <HCDotMatrix.h> 

/* Crear una instancia de HCDotMatrix (pinout). Donde pinout es el pin DIO 
   conexiones al módulo en el orden de R0 ... R7 y C0 ... C7 */ 
//HCDotMatrix HCDotMatrix (9,4,14,6,10,15,11,17,5,12, 13,8,16,7,3,2); 
HCDotMatrix HCDotMatrix(9,14,8,12,1,7,2,5,13,3,4,10,6,11,15,16);

/* Almacena el índice de posición para la parte de texto a diplay */ 
int TextPosition; 
/* Se utiliza para controlar la velocidad de desplazamiento. */ 
int ScrollCounter = 0; 

void setup()
{

}

/* Main program */
void loop()
{
  /* Increment the scroll counter */
  ScrollCounter++;
  
  /* Has enough time passed to move the text by one position ?*/
  if (ScrollCounter >= 100)
  {
    /* Have we got to the end of the text (24 characters x 8 pixels wide)? 
       If so go back to the start.*/
    if (TextPosition > (24*8))
      TextPosition = 0;
   
    /* Output a string to the matrix buffer and specify the display 
       column position */
    HCDotMatrix.print("WWW.HOBBYCOMPONENTS.COM", TextPosition);
    
    TextPosition++;
    ScrollCounter = 0;
  }
  
  /* Refresh the display. This must be run continuously */
  HCDotMatrix.UpdateMatrix();
}

