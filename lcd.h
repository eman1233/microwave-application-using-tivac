#ifndef __LCD_H__
#define __LCD_H__

#define PORTC              ((*(volatile unsigned long*)(0x40006000)))
#define PORTD              ((*(volatile unsigned long*)(0x40007000)))
	
#define DATA PORTC
#define CTRL PORTD

#define SYSCTIL_GPIO        ((*(volatile unsigned long*)(0x400FE000+0x608)))
#define GPIODATA_C          ((*(volatile unsigned long*)(DATA +0x000)))
#define GPIODIR_C           ((*(volatile unsigned long*)(DATA +0x400)))
#define GPIODEN_C           ((*(volatile unsigned long*)(DATA +0x51c)))
#define GPIODATA_D          ((*(volatile unsigned long*)(CTRL+0x000)))
#define GPIODIR_D           ((*(volatile unsigned long*)(CTRL+0x400)))
#define GPIODEN_D           ((*(volatile unsigned long*)(CTRL+0x51c)))
	
#define RS 0X10
#define RW 0X20
#define EN 0X40

void delayMs(int n);
void delayUs(int n);
void input_init(void);
void lcd_enable(void);
void lcd_command(char command);
void lcd_data(char data);
void lcd_write(char data);
void lcd_init(void);
#endif
