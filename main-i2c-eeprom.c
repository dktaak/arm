#include "header.h"
u8 arr[10]={11,12,13,14,15,16,17,18,19,20};
int main()
{
	unsigned char temp;
	uart0_init(9600);
	uart0_tx_string("read data\r\n");
	write_eeprom_at24c08(0xA0,0x0,'A');
	tdelay_ms(10);
		write_eeprom_at24c08(0xA0,0x1,'B');
	tdelay_ms(10);
		write_eeprom_at24c08(0xA0,0x2,'C');
	tdelay_ms(10);
	temp=read_eeprom_at24c08(0xA0,0x0);
	uart0_tx(temp);
		temp=read_eeprom_at24c08(0xA0,0x1);
	uart0_tx(temp);
		temp=read_eeprom_at24c08(0xA0,0x2);
	uart0_tx(temp);
	while(1);
}
