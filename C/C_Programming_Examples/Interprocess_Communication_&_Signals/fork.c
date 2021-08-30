#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    fork();

    print("Hello World!\n");

    return 0;
}