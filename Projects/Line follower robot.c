#include <avr/io.h>
#include <util/delay.h>
main()
{
	DDRA=0x00;
	DDRC=0x00;
	DDRB=0xff;
	DDRD=0xff;
	while(1)
	{
		if(PINA==0x01&&PINC==0x01)
		{
		PORTB=0x01;
		PORTD=0x01;
		}		
		if(PINA==0x00&&PINC==0x00)
		{
			PORTB=0x00;
			PORTD=0x00;
		}			
		if(PINA==0b00000000&&PINC==0b00000001)
		{
			PORTB=0b00000001;
			PORTD=0b00000000;
		}		
		if(PINA==0b00000001&&PINC==0b00000000)
		{
			PORTB=0b00000000;
			PORTD=0b00000001;
		}	
		
	}
}