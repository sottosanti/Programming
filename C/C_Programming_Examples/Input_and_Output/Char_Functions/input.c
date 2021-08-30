/*

Char Functions              String Functions                Formatting Functions
getc                        gets                            sprint
getchar                     fgets                           fprintf
fgetc                       puts                            fflush
ungetc                      fputs                           fscanf
putc                        getline                         sscanf
putchar
fputc

*/
#include <stdio.h>

/*
int getc(FILE *stream);
This function can return a special value, EOF. It is a special int value
used to indicate end of file
Can be used for any input stream
*/

int main() {
    char ch = '\0';
    FILE *fp;

    if (fp = fopen("someFile.something", "rw"))
    {
        ch = getc(fp);

        while(ch != EOF)
        {
            ch = getc(fp);
        }
        fclose(fp);
    }

    return 0;
}

int main() {
    char ch = '\0';
    FILE *fp;

    ch = getc(stdin);
    printf("read in character %c\n", ch);

    return 0;
}


/*
int getchar(void);
Only reads from stdin

Can also use it with EOF
stdin technically is a file
*/

int main() {
    printf("%c\n", getchar());

    return 0;
}

/*
Can also use it with EOF
stdin technically is a file
want to store it in an integer when working with EOF
C allows you to store characters in ints
ctrl d will cause the EOF signal
*/

int main() {
    int ch = 0;

    while ((ch = getchar()) != EOF)
        printf("%c\n", ch);

    return 0;
}


/*
int fgetc(FILE *fp)

File handling function that reads a character from a file
*/

int main() {
    FILE *fp = NULL;
    char c = '\0';

    fp = fopen ( "someFile.something", "r" ) ; // opening an existing file

    if ( fp == NULL ) {
        printf ( "Could not open file myFIle.c" ) ;
        return 1;
    }

    printf( "Reading the file myFile.c" ) ;

    while ( 1 ) 
    {
        c = fgetc ( fp ) ; // reading the file 

        if ( c = EOF )
            break ;

        printf ( "%c", c ) ;
    }

    printf ( "Closing the file" ) ;
    fclose ( fp ) ;

    return 0;
}


/*
int ungetc(int ch, FILE* stream);

Always check for EOF if you are returning several characters back into a stream
*/

int main() {
    char ch = 0;

    while ( isspace ( ch = ( char ) getchar() )) // Read as long as there is a space
        ;
    ungetc(ch, stdin);  // Put back the nonspace character

    printf("char is %c\n", getchar());
    return 0;
}