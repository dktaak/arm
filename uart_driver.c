#include"header.h"

void uart0_init(u32 baud)
{
	PINSEL0|=0X5;//TX RX ENABLED
	U0LCR=0X83;//DLAB=1(Baudrate setting unlocked),P=DISABLE,8 BIT MODE, 
	
	switch(baud)
	{
		case 9600: U0DLL=97; break;
		case 57600: U0DLL=16; break;
		case 115200: U0DLL=8; break;
		case 921600: U0DLL=1; break;
	}
	U0LCR=0X03;//DLAB=0(Baudrate setting locked),P=DISABLE,8 BIT MODE
}

#define THRE ((U0LSR>>5)&1)
#define RDR ((U0LSR)&1)

void uart0_tx(u8 data)
{
	U0THR=data;
	while(THRE==0);
	//THRE=0; Auto clear flag
}

u8 uart0_rx(void)
{
	while(RDR==0);
	//RDR=0; Auto clear flag
	return U0RBR;
}

void uart0_tx_string(u8 *p)
{
	while(*p)
	{
		uart0_tx(*p);
		p++;
	}
}
#include<stdio.h>
void uart0_integer(s32 n)
{
	s8 buf[10];
	sprintf((char*)buf,"%d",n);
	uart0_tx_string((u8 *)buf);
}
