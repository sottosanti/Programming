#include <stdio.h>
#include <stdlib.h>
 
void square(int * const x);

int main()
{
    int num = 9;

    square(&num);
    printf("The square of the given number is %d\n", num);

    return 0;
}

/* 
Don't have to use const because it sends a copy of the address
*/
void square(int * const x)
{
    *x = (*x) * (*x);
}