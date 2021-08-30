#include <stdio.h>
#include <malloc.h>

struct s {
    int arraySize;
    int array[];
}; //end struct s

int main () {
    int size = 5;
    struct s *ptr;

    ptr = malloc( sizeof( struct s ) + size * sizeof( int ) );
}