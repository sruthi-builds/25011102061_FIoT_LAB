#include <reg51.h>

#define LCD_PORT P3

sbit RS = P3^2;
sbit E  = P3^3;

void delay_ms(unsigned int ms)
{
    unsigned int i, j;

    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < 1275; j++);
    }
}

void lcd_enable()
{
    E = 1;
    delay_ms(1);
    E = 0;
}

void lcd_send_nibble(unsigned char nibble)
{
    LCD_PORT = (LCD_PORT & 0x0F) | (nibble & 0xF0);
    lcd_enable();
}

void lcd_cmd(unsigned char cmd)
{
    RS = 0;

    lcd_send_nibble(cmd);
    lcd_send_nibble(cmd << 4);

    delay_ms(2);
}

void lcd_data(unsigned char dat)
{
    RS = 1;

    lcd_send_nibble(dat);
    lcd_send_nibble(dat << 4);

    delay_ms(1);
}

void lcd_init()
{
    RS = 0;
    E = 0;

    delay_ms(20);

    lcd_send_nibble(0x30);
    delay_ms(5);

    lcd_send_nibble(0x30);
    delay_ms(1);

    lcd_send_nibble(0x30);
    delay_ms(1);

    lcd_send_nibble(0x20);

    lcd_cmd(0x28);
    lcd_cmd(0x0F);
    lcd_cmd(0x06);
    lcd_cmd(0x01);

    delay_ms(2);
}


void lcd_goto(unsigned char row, unsigned char column)
{
    if(row == 0)
        lcd_cmd(0x80 + column);
    else
        lcd_cmd(0xC0 + column);
}


void lcd_puts(char *str)
{
    while(*str)
    {
        lcd_data(*str);
        str++;
    }
}


void lcd_print_number(unsigned int value)
{
    unsigned char digits[5];
    unsigned char i = 0;
    unsigned char j;

    if(value == 0)
    {
        lcd_data('0');
        return;
    }

    while(value > 0)
    {
        digits[i] = (value % 10) + '0';
        value = value / 10;
        i++;
    }

    for(j = i; j > 0; j--)
    {
        lcd_data(digits[j-1]);
    }
}

void main()
{
    unsigned int count = 0;

    lcd_init();

    lcd_goto(0, 0);
    lcd_puts("Counter Value:");

    while(1)
    {
        lcd_goto(1, 0);

        lcd_print_number(count);

        // Clear any leftover digits
        lcd_puts("     ");

        count++;

        if(count > 99999)
            count = 0;

        delay_ms(500);
    }
}