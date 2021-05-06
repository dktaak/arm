#include"header.h"

extern u32 count2;

void EINT0_Handler(void) __irq
{
	count2++;//default task
	
	EXTINT=0X1;//clear flag
	VICVectAddr=0x0;//dummy adress to finish isr
}

/*Configure the VIC*/

void VIC_init(void)
{
	VICIntSelect=1<<14;//EINT0 intrpt IS FIQ type
	
//	VICIntSelect=0x0;//all intrpt are irq type
//	VICVectCntl0=14|(1<<5);//enable slot
//	VICVectAddr0=(unsigned int)EINT0_Handler;//Assign isr adress
	VICIntEnable|=1<<14;//enable EINT0
}

/*Configure the EINT0*/

void EINT0_init(void)
{
	PINSEL1|=1;//P0.16-->EINT0 feature select
	EXTPOLAR=0x0;//Active low
	EXTMODE=0x1;//edge trigered
}
