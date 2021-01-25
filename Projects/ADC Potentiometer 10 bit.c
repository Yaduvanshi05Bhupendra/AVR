/////////////////////////////////////////////////////
// Copyright (c) Bhupendra                         //
// ------------------------------------------------//
// FILE NAME: ADC Potentiometer 10 bit.c           //
// TYPE: Hardware                                  //
// DEPARTMENT: Verilog Design with FPGA            //
// AUTHOR: Bhupendra Kumar Yadav                   //
// AUTHOR'S EMAIL: Yaduvanshi05bhupendra@gmail.com //
//-------------------------------------------------//
// Release history                                 //
// VERSION DATE AUTHOR DESCRIPTION                 //
// 1.0 25/01/2029 Bhupendra Kumar Yadav            //
//-------------------------------------------------//
// KEYWORDS: Interrupt, LCD, Function              //
//-------------------------------------------------//
// PURPOSE: Measure resistance of Potentiometer    //
/////////////////////////////////////////////////////

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <lcd.h>

char adcResult[4];

int main(void)
{
	DDRD=0xFF;
	DDRC=0xFF;
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
	
	
	ADMUX |= 1<<ADLAR;
	ADMUX |= 1<<REFS0;
	ADCSRA |= 1<<ADPS2;
	ADCSRA |= 1<<ADIE;
	ADCSRA |= 1<<ADEN;
	
	sei();
	
	ADCSRA |= 1<<ADSC;


ISR(ADC_vect)
{
	uint8_t theLow = ADCL;
	uint16_t tenBitValue = ADCH << 2 | theLow >> 6;
 
 itoa(tenBitValue , adcResult , 10);
 lcd_cmd(0x80);
 display(adcResult);
 display(" ");

 ADCSRA |= 1<<ADSC;
}
