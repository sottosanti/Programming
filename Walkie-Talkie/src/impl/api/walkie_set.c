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
        
        if(strcmp(token, "list") == 0 || strcmp(token, "show") == 0 || strcmp(token, "display") == 0 || strcmp(token, "print") == 0) {
            command = PRINT;
            *SET_FLAGS = *SET_FLAGS | (1 << command);

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

    while(sscanf(input_text, "%s ", token) != EOF) {
        // printf("token: %s\n", token);
        num_characters = strlen(token);
        while(num_characters--){
            input_text++;
        }

        // gets rid of leading space if there is one
        if(*input_text == 32) input_text++;
        
        if(strcmp(token, "prototypes") == 0) {
            command = PROTO;
            // printf("command: %d and test: %d\n", command, (1 << command));
            *SET_FLAGS = *SET_FLAGS | (1 << command);

            break;
        }
    }

    return input_text;
}