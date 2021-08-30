#include <stdio.h>

// Global data
const int global = 10;

int main(void) {

    const const const const const const double pi = 3.141592654;
    // same as 
    //const double pi = 3.141592654;

    const int days[12] = {31, 28, 31, 30, .....};

    typedef const int zip;

    const zip q = 8;

    const float *pf; // pf points to a constant float value

    float * const pt; // pt is a const pointer

    const float * const ptr; // both are constant

    float const *pfc; // same as const float *pfc

    return 0;
}

void display (const int array[], int limit){}
// const int array[] 
// same as
// const int *array

// The actual definition
char *strcat(char *restrict sl, const char * restrict s2);