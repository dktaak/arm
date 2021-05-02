#include"header.h"

int main()
{
	s8 val;
	IODIR0=0X7ff;
  lcd_init();
	
	IODIR0|=(0XF<<16);
	IOCLR0|=(0XF<<16);
	IODIR1|=(0XF<<16);
	IOSET1|=(0XF<<16);
	IODIR1&=(~(0XF<<16));
	while(1)
	{
	val=keyscan();
	if((val>=0)&&(val<=9))
	 lcd_data(val+48);
	else
	 lcd_data(val);
  }
}

