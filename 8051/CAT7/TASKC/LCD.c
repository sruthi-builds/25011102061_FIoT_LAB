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

void lcd_string(char *str)
{
    while(*str)
    {
        lcd_data(*str);
        str++;
    }
}

void lcd_goto(unsigned char row, unsigned char column)
{
    if(row == 0)
        lcd_cmd(0x80 + column);

    else
        lcd_cmd(0xC0 + column);
}


void lcd_init()
{
    RS = 0;
    E = 0;

    delay_ms(20);

    
    lcd_send_nibble(0x20);


    lcd_cmd(0x28);

    
    lcd_cmd(0x0F);

  
    lcd_cmd(0x06);

    lcd_cmd(0x01);

    delay_ms(2);
}



void main(void)
{
    unsigned char key;

    unsigned char row = 0;
    unsigned char column = 0;

    lcd_init();
    lcd_goto(row, column);
    lcd_data('*');

    while(1)
    {
        key = keypad_scan();
        lcd_goto(row, column);
        lcd_data(' ');

        if(key == 2)
        {
            if(row > 0)
                row--;
        }

        else if(key == 8)
        {
            if(row < 1)
                row++;
        }

        else if(key == 4)
        {
            if(column > 0)
                column--;
        }

        else if(key == 6)
        {
            if(column < 15)
                column++;
        }
        lcd_goto(row, column);
        lcd_data('*');

        delay_ms(150);
    }
}