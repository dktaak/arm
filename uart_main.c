#include"header.h"

int main()
{
	uart0_init(9600);
	uart0_tx_string((u8*)"Loopback...\r\n");
	uart0_integer(133);
	while(1)
	{
		uart0_tx(uart0_rx());//loopback
	}
}
