#include <stdio.h>


struct point { int x, y; };

struct zpoint {
    int x, y, z;
};

int main() {
    int numbers[100] = {1, 2, 3, [3 ... 9] = 10, [10] = 80, 15, [70] = 50, [42] = 400};

    for (int i = 0; i < 100; i++){
        printf("%d ", numbers[i]);
    }

    printf("\n\n");
    int array[100];

    for (int i = 0; i < 100; i++){
        printf("%d ", array[i]);
    }

    printf("\n\n");

    int numbers_array[] = {1, 2, 3, [10] = 80, 15, [70] = 50, [42] = 400};
    int n = sizeof(numbers_array) / sizeof(numbers_array[0]);
    printf("%d\n", n);

    struct point p = { .y = 2, .x = 3 };
    struct point q = { y: 2, x: 3 };
    // same as
    struct point r = { 2, 3 };

    struct zpoint p1 = { .y = 0, .z = 1, .x = 2};
    struct zpoint p2 = { .x = 20 };

    printf ( "x = %d, y = %d, z = %d\n", p1.x, p1.y, p1.z );
    printf ( "x = %d\n", p2.x );

    struct point pts[5] = { [2].y = 5, [2].x = 6, [0].x = 2};

    int i;
    for (i = 0; i < 5; i++)
        printf("%d %d\n", pts[i].x, pts[i].y);

    return 1;
}