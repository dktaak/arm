#include"header.h"
#define I2C_ENABLE  1 << 6     //I2C Enable bit
#define I2C_START 1 << 5     //Start Bit
#define I2C_STOP  1 << 4     //Stop Bit
#define I2C_SI  1 << 3     //I2C interrupt flag
#define I2C_ACK   1 << 2     //assert ACK flag

void i2c_init(void)
{
	PINSEL0|=(0x3<<22);//SCL1 0x00000
	PINSEL0|=(0x3<<28);//SDA1
	
	I2C1CONCLR=0X0;//CLEAR CONTROL REGISTER
	
	//set I2C clock to work at 100Khz
	I2C1SCLH=300; //SET I2C frequency=[Pclk/(I2CSCLL+I2CSCH)]
	I2C1SCLL=300;
	
	I2C1CONSET=1<<6;//ENABLE I2C
}

void i2c_start(void) //Function to initiate a start condition on the I2C bus
{
//unsigned int status;
	I2C1CONCLR=(0xff);//CLEAR ALL BITS OF CONTROL REG EXCEPT I2C ENABLE
	I2C1CONSET=1<<6;//ENABLE I2C
	I2C1CONSET=1<<5;//start field of i2c frame
	//I2C1CONCLR|=(1<<5);//clear start bit 
	while(!(I2C1CONSET& (1<<3)));      //wait till interrupt flag becomes set

}

void i2c_stop(void)
{
	I2C1CONCLR =I2C_START | I2C_SI | I2C_ACK;    //clear all bits
	I2C1CONSET=1<<4;//STOP field of i2c frame
}

void i2c_write(u32 data)
{
	I2C1DAT=data;
	I2C1CONCLR = I2C_START | I2C_STOP;//CLEAR ALL BITS OF CONTROL REG EXCEPT I2C ENABLE
	I2C1CONCLR = I2C_SI; 
  while(!(I2C1CONSET& (1<<3)));   //wait till interrupt flag becomes set
	I2C1CONCLR=(0X08);//clear si bit
}

u32 i2c_read(void)
{
  I2C1CONCLR = I2C_START | I2C_STOP;//CLEAR ALL BITS OF CONTROL REG EXCEPT I2C ENABLE
	I2C1CONCLR = I2C_SI; 
	I2C1CONSET=1<<2;//ack
  while(!(I2C1CONSET& (1<<3)));  //wait till interrupt flag becomes set
	I2C1CONCLR =(0X0c);
	return I2C1DAT;
}

void i2c_write_frame(u32 sa,u32 mr,u32 data)
{
	i2c_start();
	i2c_write(0xa0);//sa+W
	i2c_write(mr);
//	i2c_write((mr>>15)&0XFF);
//i2c_write((mr>>15)&0XFF);
	i2c_write(data);
  i2c_stop();
}

u32 i2c_read_frame(u32 sa,u32 mr)
{
	u8 temp;
	i2c_start();
	i2c_write(sa);//sa+W
	i2c_write(mr);
//	i2c_write((mr>>15)&0XFF);
//i2c_write((mr>>15)&0XFF);
	i2c_start();
	i2c_write(sa|1);//sa+R
	temp=i2c_read();
  i2c_stop();
	
	return temp;
}
