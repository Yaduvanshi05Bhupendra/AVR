#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
#define Ref 1500

int x = Ref;
int p = Ref;

int Rotation_plus(int a)
{
	int i,n;
	for(i=1; i < 3; i++)
	{
		OCR1A = ICR1 - (a+(9*i));
	    _delay_ms(100);
	}	
	n = ICR1 - OCR1A;
	return n;
}

int Rotation_minus(int a)
{
	int i,n;
	for(i=1; i < 3 ; i++)
	{
		OCR1A = ICR1 - (a-(9*i));
		_delay_ms(100);
	}
	n = ICR1 - OCR1A;
	return n;
}

int Retain_postion(int a)
{
	int n;
	OCR1A = ICR1 - a;
	_delay_ms(100);
	n = a;
	return n;
}

int Reset_to_zero(int a)
{
	int i, n;
	
	if(a>Ref)
	{
		for(i=a; i >= Ref ; i=i-10)
	{
		OCR1A = ICR1 - (a-(9*i));
		_delay_ms(100);
	}
	}	
	
	if(a<=Ref)
	{
		for(i=a; i <= Ref ; i=i+10)
		{
			OCR1A = ICR1 - (a+(9*i));
			_delay_ms(100);
		}
	}
	n = ICR1 - OCR1A;
	return n;
}

int main(void)
{
/***************************** Timer *******************/
	DDRD |= 1<<PIND5;                                   // Define direction resistor OCR1A(PD5) as output 
	DDRA &= ~(1<<PINA0) & ~(1<<PINA1) & ~(1<<PINA2);
	TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1A0;
	TCCR1B |= 1<<WGM12 | 1<<WGM13 | 1<<CS10;
	
	ICR1 = 19999;
	
/**********************************************************/
	
	
	
/******************* Timer *******************/
	while(1)
	{
		
		if(PINA == (1<<PINA0))
		{
			x = Rotation_plus(p);
			_delay_ms(500);
		}			
		
	    else if(PINA == (1<<PINA1))
		{
			x = Rotation_minus(p);
			_delay_ms(500);
		}
		
		else if(PINA == (1<<PINA2))
		{
			x = Reset_to_zero(p);
			_delay_ms(500);
		}
		else
		{
			x = Retain_postion(p);
			_delay_ms(500);
		}
		p = x;
	}
}
/*******************************************/