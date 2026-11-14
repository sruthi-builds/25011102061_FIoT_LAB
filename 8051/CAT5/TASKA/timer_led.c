#include <reg51.h>

sbit LED = P1^1;

unsigned int ms_count = 0;

void timer0_check(void)
{if(TF0==1){
	  TF0=0;
    TH0 = 0xE6;
    TL0 = 0xCD;

    ms_count++;

    if(ms_count >=86)
    {
        ms_count = 0;

        LED = ~LED;
    }
	}
}

void main()
{

    TMOD = 0x01;

    TH0 = 0xE6;
    TL0 = 0xCD;
	  TR0=1;

    while(1)
    {

	    timer0_check();

    }
}