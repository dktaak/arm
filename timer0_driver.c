#include"header.h"
void tdelay_sec(unsigned int sec)
{
	T0PR=15000000-1;//if PCLK=15Mhz
	T0PC=T0TC=0X0;//init
	T0TCR=0X1;//start timer0
	while(T0TC<sec);//wait untill ov
	  T0TCR=0X0;//stop
}

void tdelay_ms(unsigned int ms)
{
	T0PR=15000-1;//if PCLK=15Mhz
	T0PC=T0TC=0X0;//init
	T0TCR=0X1;//start timer0
	while(T0TC<ms);//wait untill ov
	  T0TCR=0X0;//stop
}

