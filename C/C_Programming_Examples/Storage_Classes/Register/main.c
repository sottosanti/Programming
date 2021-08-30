#include <stdio.h>

int main() {
    register int x; // register variable (counter)

    for (x = 1; x <=15; x++)
    {
        printf("\n%d", x);
    }

    return 1;
}