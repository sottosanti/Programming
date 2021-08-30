#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *hello_return(void * args)
{
    // Allocate a new string for the heap with "Hello World!"
    char * hello = strdup("Hello World!\n");
    return (void *) hello;
}

int main(int argc, char * argv[])
{
    char * str;
    pthread_t thread; // thread identifier

    // create a new thread that runs hello_return without arguments
    pthread_create(&thread, NULL, hello_return, NULL);

    // Wait until thread completes, assign return value to str
    pthread_join(thread, (void **) &str);
    pthread_exit(NULL);
    printf("%s", str);

    return 0;
}