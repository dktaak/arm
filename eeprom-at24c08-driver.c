#include "header.h"
void write_eeprom_at24c08(u8 sa,u8 mr_addr,u8 data_byte)
{
	I2C_INIT();
	I2C_START();
	I2C_WRITE(sa);
	I2C_WRITE(mr_addr);
	I2C_WRITE(data_byte);
	I2C_STOP();
}

u8 read_eeprom_at24c08(u8 sa, u8 mr_addr)
{
	u8 temp;
	I2C_START();
	I2C_WRITE(sa);
	I2C_WRITE(mr_addr);
	I2C_STOP();
	I2C_START();
	I2C_WRITE(sa|0x1);
	temp=I2C_READ();
	I2C_STOP();
	return temp;
}

