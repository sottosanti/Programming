#include <stdio.h>

union car {
    int i_value;
    float f_value;
    char c_value[40];
};


int main() 
{
    union car car1, car2, *car3;
    printf("Memory size occupied by car: %zu\n", sizeof(car1));

    return 0;
}