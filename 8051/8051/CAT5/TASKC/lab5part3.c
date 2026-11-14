
#include <reg51.h>

sbit DIR  = P2^0;
sbit SLOW = P2^1;
sbit FAST = P2^2;

volatile unsigned char ms_count = 0;
volatile bit step_due = 0;

unsigned char step_index = 0;
unsigned char step_interval = 50;

unsigned char code steps[4] = {
    0x08, 0x04, 0x02, 0x01
};

void Timer0_ISR(void) interrupt 1
{
    TH0 = 0xFC;
    TL0 = 0x66;

    ms_count++;

    if(ms_count >= step_interval)
    {
        ms_count = 0;
        step_due = 1;
    }
}

void main(void)
{
    unsigned char pattern;

    P1 = 0x00;

   
    TMOD = (TMOD & 0xF0) | 0x01;

    
    TH0 = 0xFC;
    TL0 = 0x66;

    
    ET0 = 1;
    EA = 1;

    
    TR0 = 1;

    while(1)
    {
      
        if(SLOW == 0)
            step_interval = 100;
        else if(FAST == 0)
            step_interval = 10;
        else
            step_interval = 50;

       
        if(step_due == 1)
        {
            EA = 0;
            step_due = 0;
            EA = 1;

            if(DIR == 0)
            {
              
                step_index++;

                if(step_index >= 4)
                    step_index = 0;
            }
            else
            {
                
                if(step_index == 0)
                    step_index = 3;
                else
                    step_index--;
            }

            pattern = steps[step_index];
            P1 = (P1 & 0xF0) | pattern;
        }
    }
}
