#include <avr/io.h>
#include <util/delay.h>
main()
{
	int i;
	
	DDRD=0b11111111;
	TCCR1A=0b01010011;
	TCCR1B=0b00011010;
	while(1)
	{
		OCR1A=65535;
		for(i=0;i<65535;i++)
		{
			ICR1=i;
			_delay_ms(10000);
		}
	}
}