#include <reg51.h>
#include "keypad.h"
#include "delay.h"

// Rows
sbit R1 = P2^7;
sbit R2 = P2^6;
sbit R3 = P2^5;
sbit R4 = P2^4;

// Columns
sbit C1 = P2^3;
sbit C2 = P2^2;
sbit C3 = P2^1;
sbit C4 = P2^0;

unsigned char keypad_scan()
{
    //---------------- ROW 1 ----------------//

    R1 = 0;
    R2 = 1;
    R3 = 1;
    R4 = 1;

    if(C1 == 0)
    {
        while(C1 == 0);
        return 1;
    }

    if(C2 == 0)
    {
        while(C2 == 0);
        return 2;
    }

    if(C3 == 0)
    {
        while(C3 == 0);
        return 3;
    }

    if(C4 == 0)
    {
        while(C4 == 0);
        return 10;     // A
    }

    //---------------- ROW 2 ----------------//

    R1 = 1;
    R2 = 0;
    R3 = 1;
    R4 = 1;

    if(C1 == 0)
    {
        while(C1 == 0);
        delay();
        return 4;
    }

    if(C2 == 0)
    {
        while(C2 == 0);
        return 5;
    }

    if(C3 == 0)
    {
        while(C3 == 0);
        return 6;
    }

    if(C4 == 0)
    {
        while(C4 == 0);
        return 11;     // B
    }

    //---------------- ROW 3 ----------------//

    R1 = 1;
    R2 = 1;
    R3 = 0;
    R4 = 1;

    if(C1 == 0)
    {
        while(C1 == 0);
        
        return 7;
    }

    if(C2 == 0)
    {
        while(C2 == 0);

        return 8;
    }

    if(C3 == 0)
    {
        while(C3 == 0);
        
        return 9;
    }

    if(C4 == 0)
    {
        while(C4 == 0);
        
        return 12;     // C
    }

    //---------------- ROW 4 ----------------//

    R1 = 1;
    R2 = 1;
    R3 = 1;
    R4 = 0;

    if(C1 == 0)
    {
        while(C1 == 0);
        return 14;     // *
    }

    if(C2 == 0)
    {
        while(C2 == 0);

        return 0;
    }

    if(C3 == 0)
    {
        while(C3 == 0);
        return 15;     // #
    }

    if(C4 == 0)
    {
        while(C4 == 0);
        return 13;     // D
    }

    return 255;        // No key pressed
}