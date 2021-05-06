/**
 @file
 
 	This file contains function delaration for source code
 	
*/

#ifndef serial_h_
#define serial_h_
extern void Uart0Init (void);
extern void Uart0PutCh (unsigned char ch);
extern void Uart0PutS (unsigned char *str);
extern unsigned char Uart0GetCh (void);
#endif 


/**

End of file

*/
