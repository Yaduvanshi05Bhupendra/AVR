#include <avr/io.h>
#include <util/delay.h>

void pina0()
{
	while(bit_is_clear(PINA, 0))
	{
	PORTB |= 1<<PINB0;
	}
		PORTB &= ~(1<<PINB0);
	
}

void  pina1()
{
	while(bit_is_clear(PINA, 1))
	{
		PORTB |= 1<<PINB1;
	}
	PORTB &= ~(1<<PINB1);
	
	
} 
void  pina2()
{
	while(bit_is_clear(PINA, 2))
	{
		PORTB |= 1<<PINB2;
	}
	PORTB &= ~(1<<PINB2);
	
	
}
void  pina3()
{
		PORTB |= 1<<PINB3;	
}


int main(void)
{
	
	DDRB |= 1<<PINB0 | 1<<PINB1 | 1<<PINB2 | 1<<PINB3;
	DDRA &= ~(1<<PINA0);
	PORTA |= 1<<PINA0;
	DDRA &= ~(1<<PINA1);
	PORTA |= 1<<PINA1;
	DDRA &= ~(1<<PINA2);
	PORTA |= 1<<PINA2;
	DDRA &= ~(1<<PINA3);
	PORTA |= 1<<PINA3;
	
	while(1)
	{
		
		
		if(bit_is_clear(PINA, 0))
		{
			pina0();
		}
		else if(bit_is_clear(PINA, 1))
		{
			pina1();
		}
		else if(bit_is_clear(PINA, 2))
		{
			pina2();
		}
		else
		{
			pina3();
			_delay_ms(100);
			PORTB &= ~(1<<PINB3);
		}
	}
}