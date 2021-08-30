/*

Char Functions      String Functions        Formatting Functions        Analyzing Strings
getc                gets                    sprint                      islower()
getchar             fgets                   fprintf                     isupper()
fgetc               puts                    fflush                      isalpha() - uppercase or lowercase letter
ungetc              fputs                   fscanf                      isalnum() - uppercase or lowercase letter or digit
putc                getline                 sscanf                      iscntrl() - control character
putchar                                                                 isprint() - any printing character including space
fputc                                                                   isgraph() - Any printing character except space
                                                                        isdigit() - Decimal digit ('0' to '9')
                                                                        isxdigit() - Hexadecimal digit ('0' to '9', 'A' to 'F', 'a' to 'f')
                                                                        isblank() - Standard blank characters (space, '\t')
                                                                        isspace() - Whitespace character (space, '\n', '\t', '\v', '\r', '\f')
                                                                        ispunct() - Printing character for which isspace() and isalnum() return false   

Converting Strings to Numbers
The stdlib.h header file declares functions that you can use to conert a string to a numerical value
These functions can also be reversed

atof() - returns a value of type double that is produced from the string argument. Infinity as a double value
        is recognized from the strings "INF" or "INFINITY" where any character can be in uppercase or lowercase
        and 'not a number' is recognized from the string "NAN" in uppercase or lowercase

atoi() - returns a value of type int that is produced from the string argument

atol() - returns a value of type long that is produced from the string argument

atoll() - returns a value of type long long that is produced from the string argument 

strtod() - returns a value of type double that is produced from the initial part of the string specified by the first argument.
        The second argument is a pointer to a variable, ptr say, of type char* in which the function will store the address of the
        first character following the substring that was converted to the double value. If no string was converted to type double, 
        the variable ptr will contain the address passed as the first argument

strtof() - returns a value of type float. In all other respects it works as strtod()

strtold() - returns a value of type long double. In all other respects it works as strtod()

*/
#include <stdio.h>
#include <string.h> /* strchr */
#include <stdlib.h> /* exit() */
#include <malloc.h>

/*
gets()

Stands for get string and reads a line from standard input into a buffer
    - reads until a terminating newline or end-of-file (EOF) is found
    - takes one argument, a pointer to an array of chars where the string is stored
    - returns str on sucess, and NULL on error or when end of file occurs

Decleration: char *gets(char *str)

This function is deprecated and should never be used
    - removed from C11

Other options that are from C99 are fgets() or getchar()

The gets() function does not check for buffer overflow 

*/

/*
fgets()

Used for reading entire lines of data from a file/stream (file get string)
    - similar to gets except:
        - takes in number of characters to be read
        - an input stream (when specified as stdin, same behavior as gets())

Decleration: char *fgets(char *buffer, int n, FILE *stream)
- Buffer is a pointer to a character array where the line that is read in will be stored
- n is an integer value that represents the maximum number of characters to be stored into buffer, including the null character
- Stream is the pointer to object that identifies the stream where characters are read from
    - usually used with a file stream, however, standard input stream is also acceptable

Reads characters from the specified file until a newline character has been read or until n-1 characters have been read (whichever occurs first)
    - a null character is written immediately after the last character read into the array
    - returns the value of buffer if the read is successful
    - returns the value NULL if an error occurs on the read or if an attempt is made to read past the end of the file

It is also deprecated because the function cannot tell whether a null character is included in the string it reads
    - if a null character is read it will be stored in the string along with the rest of the characters read
        - since a null character terminates a string, this will end your string prematurely, right before the first null character

Only use fgets if you are certain the data read cannot contain a null character
    - otherwise, use getline
*/

int main()
{
    char buf[255];
    int ch = '\0';
    char *p = NULL;

    if (fgets(buf, sizeof(buf), stdin))
    {
        p = strchr(buf, '\n');
        
        if (p) 
        {
            *p = '\0'; /* add null terminator right after the line feed */
        }
        else
        {
            while (((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin));
        }
    }
    else
    {
        /* fgets failed handle error */
    }

    printf("buf contains: %s\n", buf);
    return 0;
}

/*
getline

The latest function for reading a string of text
    - fairly new C library function, 2010 or so

It is the preferred method for reading lines of text from a stream (including standard input)
    - the other standard functions, including gets, fgets, and scanf, are too unreliable

The getline function reads an entire line from a stream
    - up to and including the next newline character and takes three parameters

Decleration: ssize_t getline(char **buffer, size_t *size, FILE *stream);
- the first parameter is a pointer to a block allocated with malloc or calloc (type char **)
    - the address of the first character position where the input string will be stored
        - this pointer type (a pointer-pointer) causes massive confusion
    - will automatically enlarge the block of memory as needed (realloc)
        - there is never shortage of space (why getline is so safe)
    - will contain the line read by getline when it returns
- the second parameter is a pointer to a variable of type size_t
    - specifies the size in bytes of the block of memory pointed to by the first parameter
    - the address of the variable that holds the size of the input buffer, another pointer
- the third parameter is simply the stream from which to read the line

- if an error occurs, such as end of file being reached without reading any bytes, getline returns -1
    - otherwise, returns the number of characters read (up to and including the newline, but not the final null character)

*/

int main()
{
    char *buffer = NULL;
    size_t buffsize = 32;
    size_t characters;

    buffer = (char *)malloc(buffsize * sizeof(char));

    if (buffer == NULL)
    {
        exit(1);
    }

    printf("Type something: ");
    characters = getline(&buffer, &buffsize, stdin);

    printf("%zu characters were read.\n", characters);
    printf("You typed: '%s'\n", buffer);

    return 0;
}

int main()
{
    char buffer[32];
    char *b = buffer;
    size_t buffsize = 32;
    size_t characters;

    printf("Type something: ");
    characters = getline(&b, &buffsize, stdin);

    printf("%zu characters were read.\n", characters);
    printf("You typed: '%s'\n", buffer);

    return 0;
}