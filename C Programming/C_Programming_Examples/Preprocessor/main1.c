#include <stdio.h>

#define MYDEF 5
#define MYOTHERDEF 2

#ifdef UNIX
#   define DATADIR "/uxn1/data"
#else
#   define DATADIR "\\usr\\data"
#endif

/*
Or define on the command line:

gcc -D DATADIR=/c/my_data
*/

int main(void)
{
    #if MYDEF == 5 && MYOTHERDEF == 2
        printf("Hello\n");
    #endif

    return 0;
}