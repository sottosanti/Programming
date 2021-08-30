#include <stdio.h>

int foo() {
    static int count = 0;
    int localvar = 0;

    printf("automatic=%d, static=%d ", localvar, count);

    count++;
    localvar++;
    return count;
}

int main() 
{

    for (int i = 0; i < 5; i++)
    {
        fun();
    }
    
    return 0;
}