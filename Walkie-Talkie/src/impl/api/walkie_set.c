#include "walkie_set.h"

// Will be changed. Not sure how I want to do this part


/*
    This function looks for a word that will be a level1 command. Really just tells us if they want to print 
    or to do something else.

    parameter: char * input_text
        The text that the user inputed 
    
    parameter: uint32_t * SET_FLAGS
        The uint32_t flags integer used to represent commands found.

    return: updated pointer of the input text. It doesn't include the words already read so that they don't get reread  
*/
char *
set_functions_l1(char * input_text, uint32_t * SET_FLAGS)
{
    char token[32] = "\0";
    enum commands command;
    size_t num_characters = 0;

    while(sscanf(input_text, "%s ", token) != EOF) {
        num_characters = strlen(token);
        while(num_characters--){
            input_text++;
        }

        // gets rid of leading space if there is one
        if(*input_text == 32) input_text++;
        
        command = NA;
        switch(*token){
            case 'd': // display, define
                if(++*token != '\0') {
                    switch(*token){
                        case 'i': // check for display
                            if (!strcmp(token, "isplay")) command = PRINT;
                            break;
                        case 'e': // check for define
                            if (!strcmp(token, "efine")) command = EXPLAIN;
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 'e': // explain
                if (!strcmp(token, "explain")) command = EXPLAIN;
                break;
            case 'f': // find
                if (!strcmp(token, "find")) command = PRINT;
                break;
            case 'h': // help. may default to "show functions for.." because "help with strings", user probably wants functions that work with strings 
                if (!strcmp(token, "help")) command = PRINT;
                break;
            case 'l': // list
                if (!strcmp(token, "list")) command = PRINT;
                break;
            case 'n': // need
                if (!strcmp(token, "need")) command = PRINT;
                break;
            case 'p': // print
                if (!strcmp(token, "print")) command = PRINT;
                break;
            case 's': // show
                if (!strcmp(token, "show")) command = PRINT;
                break;
            default:
                break;
        }

        if(command != NA) {
            *SET_FLAGS |= (1 << command);
            break;
        }
    }

    return input_text;
}

/*
    This function looks for a word that will be a level2 commands. Tells us what they want. Functions, definitions, prototypes, etc.  

    parameter: char * input_text
        The text that the user inputed 
    
    parameter: uint32_t * SET_FLAGS
        The uint32_t flags integer used to represent commands found.

    return: updated pointer of the input text. It doesn't include the words already read so that they don't get reread  
*/
char *
set_functions_l2(char * input_text, uint32_t * SET_FLAGS)
{
    char token[32] = "\0";
    enum commands command;
    size_t num_characters = 0;

    if(*SET_FLAGS == 2){ // PRINT
        while(sscanf(input_text, "%s ", token) != EOF) {
            // printf("token: %s\n", token);
            num_characters = strlen(token);
            while(num_characters--){
                input_text++;
            }

            // gets rid of leading space if there is one
            if(*input_text == 32) input_text++;
            
            command = NA;
            switch(*token){
                case 'd': // definitions
                    if (!strcmp(token, "definitions")) command = DEFIN;
                    break;
                case 'e': // enums
                    if (!strcmp(token, "enums")) command = ENUM;
                    break;
                case 'f': // functions 
                    if (!strcmp(token, "functions")) command = FUNC;
                    break;
                case 'h': // header
                    if (!strcmp(token, "header")) command = PRINT;
                    break;
                case 'i': // need
                    if (!strcmp(token, "includes")) command = INCL;
                    break;
                case 'p': // prototypes
                    if (!strcmp(token, "prototypes")) command = PROTO;
                    break;
                case 's': // structs
                    if (!strcmp(token, "structs")) command = STRCT;
                    break;
                default:
                    break;
            }

            if(command != NA) {
                *SET_FLAGS |= (1 << command);
                break;
            }
        }
    }

    return input_text;
}