#include <stdio.h>

#define PI 3.14

#define CIRCLE_AREA(x) ((PI) * (x) * (x))

int main()
{
    int area = CIRCLE_AREA(4)
    printf("Area is %d\n", area);

    return 0;
}