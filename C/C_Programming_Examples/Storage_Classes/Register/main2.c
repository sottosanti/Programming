#include <stdio.h>

int main() {
    int x = 15; // register variable (counter)

    register int *a = &x;

    printf("\n%d", *a);

    return 1;
}