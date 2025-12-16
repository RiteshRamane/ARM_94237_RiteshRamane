#include<stdio.h>
#define BV(n) (1 << (n))
int binary(void *vp, int size);
int main()
{
    unsigned int value = 0x05;
    unsigned int value1, value2;
    printf("Left Shift by 2 position:\n");
    value1 =(value << 2);
    binary(&value1,sizeof(value1));

    printf("\nRight Shift by 1 position:\n");
    value2 = (value >> 1);
    binary(&value2,sizeof(value2));
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