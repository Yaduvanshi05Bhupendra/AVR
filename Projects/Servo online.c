#include <avr/io.h>
#include <util/delay.h>
//#define F_CPU 16000000UL

int main(void)
{
	DDRA = 0x00;
	DDRD = 0xFF;
	DDRC = 0xff;
	TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1A0;
	TCCR1B |= 1<<WGM12 | 1<<WGM13 | 1<<CS10;
	
	ICR1 = 19999;
	
	int i;
	
	while(1)
	{
		/*	
           	for(i=1; i<20; i++)
			{
		OCR1A = ICR1 - (1500+(9*i));
		_delay_ms(500);			
			
			}			
		for(i=1; i<20; i++)
		{			
			OCR1A = ICR1 - (1500-(9*i));
			_delay_ms(500);
			
		}	*/	
		
		
		OCR1A = ICR1 - 1500;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 2500;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1500;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 500;
		_delay_ms(1000);
		
		/*OCR1A = ICR1 - 1800;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1700;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1600;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1500;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1400;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1300;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1200;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1100;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1200;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1300;
		_delay_ms(1000);
		
		OCR1A = ICR1 - 1400;
		_delay_ms(1000);
		
		*/
	}
}	