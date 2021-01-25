/*Registrs
TWSR(TWI status register):- TWS7/TWS6/TWS5/TWS4/TWS3/-/TWS1/TWS0
TWBR(TWI bit rate Register):-TWB7/TWB6/TWB5/TWB4/TWB3/TWB2/TWB1/TWB0
TWCR(TWI control register):-TWINT/TWEA/TWSTA/TWST0/TWWC/TWEN/-/TWIE
TWDR(TWI data register):- 8 bit all contain data

H  M  S
12:15:55

*/
#include <avr/io.h>
#include <util/delay.h>
int s,m,h;
void start()
{
	TWCR=0b01100100;	
}
void stop()
{
	TWCR=0b01010100;
}
void tx(unsigned char x)
{
	TWDR=x;
	while(TWCR==0<<TWINT);
	TWCR=0<<TWINT;
}
char rx()
{
	while(TWCR==0<<TWINT)
	TWCR=0<<TWINT;
	return TWDR;
}
main()
{
	TWCR=0b01000100;
	TWBR=10;
	TWSR=0b00000000;
	start();
	tx(0b10011010);           //device address
	tx(0b00000000);            //location of second
	tx('5');
	tx('5');
	tx(0b00000000);             //location of minute
	tx('1');
	tx('5');
	tx(0b00000010);             //location of hour
	tx('1');
	tx('2');
	stop();
	while(1);
	{
		start();
		tx(0b10011011);
		tx(0b00000000);       //location of sec...BCD to char .....-char tx(s/16+48);
		s=rx();
		tx(0b00000001);       //location of min....BCD to char .....-char tx(m/16+48);
		m=rx();
		tx(0b00000010);       //location of hours.....BCD to char .....-char tx(h/16+48);
		h=rx();
	}
}