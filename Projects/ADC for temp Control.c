#include <avr/io.h>
#include <util/delay.h>
#include <lcd.h>                    //Calling lcd header file
int adc_conv(void)
{
	ADMUX=0b11100000;              //REFS1/REFS0/ADLAR/MUX4/MUX3/MUX2/MUX1/MUX1
	ADCSRA=0b11000000;             //ADEN/ADSC/ADATE/ADIF/ADIE/ADPS2/ADPS2/ADPS0
	while(ADCSRA==0<<ADIF);        //Waiting till conversion is completed
	ADCSRA=0<<ADIF;                 //Setting ADIF bit zero  
	return ADC;	                   //Return value of ADC
}
void lcd_str(char arr[100])
{
	int i;
	for(i=0;arr[i]!='\0';i++)
	{
		lcd_data(arr[i]);
	}
}	
main()
{
	int x;
	char a[10];
	DDRA=0x00;
	DDRC=0xff;
	DDRD=0xff;
	lcd_cmd(0x38);                    //8 bit selection mode
	lcd_cmd(0x01);                    //Clear screen
	lcd_cmd(0x0e);                    //Led on, cursor blink
	while(1)
	{
	x=adc_conv();                     //Calling adc_conv function
	itoa(x,a,10);                      //converting int x into String
	lcd_str(a);                        //Display a
	_delay_ms(1000);                   //Delay of 1 second
	lcd_cmd(0x01);                     //Clear screen
}
}