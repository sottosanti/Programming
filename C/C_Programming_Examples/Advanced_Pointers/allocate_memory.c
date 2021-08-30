#include <stdio.h>
#include <malloc.h>

void allocateMemory (int ** ptr) 
{
    *ptr = (int *) malloc(sizeof(int)); // allocate memory
}

int main()
[
    int * ptr = NULL;

    allocateMemory(&ptr);
    *ptr = 20;
    printf("%d\n", *ptr);

    // free the memory
    free(ptr);

    return 0;
]