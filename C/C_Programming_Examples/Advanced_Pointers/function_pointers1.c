#include <stdio.h>

void foo1 (int);
void foo2 (int);  

typedef void FuncType(int);

int main()
{
    FuncType *foo_ptr = NULL;

    foo_ptr = foo1;

    (*foo_ptr)(100);

    foo_ptr = foo2;

    (*foo_ptr)(200);

    return 0;
}

int foo1(int x) 
{
    printf("foo1 got an argument of%d\n", x);
    return 0;
}

int foo2(int x) 
{
    printf("foo2 got an argument of%d\n", x);
    return 0;
}