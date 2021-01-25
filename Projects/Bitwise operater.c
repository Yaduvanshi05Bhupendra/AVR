#include <avr/io.h>
#include <util/delay.h>
main()
{
	DDRB=0b11111110;
	while(1)
	{
		if(PINB==(1<<0))
	{
		PORTB|=(1<<1);
		_delay_ms(1000);
	}
	if(PINB==(0<<0))
	{
		PORTB|=(0<<1);
		_delay_ms(1000);
	}
	}	
}