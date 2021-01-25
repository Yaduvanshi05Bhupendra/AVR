/*
 * Servo_multiple.c
 *
 * Created: 10-04-2018 01:38:36 PM
 *  Author: FLY-HIGH
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB = 0xFF;
	TCCR1A |= 1<<WGM11;
	TCCR1B |= 1<<WGM12 | 1<<WGM13 | 1<<CS10;
	TIMSK |= 1<<OCIE1A;
	
	ICR1 = 19999;
	sei();
    while(1)
    {
		if (TCNT1>=800 && TCNT1<=2400)
		{
       if (TCNT1 >= 2000 && bit_is_set (PORTB, PINB0)) PORTB &= ~(1<<PINB0); 
    }
	if (TCNT1<800 || TCNT1>2400)
	{
		
	}
}
}

ISR (TIMER1_COMPA_vect)
{
	PORTB = 0xFF;
}