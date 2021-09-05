#include "walkieApi.h"

char *directories[] = {"aio", "aliases", "alloca", "ar", "argp", "argz", "assert", "byteswap", "complex", "cpio", "crypt",
                    "ctype", "dirent", "dlfcn", "elf", "endian", "envz", "err", "errno", "error", "execinfo", "fcntl", "features",
                    "fenv", "fmtmsg", "fnmatch", "fts", "ftw", "gconv", "getopt", "glob", "gnu-versions", "gnumake", "grp", "gshadow",
                    "iconv", "ifaddrs", "inttypes", "langinfo", "libgen", "libintl", "limits", "link", "locale", "malloc", "math", "memory",
                    "mntent", "monetary", "mqueue", "netdb", "nl_types", "nss", "obstack", "printf", "proc_service", "pthread", "pty", "pwd",
                    "re_comp", "regex", "regexp", "sched", "search", "semaphore", "setjmp", "sgtty", "shadow", "signal", "spawn", "stab",
                    "stdc-predef", "stdint", "stdio_ext", "stdio", "stdlib", "string", "strings", "sudo_plugin", "syscall", "sysexits",
                    "syslog", "tar", "tgmath", "thread_db", "threads", "time", "uchar", "ucontext", "ulimit", "unistd", "utime", "utmp",
                    "utmpx", "values", "wchar", "wctype", "wordexp", "zlib" };

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

void 
walkie_print(const char *out_text)
{
    FILE * output = DEFAULT_OP;
    fprintf(output,"%s%s", YELLOW, out_text);
    fflush(output);
}

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

void
run_command(char * input_text, uint32_t command)
{
    int i = 0;
    FILE *fp = NULL;

    char file[64] = "dict/";
    char token[32] = "\0";
    char * buffer; 

    size_t buff_size = 512;
    size_t num_characters = 0;

    buffer = (char *) malloc(sizeof(char) * buff_size);
    
    if (command == 2049){ // display prototypes for a specific header file
        while(sscanf(input_text, "%s ", token) != EOF) {
            num_characters = strlen(token);
            while(num_characters--){
                input_text++;
            }

            // gets rid of leading space if there is one
            if(*input_text == 32) input_text++;

            for (i = 0; i < sizeof(directories)/sizeof(directories[0]); i++) {
                if (!strcmp(token, directories[i])) {
                    /* Display the prototypes.txt file in the directory specified */
                    strcat(file, directories[i]);
                    strcat(file, "/prototypes.txt");

                    // printf("File is: %s\n", file);

                    if((fp = fopen(file, "r")) == NULL) {
                        // send error that file may have been removed or something
                        printf("prototype file error. %s not found\n", file);
                        free(buffer);
                        return;
                    }

                    while (getline(&buffer, &buff_size, fp) != EOF) {
                        walkie_print(buffer);
                    }
                    walkie_print("\n");
                    walkie("Anything else I can help you with? Over.\n");
                }
            }
        }
    }

    free(buffer);
}