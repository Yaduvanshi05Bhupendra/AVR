#include<avr/io.h>
#include <util/delay.h>
main()
{
	DDRA=0b00000000;
	DDRB=0b11111111;
	while(1)
	{
		if(PINA==0b00000001)
		{
			PORTB=0xff;
		}
		if(PINA==0x00)
		{
			PORTB=0x00;
		}
	}
}