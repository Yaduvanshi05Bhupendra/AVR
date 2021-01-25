/*
 * dc_fan_control.c
 *
 * Created: 08-04-2017 03:41:00
 *  Author: Fly-High
 */ 
char as[15];
#include <avr/io.h>
#include<util/delay.h>
void lcd_cmd(char x)
{   PORTB=x;
	PORTD=0b00000100;
	_delay_ms(10);
	PORTD=0b00000000;
	_delay_ms(10);
}
void lcd_data(char x)
{   PORTB=x;
	PORTD=0b00000101;
	_delay_ms(10);
	PORTD=0b00000001;
	_delay_ms(10);
}
void lcd_str(char arr[])
{ 
	int i;
	for(i=0;arr[i]!='\0';i++)
	{
		lcd_data(arr[i]);
	}
}
int main(void)
{   int x;
    DDRB=0b11111111;
	DDRD=0b11111111;
	lcd_cmd(0X38);
	lcd_cmd(0X0E);
	lcd_cmd(0X01);
	lcd_cmd(0XC0);
	lcd_str("Starting :");
	_delay_ms(1000);
	lcd_data('.');
	_delay_ms(1000);
	lcd_data('.');
	_delay_ms(1000);
	lcd_data('.');
	_delay_ms(7000);
	lcd_cmd(0x01);
	lcd_str("temperature");
	lcd_cmd(0XC0);
	lcd_str("control fan");
	_delay_ms(7000);
	lcd_cmd(0X01);
	lcd_str ("by-");
	lcd_cmd(0XC0);
	lcd_str("Priya & Harshita");
	_delay_ms(7000);
	lcd_cmd(0X01);
	lcd_str("Temp :");
	lcd_cmd(0XC0);
	lcd_str("Fan :");
	DDRC=0b11111111;
	DDRA=0;
	ADCSRA=0X87;
	ADMUX=0XE0;
	while(1)
	{
		ADCSRA|=(1<<ADSC);
		while((ADCSRA&(1<<ADSC)==0));
		x=ADCH;
		itoa(ADCH,as,10);
	if (x>0&&x<=19)
	{
		lcd_cmd(0X88);
		lcd_str(as);
		lcd_cmd(0XC8);
		lcd_str("Slow");
		PORTC=0b00000001;
		_delay_ms(300);
		PORTC=0b00000011;
		_delay_ms(3000);
	}
	if (x>19&&x<=39)
	{
		lcd_cmd(0X88);
		lcd_str(as);
		lcd_cmd(0XC8);
		lcd_str("Med.");
		PORTC=0b00000001;
		_delay_ms(300);
		PORTC=0b00000011;
		_delay_ms(3000);
	}
	if (x>39&&x<=59)
	{
		lcd_cmd(0X88);
		lcd_str(as);
		lcd_cmd(0XC8);
		lcd_str("High");
		PORTC=0b00000001;
		_delay_ms(300);
		PORTC=0b00000011;
		_delay_ms(3000);
	}
  }
}