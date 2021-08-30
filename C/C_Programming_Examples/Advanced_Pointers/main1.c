#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
&ptr = 0xaaaaa;
ptr = 0xfffff;
0xfffff = 6

&ptr_cpy = 0xbbbbb;
ptr_cpy = 0xfffff;
*/
void foo(char *ptr_cpy) {
    ptr_cpy = malloc(255); // Allocating memory for a copy
    strcpy(ptr_cpy, "Hello World\n");
}

void foo2(char **ptr) {
    *ptr = malloc(255); // Allocating memory for a copy
    strcpy(*ptr, "Hello World\n");
}

int main() {
    char *ptr = NULL;

    foo(ptr);

    foo(&ptr);
    printf("%s\n", ptr);
    
    free(ptr);

    return 0;
}