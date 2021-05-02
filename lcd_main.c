#include"header.h"

int main()
{
	IODIR0=0X7FF;
	lcd_init();
	lcd_data('A');
	lcd_int(255);
	lcd_data(' ');
	lcd_float(32.56);
	lcd_cmd(0XC0);
	lcd_string("VECTOR");
	while(1);
}
