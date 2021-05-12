#include"header.h"
#define SW1 ((IOPIN0>>2)&1)
int main()
{
	IODIR0=0X3;
	 IOCLR0|=1<<1;
	while(1){
	if(SW1==0)
		IOCLR0|=1;
	else
		IOSET0|=1;
}
}
