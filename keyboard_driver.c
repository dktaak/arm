#include"header.h"
#define c0 ((IOPIN1>>16)&1)
#define c1 ((IOPIN1>>17)&1)
#define c2 ((IOPIN1>>18)&1)
#define c3 ((IOPIN1>>19)&1)


s8 row=0,col=0;
s8 key[4][4]={7,8,9,'/',4,5,6,'*',1,2,3,'-','#',0,'=','+'};//ask about code datatype
	
s8 keyscan(void)
{
	
		while((c0&c1&c2&c3)==1);
		tdelay_ms(30);
		
		//r0=0
	IOSET0|=(0XF<<16);
	IOCLR0|=(0X1<<16);
		
		if((c0&c1&c2&c3)==0){
		row=0;
		goto colcheck;
	}
		
		//r1=0
	IOSET0|=(0XF<<16);
	IOCLR0|=(0X1<<17);
		
		if((c0&c1&c2&c3)==0){
		row=1;
		goto colcheck;
	  }
		
		//r2=0
	IOSET0|=(0XF<<16);
	IOCLR0|=(0X1<<18);
		
		if((c0&c1&c2&c3)==0){
		row=2;
		goto colcheck;
	  }		
		
		//r3=0
	IOSET0|=(0XF<<16);
	IOCLR0|=(0X1<<19);
		
		if((c0&c1&c2&c3)==0){
		row=3;
		goto colcheck;
	  }			
		
	colcheck:
	if(c0==0)
		col=0;
	else if(c1==0)
		col=1;
	else	if(c2==0)
		col=2;
	else	if(c3==0)
		col=3;
	
	while((c0&c1&c2&c3)==0);
	return key[row][col];
}
//u8 math(void){
//	u8 a[4],i;
//	for(i=0;i<4;i++){
//		a[i]=keyscan();
//	if((a[i]>=0)&&(a[i]<=9))
//	  lcd_data(a[i]+48);
//	else
//	  lcd_data(a[i]);
//	if(a[i]==('='))
//		break;
//	else if(a[i]==('#')){
//		lcd_cmd(0x1);
//		return 0;
//	}	
//}
//	switch(a[1]){
//		case '/':
//			a[0]=(a[0]/a[2]);break;
//		case '*':
//			a[0]=(a[0]*a[2]);break;
//		case '+':
//			a[0]=(a[0]+a[2]);break;
//		case '-':
//			a[0]=(a[0]-a[2]);break;
//	} 
//	return a[0];
//}
