#include <stdio.h>


int araySum(int array[], const int n);
/* 
also valid:
int arraySum(int *array, const int n);
*/

void main(void)
{
    int values[10] = {3,7,-9,3,6,-1,7,9,1,-5};

    printf("The sum is %i\n", arraySum(values, 10));
}

int arraySum(int array[], const int n)
{
    int sum = 0, *ptr;
    int * const arrayEnd = array + n; // address of pointer can't change

    for(ptr = array; ptr < arrayEnd; ++ptr)
        sum += *ptr;

    return sum;
}