#include "walkie_io.h"

/* 
    Start infinite loop which starts our "shell" where the user can start entering commands

    parameter: none

    return: void
*/
void 
init_shell()
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

/* 
    a python like input function

    parameter: const char *out_text
        Pointer to the string that you want to display before reading input

    return: pointer to the string of the entered input
*/
char *
input(const char *out_text)
{
    FILE * output = DEFAULT_OP;
    
    fprintf(output,"%s%s", GREEN, out_text);
    fflush(output);

    char * buffer = (char*) malloc(sizeof(char) * 100);
    size_t buff_size = 100; // bytes
    
    getline(&buffer, &buff_size, stdin); 

    return buffer;
}

/*
    when the user doesn't say over at the end of a statement. this function will repeat waht the user
    said and take off any punctuation at the end and add on "what? over."

    parameter: char *out_text
        The input text that did not contain the word over 

    return: void
*/
void 
no_over(char *out_text)
{
    FILE * output = DEFAULT_OP;

    char walkie_reply[] = " what? Over.\n";
    char * p = NULL;
    useconds_t usec = 60000;

    // remove any ending punctuation to make output funnier
    for (int i = strlen(out_text) - 1; i >= 0; i--) {
        if (isalpha(out_text[i])) {
            break;
        } else {
            out_text[i] = '\0';
        } 
    }

    printf("%s", YELLOW);
    fprintf(output,"walkie: ");
    usleep(usec);
    fflush(output);

    p = out_text;
    for(; *p; *p++) {
        putc(*p, output);
        usleep(usec);
        fflush(output);
    }

    p = walkie_reply;
    for(; *p; *p++) {
        putc(*p, output);
        usleep(usec);
        fflush(output);
    }
}

/*
    print function for walkie meaning it will print out "walkie: " first and then the desired text, all in yellow 

    parameter: const char *out_text
        Pointer to the text that you would like to print out as walkie

    return: void
*/
void 
walkie(const char *out_text)
{
    FILE * output = DEFAULT_OP;
    const char * p = out_text;
    useconds_t usec = 60000;

    printf("%s", YELLOW);
    fprintf(output,"walkie: ");
    usleep(usec);
    fflush(output);

    for(; *p; *p++) {
        putc(*p, output);
        usleep(usec);
        fflush(output);
    }
}


/*
    function for printing results in yellow. Used to print function names, prototypes, etc. Whatever the user requested, in yellow 

    parameter: const char *out_text
        Pointer to the text that you would like to print out in yellow

    return: void
*/
void 
walkie_print(const char *out_text)
{
    FILE * output = DEFAULT_OP;
    fprintf(output,"%s%s", YELLOW, out_text);
    fflush(output);
}

/*
    function for printing contents of a file. 

    parameter: const char *filename
        Pointer to the text that is the name of the file

    return: void
*/
void
walkie_print_file(const char *filename) 
{
    FILE * fp = fopen(filename, "r");

    if (!fp) {
        // send error that file may have been removed or something
        walkie("I couldn't find ");
        walkie(filename);
        walkie(", over.\n");
        return;
    }

    char * buffer; 
    size_t buff_size = 512;

    buffer = (char *) malloc(sizeof(char) * buff_size);

    walkie_print("\n\n");
    while (getline(&buffer, &buff_size, fp) != EOF) {
        walkie_print("\t\t");
        walkie_print(buffer);
    }
    walkie_print("\n\n");
    
    free(buffer);
    return;
}