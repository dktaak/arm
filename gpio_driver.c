#include"header.h"
void gpio_write(u8 port_num,u8 pin_num,u8 val)
{
	if(port_num==0)
		{
		IODIR0|=(1<<pin_num);//SET output DIR OF P0.0
		if(val==1)
			IOSET0=(1<<pin_num);//SET pin_num
		else if(val==0)
	    IOCLR0=(0X1<<pin_num);//CLEAR pin_num
	  }
	else if(port_num==1)
		{
		IODIR1|=(1<<pin_num);//SET output DIR OF P0.0
		if(val==1)
			IOSET1=(1<<pin_num);//SET pin_num
		else if(val==0)
	    IOCLR1=(0X1<<pin_num);//CLEAR pin_num
	  }
}
//u8 gpio_read(u8 port_num,u8 pin_num)
//{
//	u8 status;
//	if(port_num==0)
//		{
//		IODIR0&=~(1<<pin_num);//SET input DIR OF P0.0
//		 status=((IOPIN0>>pin_num)&1);
//		}
//		else	if(port_num==1)
//		{
//		IODIR1&=~(1<<pin_num);//SET output DIR OF P0.0
//		 status=((IOPIN1>>pin_num)&1);
//		}
//		return status;
//}

