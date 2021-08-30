#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));

    for(int i = 0; i < 10; ++i)
    {
        printf(" %d ", rand());
        printf(" %d ", rand() % 5 + 1); // Random numbers in the range from 1 to 5
    }

    printf("\n");

    return 0;
}