#include"header.h"
#define RS_C gpio_write(0,8,0) 
#define RS_D gpio_write(0,8,1)
#define RW gpio_write(0,9,0)
#define EN gpio_write(0,10,1)
#define EN_D gpio_write(0,10,0)

void lcd_cmd(u32 cmd)
{
	IOCLR0=0XFF;
	IOPIN0=cmd;
  RS_C;
	RW;
	EN;
	tdelay_ms(2);
	EN_D;
}
void lcd_data(u32 data)
{
	IOCLR0=0XFF;
	IOPIN0=data;
  RS_D;
	RW;
	EN;
	tdelay_ms(2);
	EN_D;
	
}
void lcd_init(void)
{
	lcd_cmd(0x02);//cursur move to home position
  lcd_cmd(0x38);//8 bit_ mode
	lcd_cmd(0x0E);//cursur on
	lcd_cmd(0x01);/* Display clear */
	//lcd_cmd(0x80);  /* First line first position */
	
}

void lcd_string(u8 *p)
{
	while(*p!='\0')
	{
//		if((*p)==Enter_key)
//			{
//			lcd_cmd(0xc0);
//				p++;
//		  }
		lcd_data(*p);
		p++;
	}
}

void lcd_int(s32 n){
	signed long int i=0,a[16];
	if(n<0){
		lcd_data('-');
		n=-n;
	}
	if(n==0)
		lcd_data(48);
	while(n){
		a[i]=n%10;
		i++;
		n=n/10;
	}
	for(i=i-1;i>=0;i--){
		lcd_data(a[i]+48);
	}
}

void lcd_float(float f){
	long int ip,dp;
	if(f<0){
		lcd_data('-');
		f=-f;
	}
	ip=f;
	dp=(f-ip)*100;
	lcd_int(ip);
	lcd_data('.');
	lcd_int(dp);
}


