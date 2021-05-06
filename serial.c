#include<lpc214x.h>		 //Includes LPC2148 register definitions
#include "serial.h"

void Uart0Init (void)		    // Initialize Serial Interface       
{               	   
    PINSEL0 |= 0x00000005;           //Enable RxD0 and TxD0                     
    U0LCR = 0x83;                   // 8 bits, no Parity, 1 Stop bit            
    U0DLL = 97;                     // 9600 Baud Rate @ 15MHz PCLK         
    U0LCR = 0x03; 		    // DLAB = 0  
}
				
void Uart0PutCh (unsigned char ch)  // Write character to Serial Port   
{                  		
   	U0THR = ch;
	  while (!(U0LSR & 0x20));
}

void  Uart0PutS(unsigned char *str)  //A function to send a string on UART0
{  
   while(*str)
   {  
      Uart0PutCh(*str++);	    
   }
}
unsigned char Uart0GetCh (void)		// Read character from Serial Port   
{            
  while (!(U0LSR & 0x01));
  return (U0RBR);
}
