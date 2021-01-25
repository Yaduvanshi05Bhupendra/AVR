#include <avr/io.h>
#include <util/delay.h>
main()
{
	char x;
	UBRRL=51;
	UCSRA=0b00000000;
	UCSRB=0b00011000;
	UCSRC=0b10000110;
	DDRB=0xff;
	while(1)
	{
		while(UCSRA==0<<RXC);
		UCSRA=0<<RXC;
		x=UDR;
		if(x=='a')
		{
			PORTB=0b00000001;
		}
		if(x=='b')
		{
			PORTB=0b00000010;
		}
		if(x=='c')
		{
			PORTB=0b00000100;
		}			
		if(x=='d')
		{
			PORTB=0xff;
		}
		}
	}
