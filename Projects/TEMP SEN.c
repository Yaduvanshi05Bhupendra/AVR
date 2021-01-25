/*
 * ADC_Potentiometer.c
 *
 * Created: 10-04-2018 02:11:10 PM
 *  Author: FLY-HIGH
 */ 


#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <lcd.h>
#define F_CPU 1000000UL;

int x=0;
int main(void)
{
	DDRD=0xFF;
	DDRC=0xFF;
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
	
	lcd_cmd(0x80);
	display("Temp");
	_delay_ms(100);
	lcd_cmd(0x85);
	display(":");
	_delay_ms(100);
	 lcd_cmd(0x89);
	 display("*");
	 lcd_cmd(0x8A);
	 display("C");
	
	
	ADMUX |= 1<<ADLAR;
	ADMUX |= 1<<REFS0;
	ADMUX |= 1<<REFS1;
	ADCSRA |= 1<<ADPS0;
	ADCSRA |= 1<<ADPS1;
	ADCSRA |= 1<<ADPS2; 
	ADCSRA |= 1<<ADIE;
	ADCSRA |= 1<<ADEN;
	
	sei();
	
	ADCSRA |= 1<<ADSC;
		
    while(1)
    {
        //TODO:: Please write your application code 
    }
}

ISR(ADC_vect)
{
	
	x = ADCH;
 char a[4];
 itoa(x , a , 10);
 _delay_ms(200);
 
 lcd_cmd(0x86);
 display(a);


 ADCSRA |= 1<<ADSC;
}