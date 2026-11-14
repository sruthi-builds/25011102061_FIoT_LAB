
#include <reg51.h>

#define SIZE 16

volatile unsigned char buffer[SIZE];
volatile unsigned char head = 0;
volatile unsigned char tail = 0;

void UART_Init(void)
{
    TMOD = (TMOD & 0x0F) | 0x20;

    TH1 = 0xFD;
    TL1 = 0xFD;

    SCON = 0x50;
    PCON &= 0x7F;

    TI = 0;
    RI = 0;

    TR1 = 1;

    ES = 1;
    EA = 1;
}


void UART_ISR(void) interrupt 4
{
    unsigned char ch;
    unsigned char next;

    if(RI == 1)
    {
        ch = SBUF;
        RI = 0;

        next = (head + 1) & 0x0F;

      
        if(next != tail)
        {
            buffer[head] = ch;
            head = next;
        }
    }

    if(TI == 1)
    {
        TI = 0;
    }
}

/* Transmit character */
void UART_Transmit(char ch)
{
    SBUF = ch;

    while(TI == 0);

    TI = 0;
}


char UART_GetChar(void)
{
    char ch;

    while(head == tail);

    ch = buffer[tail];

    tail = (tail + 1) & 0x0F;

    return ch;
}

void main(void)
{
    char ch;

    UART_Init();

    while(1)
    {
        ch = UART_GetChar();

        UART_Transmit(ch);
    }
}
