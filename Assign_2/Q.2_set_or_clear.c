#include<stdio.h>
#define BV(n) (1 << (n))
int main()
{
    unsigned int reg = 0x08;
    if(reg & BV(3))  // set or clear
    {
        printf("Bit 3 is set");
    }
    else
    {
        printf("Bit 3 is clear");
    }
}