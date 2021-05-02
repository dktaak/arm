#include"header.h"
#define c0 ((IOPIN1>>16)&1)
#define c1 ((IOPIN1>>17)&1)
#define c2 ((IOPIN1>>18)&1)
#define c3 ((IOPIN1>>19)&1)
int main()
{
	u8 row=0,col=0;s8 t;
  u8 key[4][4]={7,8,9,'/',4,5,6,'*',1,2,3,'-','#',0,'=','+'};//ask about code datatype
	IODIR1=(0X1<<21);//led output dir
	IODIR0|=0X7ff;
  lcd_init();
	IODIR0|=(0XF<<16);
	IOCLR0|=(0XF<<16);
	IODIR1|=(0XF<<16);
	IOSET1|=(0XF<<16);
	IODIR1&=(~(0XF<<16));
	while(1)
	{
		while((c0&c1&c2&c3)==1);
		tdelay_ms(30);
		
		//r0=0
	IOSET0|=(0XF<<16);
	IOCLR0|=(0X1<<16);
		
		if((c0&c1&c2&c3)==0){
		row=0;
		goto colcheck;
	}
		
		//r1=0
	IOSET0|=(0XF<<16);
	IOCLR0|=(0X1<<17);
		
		if((c0&c1&c2&c3)==0){
		row=1;
		goto colcheck;
	  }
		
		//r2=0
	IOSET0|=(0XF<<16);
	IOCLR0|=(0X1<<18);
		
		if((c0&c1&c2&c3)==0){
		row=2;
		goto colcheck;
	  }		
		
		//r3=0
	IOSET0|=(0XF<<16);
	IOCLR0|=(0X1<<19);
		
		if((c0&c1&c2&c3)==0){
		row=3;
		goto colcheck;
	  }			
		
	colcheck:
	if(c0==0)
		col=0;
	else if(c1==0)
		col=1;
	else	if(c2==0)
		col=2;
	else	if(c3==0)
		col=3;
	
	while((c0&c1&c2&c3)==0);
	t=key[row][col];
	if((t>=0)&&(t<=9))
	 lcd_data(t+48);
	else
	 lcd_data(t);
  }
}
