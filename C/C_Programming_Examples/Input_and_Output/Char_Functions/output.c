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
putc() enables you to write a single character to a file (or stdout)
    - takes two arguments
        - the character that is to be written into the file
        - the FILE pointer that identifies the file from which the character is to be written to
    - must first call fopen() in write or append mode

The definition:

    int putc(int char, FILE *fp)

Ex:
putc('\n', stdout);
putc('\n', outputFile);

*/

int main() {
    char ch = '\0';
    FILE *fp = NULL;

    if (fp = fopen("someFile.something", "rw")) 
    {
        ch = getc(fp);
        while (ch != EOF)
        {
            putc(ch, fp);
            ch = getc(fp);
        }

        fclose(fp);
    }


    return 0;
}

int main() {
    char ch = 'x';

    putc(ch, stdout);

    return 0;
}

/*
putchar()

Used for writing data
    - a single character at a time
    - the only argument it takes is the character to be displayed
    - it outputs a single character to standard output by default, and always
    - returns the character that was displayed
    - So it allows you to output a message 1 character at a time

Definition:

    int putchar(int c);
    
You can chose to output a selected sequence of characters, from the middle of a string bounded by some kind of delimiter. 
So you can parse strings and put them out
*/

int main() {
    char string[] = "Hello World, \nI am hungry!";
    int i = 0;

    // Outputs erverything other than the \n
    while (string[i] != '\0') 
    {
        if (string[i] != '\n')
            putchar(string[i]);

        i++;
    }

    return 0;
}

int main() {
    int ch = 0;
    
    /* Simulate EOF with ctrl+d */
    while ((ch = getchar()) != EOF) 
        putchar(ch);

    /* ungetc() returns EOF previously read back to stdin */
    ungetc(ch, stdin);

    printf("Goodbye!\n");
    return 0;
}

/*
fputc()

File handling function which is used to write a character into a file
    - it writes a single character at a time to a file
    - moves the file pointer position to the next location to write the character


Definition: int fputc(int character, FILE *stream);

Location: <stdio.h>

On sucess, the character that was written is returned

If a writing error occurs, EOF is returned and the error indicator ferror is set
*/

int main() {
    FILE *fp = NULL;
    char c = '\0';

    fp = fopen("myFile.txt", "w");

    if (fp != NULL) 
    {
        for (c = 'A'; c <= 'Z'; c++)
            fputc(c, fp);
            // fputc(c, stdout);

        fclose(fp);
    }


    return 0;
}