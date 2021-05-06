#include"header.h"
u32 count1,count2;

int main()
{
	VIC_init();
	EINT0_init();
	
	while(1)
	{
		count1++;
	}
}

