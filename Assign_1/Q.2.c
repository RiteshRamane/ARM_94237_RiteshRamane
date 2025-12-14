#include<stdio.h>
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
  int main()
  {
  int num;
  printf("Enter a number :");
  scanf("%d",&num);
binary(&num,sizeof(num));

  }
