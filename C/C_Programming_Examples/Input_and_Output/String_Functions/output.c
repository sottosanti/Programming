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
#include <stdlib.h>
#include <string.h>

/*
puts

Used to write a line to the output screen
    - the most convenient function for printing a simple message on standard output 
    - automatically appends a newline

It is simpler than printf, since you don't need to include a newline character

The difference between puts and printf is that when using printf the argument is interpreted as a fromatting string
    - result will be often the same (except for the added newline) if the string doesn't contain any control characters (%)
    - if you cannot rely on that you should not use puts

The puts function is safe and simple, but not very flexible as it does not give us an option for formatting our string

Decleration: int puts(const char *string)

*/

int main()
{
    char string[40];
    strcy(str, "Hello World!");
    puts(string);

    return 0;
}

/*
fputs

Writes a line of characters to a specific file
    - does not automatically add a newline character
    - returns EOF on error

Decleration: int fputs(const char * buffer, FILE *filePtr);

*/

int main()
{
    FILE *fp = NULL;
    fp = fopen("somefile.txt", "w");

    if (fp == NULL)
    {
        exit(1);
    }

    fputs("What's up World!", fp);

    /* Close the file */
    fclose(fp);

    return 0;
}