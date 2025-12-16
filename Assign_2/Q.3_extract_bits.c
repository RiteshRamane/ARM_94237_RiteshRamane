#include<stdio.h>
#define BV(n) (1 << (n))
int binary(void *vp, int size);
int main()
{
    unsigned int reg = 0xABCD;
    binary(&reg,sizeof(reg));
    unsigned int value1,value2;
    printf("Extracted lower 4 bits:\n");
    value1 = (reg>>0) & 0x0000000F;     // extract lower 4 bits
    binary(&value1,sizeof(value1));
    printf("Extracted upper 4 bits of the lower byte:\n");
    value2 = (reg>>4) & 0x0000000F;     // extract upper 4 bits of lower byte
    binary(&value2,sizeof(value2));
}
int binary(void *vp, int size)
{
    int i;
    printf("Binary: ");
    for(i = size - 1; i >= 0; i--)
    {
        unsigned char mask = 0x80;
        while(mask)
        {
            if (*((char *)vp + i) & mask)
                printf("1");
            else
                printf("0");
            mask >>= 1;
        }
        printf(" ");
    }
    printf("\n");

    printf("Hex: 0x%X\n\n", *(unsigned int *)vp);  //Hexadecimal output

    return 0;
}
