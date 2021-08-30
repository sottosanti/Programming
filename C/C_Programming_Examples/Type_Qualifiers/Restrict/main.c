#include <stdio.h>
#include <malloc.h>


void f1(int n, float * restrict a1, const float * restrict a2)
{
    int i;
    for ( i = 0; i < n; i++ )
    {
        a1[i] += a2[i];
    }
}

int main(void) {
    int n;
    int array[10];
    int * restrict restar = (int *) malloc(10*sizeof(int));
    int *par = array;

    for ( n = 0; n < 10; n++ )
    {
        par[n] += 5;
        restar[n] += 5;
        array[n] *= 2;
        par[n] += 3;
        restar[n] += 3;
    }

    // compiler would optimize and do
    // restar[n] += 8 

    // definitions
    void * memcpy(void * restrict s1, const void * restrict s2, size_t n);
    void * memmove(void * s1, const void * s2, size_t n);
}