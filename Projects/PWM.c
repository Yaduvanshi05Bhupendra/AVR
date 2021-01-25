#include <avr/io.h>
#include <util/delay.h>
main()
{
	DDRC=0xff;
	DDRD=0xff;
	{
		while(1)
		{
		PORTD=0xff;
			PORTB=0x01;
			_delay_ms(1);
			PORTB=0x00;
			_delay_ms(19);
			_delay_ms(1000);
		PORTC=0x01;
		_delay_ms(1.5);
		PORTC=0x00;
		_delay_ms(18.5);
		_delay_ms(3000);
		PORTC=0x01;
		_delay_ms(2);
		PORTC=0x00;
		_delay_ms(18);
		_delay_ms(3000);
	
		}		
		
	}
}