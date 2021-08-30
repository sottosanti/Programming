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
#include <stdlib.h>
#include <stdio.h>

int main() 
{
    double value = 0;
    char str[] = "3.5 2.5 1.26"; // The string to be converted
    char *pstr = str; // Pointer to the string to be converted
    char *ptr = NULL; // Pointer to character position after conversion

    while(1)
    {
        value = strtod(pstr, &ptr); // Converting starting at pstr
        if(pstr == ptr)
            break;
        else 
        {
            printf("%f", value); // Output the resultant value
            pstr = ptr; // Store start for next conversion
        }
    } 
}