#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <lcd.h>

int main(void)
{
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	display("ADC Result:");
	
	ADCSRA |= 1<<ADPS2;
	ADMUX |= (1<<REFS0) | (1<<REFS1);
	ADCSRA |= 1<<ADEN;
	ADCSRA |= 1<<ADIE;
	
	sei();
	
	ADCSRA |= 1<<ADSC;
	
	while(1)
	{
		
	}
}

ISR(ADC_vect)
{
	char y[4];
	uint8_t theLowADC = ADCL;
	uint16_t theTenBitResults = ADCH<<8 | theLowADC;
	itoa(theTenBitResults, y, 10);
	lcd_cmd(0x8D);
	display(y);
	
	ADCSRA |= 1<<ADSC;
}