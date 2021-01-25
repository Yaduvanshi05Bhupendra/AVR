#include <avr/io.h>
#include <util/delay.h>
void Tx(char x)
{
	UDR=x;
	while(UCSRA==0<<TXC);
	UCSRA=0<<TXC;
	_delay_ms(1000);
}
void Str_tx(char y[])
{
	int i;
	for(i=0;y[i]!='\0';i++)
	{
		Tx(y[i]);
	}
}
main()
{
	DDRA=0x00;
	DDRC=0xff;
	UBRRL=51;
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x85;
	while(1)
	{
		if(PINA=0x01);
		{
			PORTC=0x01;
			Str_tx("AT \n \r");
			_delay_ms(1000);
			Str_tx("AT+CMGF=1 \n \r");
			_delay_ms(1000);
			Str_tx("AT+CMGS=");
			_delay_ms(1000);
			Tx(';');
			Str_tx("+919911907751");
			Tx(';');
			Tx('\n \r');
			_delay_ms(1000);
			Str_tx("2ns Switch is press");
			Tx('\n \r');
			_delay_ms(1000);
			Tx(0x1A);
		}
	}
}	