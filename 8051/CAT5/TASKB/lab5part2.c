#include <reg51.h>

sbit LED = P1^0;

unsigned char count = 0;
unsigned char duty = 100;
bit increasing = 0;

void Timer1_ISR(void) interrupt 1
{
   
    TH0 = 0xFC;
    TL0 = 0x66;

   
    count++;

    if(count >= 100)
    {
        count = 0;

       
        if(increasing == 0)
        {
            if(duty > 0)
                duty--;

            if(duty == 0)
                increasing = 1;
        }
        else
        {
            if(duty < 100)
                duty++;

            if(duty == 100)
                increasing = 0;
        }
    }

    
    if(count < duty)
        LED = 1;
    else
        LED = 0;
}

void main(void)
{
   
    TMOD = 0x01;

   
    TH0 = 0xFC;
    TL0 = 0x66;

   
    IE = 0x82;

   
    TR0 = 1;

    while(1)
    {
        
    }
}