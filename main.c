#include"header.h"
int main()
{
		IODIR0=0X1;//SET output DIR OF P0.0
	while(1){
	  IOSET0=1;//SET P0.0
		tdelay_ms(1);
	  IOCLR0=0X1;//SET P0.0
		tdelay_ms(1);
	}
	//while(1);
	
 
}
