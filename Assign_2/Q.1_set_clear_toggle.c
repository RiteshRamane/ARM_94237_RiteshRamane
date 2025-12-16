#include<stdio.h>
#define BV(n) (1 << (n))
int binary(void *vp, int size);
int main()
{
    unsigned int reg = 0x2A;
    binary(&reg,sizeof(reg));

    printf("Set bit no. 4:\n");
    reg=reg|BV(4);                 // set bit 4
    binary(&reg,sizeof(reg));
    printf("Clear bit no. 1:\n");
    reg=reg & ~(BV(1));            // clear bit 1
    binary(&reg,sizeof(reg));
    printf("Toggle bit no. 5:\n");
    reg=reg ^ BV(5);               // toggle bit 5
    binary(&reg,sizeof(reg));

}
int binary(void *vp, int size)
{
    int i;
    printf("Binary: ");
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

    printf("Hex: 0x%X\n\n", *(unsigned int *)vp);  //Hexadecimal output
}