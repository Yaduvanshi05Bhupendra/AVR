/*
 * Blinking_of_led.c
 *
 * Created: 09-03-2017 03:17:44 PM
 *  Author: FLY-HIGH
 */ 


#include <avr/io.h>
#include <util/delay.h>

main()
{
	DDRA=0b11111111;
	DDRB=0x00;
    while(1)
    {
		if(PINB==0b00000001);
		{
       PORTA=0b00000001;
	   _delay_ms(1000);
	   PORTA=0b00001000;
	   _delay_ms(1000);
	   PORTA=0b00010000;
	   _delay_ms(1000);
		}
		if(PINB==0b00000010);
		{	   
	   PORTA=0b00100000;
	   _delay_ms(1000);
	   PORTA=0b01000000;
	   _delay_ms(1000);
	   PORTA=0b10000000;
	   _delay_ms(1000);
    }
}
}