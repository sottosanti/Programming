#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

void signalHandler( int signalValue );

int main( void )
{
    int i; /* counter used to loop 100 times */
    int x; /* variable to hold random values between 1-50 */

    signal( SIGINT, signalHandler ); /* register signal handler */
    srand( clock() );

    /* output numbers 1 to 100 */
    for ( i = 1; i <= 100; i++ )
    {
        x = 1 + rand() % 50; /* Generate random number to raise SIGINT */

        if ( x == 25 )
            raise( SIGINT );

        printf("%4d", i);

        if ( i % 10 == 0 )
        {
            printf( "\n" ); 
        }
    } /* end for */

    return 0; 
} /* end main */

void signalHandler( int signalHandler )
{
    int response; /* user's response to signal (1 or 2) */

    printf( "%s%d%s\n%s", "\nInterrupt signal ( ", signalValue, ") received.", "Do you wish to continue ( 1 = yes or 2 = no )?");
    scanf( "%d", &response );

    /* check for invalid responses */
    while ( response != 1 && response != 2 )
    [
        printf( "( 1 = yes or 2 = no )? " );
        scanf( "%d", &response );
    ]

    if ( response == 1 )
    {
        /* reregister signal handler for next SIGINT */
        signal( SIGINT, signalHandler );
        
    } else exit( EXIT_SUCCESS );
        
    return;
}