#include<LPC214X.H>
//extern void delay(unsigned short int ms);
typedef unsigned long int u32;
typedef signed long int s32;
typedef unsigned char u8;
typedef unsigned short int u16;
typedef signed char s8;
typedef signed short int s16;

extern void tdelay_sec(unsigned int);
extern void tdelay_ms(unsigned int);

extern void gpio_write(u8 port_num,u8 pin_num,u8 val);
extern u8 gpio_read(u8 port_num,u8 pin_num);
//LCD

extern void lcd_cmd(u32);
extern void lcd_data(u32);
extern void lcd_init(void);
extern void lcd_string(u8 *);
extern void lcd_int(long int n);
extern void lcd_float(float f);
//extern void cgram_init();

//keyboard
extern s8 keyscan(void);
//extern u8 math(void);

//uart
extern void uart0_tx_string(u8 *p);
extern u8 uart0_rx(void);
extern void uart0_tx(u8 data);
extern void uart0_init(u32 baud);
extern void uart0_integer(signed long int n);

//ADC
extern void adc0_init(void);
extern u32 adc0_read(void);
