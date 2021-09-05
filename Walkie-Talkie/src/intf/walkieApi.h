#ifndef __SHELLAPI_H__
#define __SHELLAPI_H__

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
    PRINT = 0, // LIST SHOW DISPLAY 
    HDR = 9, // The entire header file; header_file.txt
    FUNC = 10, // Functions of a header file; functions.txt
    PROTO = 11, // Prototypes of the header file; prototypes.txt
    DEF = 12, // Function definitions of the header file; definitions.txt
    ENUM = 13, // Enums of a header file; enums.txt
};

#define DEFAULT_OP   stdout

void
init_shell(void);

char *
input(const char *out_text);

void
no_over(char *out_text);

void 
walkie(const char *out_text);

void 
walkie_print(const char *out_text);

char *
set_functions_l1(char * input_text, uint32_t * SET_FLAGS);

char *
set_functions_l2(char *input_text, uint32_t * SET_FLAGS);

void
run_command(char *input_text, uint32_t command);

// char *
// set_functions_l3(char *input_text);

// void
// run_functions(uint32_t function_flags);


#endif // __SHELLAPI_H__