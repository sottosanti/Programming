#include <stdio.h>
#include <stdlib.h>

#define DEBUG (fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)

/* 
To not have it use DEBUG just remove the definition part

#define DEBUG (fmt, ...)

It will now replace any DEBUG macro call with null statements

Advanced:
Can have debug levels. Would have to add another argument
And the debug level can be set at execution time

create global variable
int Debug;

in main:
if (argc > 2)
    Debug = atoi(argv[1]);

#define DEBUG (level, fmt, ...) \
    if(Debug >= level) \
        fprintf(stderr, fmt, __VA_ARGS__)

DEBUG(1, "process(%d, %d)\n", i, j);
DEBUG(2, "return %d\n",val);
DEBUG(3, "Processed %i arguments\n", argc - 1);
DEBUG(3, "arg1 = %i, arg2 = %i\n", arg1, arg2);

Even More Advanced:

#ifdef DEBON // if Debug is on
#define DEBUG (level, fmt, ...) \
    if(Debug >= level) \
        fprintf(stderr, fmt, __VA_ARGS__)
#else
#define DEBUG (level, fmt, ...) // Fill with null statements... don't run debug statements
#endif
*/ 


int process (int i, int j) {
    int val = 0;


    DEBUG("process(%d, %d)\n", i, j);

    val = i * j;

    
    DEBUG("return %d\n",val);

    return val;
}

int main(int argc, char *argv[]) 
{
    int arg1 = 0, arg2 = 0;

    if (argc > 1)
        arg1 = atoi(argv[1]);
    
    if(argc == 3)
        arg2 = atoi(argv[2]);

    DEBUG("Processed %i arguments\n", argc - 1);
    DEBUG("arg1 = %i, arg2 = %i\n", arg1, arg2);

    printf("%i\n", process(arg1, arg2));
    return 0;
}