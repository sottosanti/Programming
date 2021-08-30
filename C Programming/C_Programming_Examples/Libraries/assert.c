#include <stdio.h>
#include <assert.h>

int main(void) {
    int y = 5;

    for(int x = 0; x < 20; ++x) {
        printf("X = %d y = %d", x, y);
        assert(x < y);
    }

    return 0;
}