#include <stdio.h>

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

int countOnes(int num) {
    int count = 0;
    while (num != 0) {
        if (num & 1) {   // check last bit
            count++;
        }
        num = num >> 1;  // shift right
    }
    return count;
}
    printf("Number of 1 bits = %d\n", countOnes(n));
    return 0;
}
