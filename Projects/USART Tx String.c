#include <avr/io.h>
#include <util/delay.h>
void Tx(char x)
{
	UDR=x;
	while(UCSRA==0<<6);
	UCSRA=0<<TXC;
	_delay_ms(1000);
}
void Strtx(char y[])
{
	int i;
	for(i=0;y[i]!='\0';i++)
	{
		Tx(y[i]);
	}
}
main()
{
	UBRRL=51;
	UCSRA=0b00000000;
	UCSRA=0b00011000;
	UCSRA=0b10000110;
	Strtx('abcd');
}