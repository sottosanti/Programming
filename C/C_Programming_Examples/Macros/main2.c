#include <stdio.h>

#define Warning(...) fprintf(stderr, __VA_ARGS__)
int main() 
{
    Warning("%s: this program is here\n", "Stephen");
    return 0;
}