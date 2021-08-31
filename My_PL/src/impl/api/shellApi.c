#include "shellApi.h"

void init_shell()
{
    FILE * output = DEFAULT_OP;
    fprintf(output,"%sWalkie-Talkie 1.0\n", WHITE);
    fflush(output);

    fprintf(output,"%sType \"help\", \"copyright\", \"credits\" or \"license\" for more information.\n\n\n", WHITE);
    fflush(output);

    fprintf(output,"%sEnjoy using Walkie-Talkie. Over.\n", YELLOW);
    fflush(output);
}

char *input(const char *out_text)
{
    FILE * output = DEFAULT_OP;
    fprintf(output,"%s%s ", YELLOW, out_text);
    fflush(output);

    // char ch = 0;

    // while((ch = (char) getchar()) != EOF) // Read as long as there is a space
    //     ;

    char * result = "success";
    return result;
}