#include"header.h"

int main()
{
	u32 val;
	uart0_init(9600);
	adc0_init();
	uart0_integer(1234);
	while(1)
	{
		val=adc0_read();
		uart0_integer(val);
		uart0_tx_string((u8*)"\r\n");//next line
		tdelay_ms(50);//optional
	
	}
}
