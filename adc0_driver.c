#include"header.h"

void adc0_init(void)
{
	PINSEL0|=(3<<8);//11 0000 0000//P0.4 SELECT AS ADC0.6 CHANNEL
	AD0CR=0X00200440;// 00 0010 0000 04 0100 0000
	                 //6th bit selects channe6 //8th to 15th bit decides (PCLK/val+1)<4.5
	                 //16th bit select burst mode 0(software)
	                 //17th to 19th select resolution(000 for 10 bit resolution)
	                 //21st bit(PDN=1) selects adc in operational mode
}

#define ADC_DONE 0x80000000 //will help in extracting 31st bit

u32 adc0_read(void)
{
	u32 val;
	AD0CR|=(1<<24);//START ADC0.6
	//TABLE NO.285
	while(((AD0GDR>>31)&1)==0);//WAITING HERE FOR CONVERSION TO COMPLETE(31ST BIT SHOW COMPLETION)
	AD0CR&=(~(1<<24));//STOP ADC0.6
	val=((AD0GDR>>6)&0X3FF);//6TH TO 15TH BIT SHOWS THE RECENT RESULT SO MASKING
	
	return val;
}
