#include <avr/io.h>
#include <util/delay.h>

main()
{
	DDRA=0xff;
	while (1)
	{
	PORTA=0b11111111;
	_delay_ms(2000);
	PORTA=0b00000000;
	_delay_ms(2000);
	}	
	
}