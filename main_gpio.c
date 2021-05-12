#include"header.h"
#define SW1 ((IOPIN1>>17)&1)
#define SW2 ((IOPIN1>>18)&1)
#define SW3 ((IOPIN1>>19)&1)
#define SW4 ((IOPIN1>>20)&1)
int main()
{
	IODIR0=0X7FF;
//	lcd_init();
//	lcd_data('=');
//	int i=0,j=0;
//	for(i=0;i<8;i++)
//	{
//		j=(~j)&1;
//			gpio_write(0,i,j);
//	}
	IODIR0|=(0xf<<11);
	IOCLR0|=(0xf<<11);

	IODIR1|=(1<<21);//led output dir

	while(1)
	{
		if((SW1==0)||(SW2==0)||(SW3==0)||(SW4==0))
		  IOCLR1=1<<21;//LED ON
		else
			IOSET1=1<<21;//LED OFF
		
	}
	
	//blink
//	while(1){
//	gpio_write(0,0,1);
//	tdelay_ms(100);
//	gpio_write(0,0,0);
//	tdelay_ms(100);
//	}		
	//blink
//		IODIR0=0X1;//SET output DIR OF P0.0
//	  while(1){
//	  IOSET0=1;//SET P0.0
//		tdelay_ms(500);
//	  IOCLR0=0X1;//SET P0.0
//		tdelay_ms(500);
//	} 
}

