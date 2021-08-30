#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main() 
{
    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);

    /*
        When stopped, search for the process using:
        $ ps

        then pass the signal continue to the process with:
        $ kill -s SIGCONT 9499(PID)
    */
    printf("I am back\n\n");

    return 0;
}