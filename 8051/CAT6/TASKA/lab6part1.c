
#include <reg51.h>

void UART_Init(void)
{
    TMOD = (TMOD & 0x0F) | 0x20;
    TH1 = 0xFD;
    TL1 = 0xFD;

    SCON = 0x50;
    PCON &= 0x7F;

    TR1 = 1;
}

void UART_Transmit(char ch)
{
    SBUF = ch;

    while(TI == 0);

    TI = 0;
}

void UART_SendString(char *str)
{
    while(*str)
    {
        UART_Transmit(*str);
        str++;
    }
}

void delay(void)
{
    unsigned int i, j;

    for(i = 0; i < 500; i++)
        for(j = 0; j < 100; j++);
}

void main(void)
{
    UART_Init();

    while(1)
    {
        UART_SendString("Hello from 8051\r\n");
        delay();
    }
}
