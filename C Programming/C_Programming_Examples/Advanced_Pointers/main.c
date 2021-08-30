#include <stdio.h>
#include <malloc.h>

void foo(int *ptr) {
    int a = 5;
    ptr = &a;
}

void foo1(int *ptr) {
    int a = 5;
    *ptr = a;
}

void foo2(int **ptr) {
    int a = 3;
    *ptr = &a;
}

int main() {
    int *ptr = NULL;
    ptr = (int *) malloc(sizeof(int));
    *ptr = 10;

    foo(ptr);
    printf("%d\n", *ptr);
    
    foo1(ptr);
    printf("%d\n", *ptr);

    foo2(&ptr);
    printf("%d\n", *ptr);

    return 0;
}