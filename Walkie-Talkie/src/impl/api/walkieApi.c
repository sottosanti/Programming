#include "walkieApi.h"

void init_shell()
{
    FILE * output = DEFAULT_OP;

    fprintf(output,"%sWalkie-Talkie 1.0\n", WHITE);
    fprintf(output,"%sType \"help\", \"copyright\", \"credits\" or \"license\" for more information.\n\n\n", WHITE);
    fprintf(output,"%sI'm walkie and you're talkie, lets chat.\n", YELLOW);
    fprintf(output,"\t%strying to complete a project, module, assigment and need quick access to function defintions?\n\n", YELLOW);
    fprintf(output,"\t%sWell my creator filled me with every function there is so just ask. I'm a C manual that you can talk to!\n\n", YELLOW);
    fprintf(output,"\t%sType help for a list of the commands and don't forget to end each statement with \"over\"\n", YELLOW);
    fprintf(output,"\t%sand if you're done just type \"over and out\", Over.\n\n", YELLOW);
    
    fflush(output);
}

char *input(const char *out_text)
{
    FILE * output = DEFAULT_OP;
    fprintf(output,"%s%s", GREEN, out_text);
    fflush(output);

    char * buffer = (char*) malloc(sizeof(char) * 100);
    size_t buff_size = 100; // bytes
    
    getline(&buffer, &buff_size, stdin); 

    return buffer;
}

void no_over(char *out_text)
{
    FILE * output = DEFAULT_OP;

    // remove any ending punctuation to make output funnier
    for (int i = strlen(out_text) - 1; i >= 0; i--) {
        if (isalpha(out_text[i])) {
            break;
        } else {
            out_text[i] = '\0';
        } 
    }
    
    fprintf(output,"%swalkie: %s what? Over.\n", YELLOW, out_text);
    fflush(output);
}

void walkie(const char *out_text)
{
    FILE * output = DEFAULT_OP;
    
    fprintf(output,"%swalkie: %s", YELLOW, out_text);
    fflush(output);
}