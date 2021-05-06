#include <LPC214X.H>
#include "header.h"
#define I2EN (1<<6) //Enable/Disable bit
#define STA  (1<<5) //Start Set/Clear bit
#define STO  (1<<4) //Stop bit
#define SI   (1<<3) //Serial Interrupt Flag Clear bit
#define AA   (1<<2) //Assert Acknowledge Set/Clear bit

void I2C_INIT(void)
{
	PINSEL0 = PINSEL0 | 0x00000050; /* Configure P0.2 and P0.3 as SCL0 and SDA0 respectively */
	I2C0CONSET = 0x40; /* Enable I2C  */
	//I2C0SCLL = 0x32; /* I2C data rate 300Khz and 50% duty cycle */
	//I2C0SCLH = 0x32; /* I2C data rate 300Khz and 50% duty cycle */
	I2C0SCLL = 0x4B; /* I2C data rate 300Khz and 50% duty cycle */
	I2C0SCLH = 0x4B; /* I2C data rate 300Khz and 50% duty cycle */
}

void I2C_START(void)
{
	I2C0CONCLR=SI|STA|STO|AA;
	I2C0CONSET = STA; /* Set Start bit for Start condition */
	while ( (I2C0CONSET & SI) == 0 ); /* Wait till SI = 1 */
}

void I2C_WRITE(u8 data )
{
	
	I2C0DAT = data; /* Load data to be written into the data register */
	I2C0CONCLR=STA|STO|SI;
	while( (I2C0CONSET & SI) == 0 ); /* Wait till SI = 1 */
}

u8 I2C_READ(void)
{
	I2C0CONSET=AA;
	I2C0CONCLR=SI;
	while( (I2C0CONSET & SI) == 0 ); /* Wait till SI = 1 */
	return I2C0DAT;
}

void I2C_STOP( void )
{
	I2C0CONSET = STO; /* Set Stop bit for Stop condition */
}

