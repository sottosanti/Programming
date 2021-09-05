#ifndef __WALKIEAPI_H__
#define __WALKIEAPI_H__

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

// foreground colours
#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

// enums
enum commands {
    NA = 0, // SKIP
    PRINT = 1, // PRINT LIST SHOW DISPLAY
    EXPLAIN = 2, // Explain the meaning of a term. Ex: explain extern 
    HDR = 8, // The entire header file; header_file.txt
    FUNC = 9, // Functions of a header file; functions.txt
    PROTO = 10, // Prototypes of the header file; prototypes.txt
    DEFIN = 11, // Function definitions of the header file; definitions.txt
    ENUM = 12, // Enums of a header file; enums.txt
    INCL = 13, // The #includes within a specified header file 
    STRCT = 14, // The structs within a specified header file 
};

#define DEFAULT_OP   stdout

#endif // __WALKIEAPI_H__