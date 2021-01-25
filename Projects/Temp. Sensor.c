#include <avr/io.h>
#include <util/delay.h>
#include <lcd.h>
int x=0;
main()
{
	char a[100];
	DDRA=0b00000000;
	DDRC=0b11111111;
	DDRD=0b11111111;
	ADMUX=0b11100000;
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	
	lcd_cmd(0x80);
	display("Temp:");
	lcd_cmd(0x89);
	display("*C");
	_delay_ms(100);
	
	while(1)
	{
		ADCSRA=0b11100111;
		while(ADCSRA==0<<ADIF);
		ADCSRA=0<<ADIF;
		x=ADCH;
		
		itoa(x,a,10);
		lcd_cmd(0x86);
		display(a);

	}
		}