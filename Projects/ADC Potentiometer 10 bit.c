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

char adcResult[4];

int main(void)
{
	DDRD=0xFF;
	DDRC=0xFF;
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
	
	
	ADMUX |= 1<<ADLAR;
	ADMUX |= 1<<REFS0;
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
	uint8_t theLow = ADCL;
	uint16_t tenBitValue = ADCH << 2 | theLow >> 6;
 
 itoa(tenBitValue , adcResult , 10);
 lcd_cmd(0x80);
 display(adcResult);
 display(" ");

 ADCSRA |= 1<<ADSC;
}