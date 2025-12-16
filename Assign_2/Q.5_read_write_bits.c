#include<stdio.h>
#define BV(n) (1 << (n))
int binary(void *vp, int size);
int main()
{
    unsigned int reg = 0xAA;
    binary(&reg,sizeof(reg));
    unsigned int value1,value2=0x03;

    printf("\nRead the value of bits from bit 2 to bit 4:\n");
    value1 = (reg>>2) & 0x00000007;          // to read value
    binary(&value1,sizeof(value1));

    printf("\nWrite the value 0b011 into bits 2 to 4 without changing other bits:\n");
    reg =reg & ~(BV(2) | BV(3) | BV(4));     // to write value
    reg = reg | (value2 << 2);
    binary(&reg,sizeof(reg));
}
int binary(void *vp, int size)
{
    int i;
    for(i = size - 1; i >= 0; i--)
    {
        unsigned char mask=0x80;
        while(mask)
        {
               if( *((char *)vp + i) & mask )
                printf("1");
            else
                printf("0");
            mask >>= 1;
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}