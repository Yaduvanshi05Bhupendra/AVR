#include <avr/io.h>
#include <util/delay.h>
char Rx(void)
{
	while(UCSRA==0<<RXC)  //Waiting till all data is received
	UCSRA=0<<RXC;         //Setting RXC pin to zero again
	return UDR;           //Returning value 
}
void Vart_int(int x)      //Setting value of Register
{
	UBRRL=x;
	UCSRA=0x00;
	UCSRB=0b00011000;
	UCSRC=0b10000110;
}
main()
{
	char x;
	DDRB=0xff;
	Vart_int(51);            //value of UBRRRL
	while(1)
	{
		x=Rx();               //Receiving value
		if(x=='a')
		{
			PORTB=0b00000001;  //Switching on LED
		}
	}