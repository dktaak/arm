#include"header.h"

int main()
{
	u32 temp;
	uart0_init(9600);
	i2c_init();
	//uart0_tx('A');
	i2c_write_frame(0xa0,0x0,'A');
	temp=i2c_read_frame(0xa0,0x0);
	uart0_tx(temp);
	while(1);
}

