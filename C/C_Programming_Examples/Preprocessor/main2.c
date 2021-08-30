#include <stdio.h>

#define US 0
#define UK 1
#define FRANCE 2
#define GERMNAY 3
#define COUNTRY US 

int main()
{
    #if COUNTRY == US || COUNTRY == UK
        #define GREETING "Hello.\n"
    #elif COUNTRY == FRANCE
        #define GREETING "Bonjour.\n"
    #elif COUNTRY == GERMANY
        #define GREETING "Guten Tag.\n"
    #endif

    printf("Greeting is: %s", GREETING);

    return 0;
}