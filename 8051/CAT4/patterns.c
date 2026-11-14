#include <reg51.h>
#include "patterns.h"
#include "delay.h"

void runningPattern()
{
    P1 = 0x01;
    delay();

    P1 = 0x02;
    delay();

    P1 = 0x04;
    delay();

    P1 = 0x08;
    delay();
}
void binaryCounter(){
	int i;
	for(i=0;i<16;i++){
		P1=i;
		delay();
	}
}
void alternatingPattern(){
	P1=0x0A;
	delay();
	P1=0x05;
	delay();
}
void flash(){
	P1=0x0F;
	delay();
	P1=0x00;
	delay();
}