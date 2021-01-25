#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
main()
{
	DDRB=0xff;
	while (1)
	{
	PORTB=0b00000001;
	_delay_ms(1);
	PORTB=0b00000000;
	_delay_ms(19);
	_delay_ms(1000);
	PORTB=0b00000001;
	_delay_ms(1.5);
	PORTB=0b00000000;
	_delay_ms(18.5);
	_delay_ms(1000);
	PORTB=0b00000001;
	_delay_ms(2);
	PORTB=0b00000000;
	_delay_ms(18);
	_delay_ms(1000);
	PORTB=0b00000001;
	_delay_ms(1.5);
	PORTB=0b00000000;
	_delay_ms(18.5);
	_delay_ms(1000);
	}	
	
}

