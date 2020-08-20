#include "lcd.h"


void delayMs(int n){
	int i,j;
	for(i=0;i<=n;i++){
	 for(j=0;j<=3189;j++)
	 {}
 }
}

void delayUs(int n){
	int i,j;
	for(i=0;i<=n;i++){
	 for(j=0;j<=3;j++)
	 {}
 }
}

void input_init(void){
	unsigned long delay;
	SYSCTIL_GPIO|=(0X04)|(0x08);
	delay=SYSCTIL_GPIO;
	GPIODIR_D|=0XF0;
	GPIODIR_C|=0XFF;
	GPIODEN_D|=0XF0;
	GPIODEN_C|=0XFF;
}

void lcd_enable(void){
	GPIODATA_C&=~(unsigned long)0X40;
	delayMs(5);
	GPIODATA_C|=0X40;
	delayMs(5);
}

void lcd_command(char command){
	GPIODATA_D&=~(unsigned long)0X10;
	GPIODATA_C&=~(unsigned long)0Xff;
	delayMs(5);
	GPIODATA_C=command;
	lcd_enable();
}

void lcd_data(char data){
	GPIODATA_D|=0X10;
	GPIODATA_C&=~(unsigned long)0Xff;
	delayMs(5);
	GPIODATA_C=data;
	lcd_enable();
}

void lcd_write(char data){
	GPIODATA_D&=~(unsigned long)0X20;
	GPIODATA_C&=~(unsigned long)0Xff;
	delayMs(5);
	GPIODATA_C=data;
	lcd_enable();
}

void lcd_init(void){
	GPIODATA_C&=~(unsigned long)0X10;
	GPIODATA_C&=~(unsigned long)0X40;
	GPIODATA_C&=~(unsigned long)0Xff;
	delayMs(20);
	GPIODATA_C&=~(unsigned long)0Xff;
	lcd_command(0x38);
	lcd_enable();
	delayMs(5);
	GPIODATA_C&=~(unsigned long)0Xff;
	lcd_command(0x38);
	lcd_enable();
	delayUs(150);
	GPIODATA_C&=~(unsigned long)0Xff;
	lcd_command(0x38);
	lcd_enable();
	lcd_command(0x01);delayMs(2);
	lcd_command(0x02);delayMs(2);
	lcd_command(0x06);delayMs(2);
	lcd_command(0x0c);delayMs(2);
	lcd_command(0x10);delayMs(2);
  lcd_command(0x38);delayMs(2);
  lcd_command(0x80);delayMs(2);
}


	
