
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

char UART_Receive(void)
{
    char ch;

    while(RI == 0);

    ch = SBUF;
    RI = 0;

    return ch;
}

void UART_Transmit(char ch)
{
    SBUF = ch;

    while(TI == 0);

    TI = 0;
}

void main(void)
{
    char received;

    UART_Init();

    while(1)
    {
        received = UART_Receive();

        UART_Transmit(received);
    }
}
