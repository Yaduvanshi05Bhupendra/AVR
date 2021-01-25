#include <avr/io.h>
#include <util/delay.h>
main()
{
	int x;
	DDRC=0xff;
	TCNT0=0;
	TCCR0=0b00000010;
	while(1)
	{
		while(TIFR==0<<TOV0)
		TIFR=0<<TOV0;
		x++;
		if(x=19607)
		{
			PORTC=~PORTC;
			x=0;
		}
	}
}