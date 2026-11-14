#include <reg51.h>
#include "delay.h"
#include "patterns.c"
sbit R1=P2^7;
sbit R2=P2^6;
sbit R3=P2^5;
sbit R4=P2^4;
sbit C1=P2^3;
sbit C2=P2^2;
sbit C3=P2^1;
sbit C4=P2^0;
unsigned char keypad_scan(){
	R1=0;
	R2=1;
	R3=1;
	R4=1;
	if(C1==0){
		while(C1==0);
			return 0;
	}
	else if(C2==0){
		while(C2==0);
			return 1;
	}
	else if(C3==0){
		while(C3==0);
			return 2;
	}
	else if(C4==0){
		while(C4==0);
			return 3;
	}
	R1=1;
	R2=0;
	R3=1;
	R4=1;
		if(C1==0){
		while(C1==0);
			return 4;
	}
		else if(C2==0){
		while(C2==0);
			return 5;
	}
		else if(C3==0){
		while(C3==0);
			return 6;
	}
		else if(C4==0){
		while(C4==0);
			return 7;
	}
	R1=1;
	R2=1;
	R3=0;
	R4=1;
		if(C1==0){
		while(C1==0);
			return 8;
	}
		else if(C2==0){
		while(C2==0);
			return 9;
	}
		else if(C3==0){
		while(C3==0);
			return 10;
	}
		else if(C4==0){
		while(C4==0);
			return 11;
	}
	
	R1=1;
	R2=1;
	R3=1;
	R4=0;
		if(C1==0){
		while(C1==0);
			return 12;
	}
		else if(C2==0){
		while(C2==0);
			return 13;
	}
		else if(C3==0){
		while(C3==0);
			return 14;
	}
		else if(C4==0){
		while(C4==0);
			return 15;
	}
		
	
}
void display_digit(unsigned char digit)
{
    switch(digit)
    {
        case 0: P0 = 0x3F; break;
        case 1: P0 = 0x06; break;
        case 2: P0 = 0x5B; break;
        case 3: P0 = 0x4F; break;
			  case 4: P0 = 0x66; break;
        case 5: P0 = 0x6D; break;
        case 6: P0 = 0x7D; break;
        case 7: P0 = 0x07; break;
			  case 8: P0 = 0x7F; break;
        case 9: P0 = 0x6F; break;
        case 10: P0 = 0x77; break;
        case 11: P0 = 0x7C; break;
			  case 12: P0 = 0x39; break;
        case 13: P0 = 0x5E; break;
        case 14: P0 = 0x79; break;
        case 15: P0 = 0x71; break;

        default:
            P0 = 0x00;
            break;
    }
}
void led_control(unsigned char key){
	switch(key){
		case 0:P1=0x01;break;
		case 1:P1=0x02;break;
		case 2:P1=0x04;break;
		case 3:P1=0x08;break;
		case 4:
			runningPattern();
		break;
		case 5:
			alternatingPattern();
		break;
		case 6:
			binaryCounter();
		break;
		case 7:flash();
		break;
		case 8:P1=0x00;break;
		default:
			P1=0x00;
		  break;
	}
}
		
void main()
{
    unsigned char key;

    while(1)
    {
        key = keypad_scan();

            display_digit(key);
			      led_control(key);
    }
}
		