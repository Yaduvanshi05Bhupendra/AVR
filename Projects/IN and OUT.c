#include <avr/io.h>
#include <util/delay.h>
main()
{
	DDRA=0x00;
	DDRC=0xff;
	while(1)
	{
		if(PINA==0b00000001)
		{
			PORTC=0b00000001;
		}
		if(PINA==0b00000010)
		{
			PORTC=0b00000010;
		}
		if(PINA==0x00)
		{
			PORTC=0x00;
		}
	}
}