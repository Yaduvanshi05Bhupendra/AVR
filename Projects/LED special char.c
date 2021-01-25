#include <avr/io.h>
#include <lcd.h>
#include <util/delay.h>
main()
{
DDRC=0xff;
DDRD=0xff;
lcd_cmd(0x38);
lcd_cmd(0x0e);
lcd_cmd(0x01);
lcd_cmd(64);
lcd_data(31);
lcd_data(28);
lcd_data(23);
lcd_data(21);
lcd_data(29);
lcd_data(5);
lcd_data(0);
lcd_cmd(0x83);
_delay_ms(2000);
lcd_data(0);
}
