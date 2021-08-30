#include <stdio.h>

union mixed {
    char c;
    float f;
    int i;
};



int main()
{
    union mixed x;

    x.c = 'j';
    printf("Character = %c\n", x.c);

    x.f = 784.3323;
    printf("Float = %f\n", x.f);

    return 0;
}