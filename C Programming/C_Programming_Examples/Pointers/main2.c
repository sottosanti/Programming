#include <stdio.h>

void foo(int *b){
    *b = 3;
}

/* function definition to swap the values */
void swap(int *x, int *y)
{
    int temp;
    int c = 0;
    
    temp = *x; /* save the value at address x */
    *x = *y; /* put y into x */
    *y = temp; /* put temp into y */
    *y = 2;
    foo(y);
    &y = &c;
    return;
}

int main() 
{
    int a = 100;
    int c = 50;
    int *b = &c;

    printf("Before swap, value of a : %d\n", a);
    printf("Before swap, value of b : %d\n", *b);

    swap(&a, b);

    printf("After swap, value of a : %d\n", a);
    printf("After swap, value of b : %d\n", *b);

    return 0;
}