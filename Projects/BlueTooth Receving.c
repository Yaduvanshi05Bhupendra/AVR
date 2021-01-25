#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL;
main()
{
	
	char x;
	UBRRL=51;
	UCSRA=0b00000000;
	UCSRB=0b00011000;
	UCSRC=0b10000110;
	DDRC=0b11111111;
	while(1)
	{
	while(UCSRA==0<<7);
	UCSRA=0<<7;
	x=UDR;
	if(x=='a')
	{
		PORTC=0xFF;
	}	
	if(x=='b')
	{
		PORTC=0x00;
	}
	}
}