#include "walkie_run.h"

char *directories[] = {"aio", "aliases", "alloca", "ar", "argp", "argz", "assert", "byteswap", "complex", "cpio", "crypt",
                    "ctype", "dirent", "dlfcn", "elf", "endian", "envz", "err", "errno", "error", "execinfo", "fcntl", "features",
                    "fenv", "fmtmsg", "fnmatch", "fts", "ftw", "gconv", "getopt", "glob", "gnu-versions", "gnumake", "grp", "gshadow",
                    "iconv", "ifaddrs", "inttypes", "langinfo", "libgen", "libintl", "limits", "link", "locale", "malloc", "math", "memory",
                    "mntent", "monetary", "mqueue", "netdb", "nl_types", "nss", "obstack", "printf", "proc_service", "pthread", "pty", "pwd",
                    "re_comp", "regex", "regexp", "sched", "search", "semaphore", "setjmp", "sgtty", "shadow", "signal", "spawn", "stab",
                    "stdc-predef", "stdint", "stdio_ext", "stdio", "stdlib", "string", "sudo_plugin", "syscall", "sysexits",
                    "syslog", "tar", "tgmath", "thread_db", "threads", "time", "uchar", "ucontext", "ulimit", "unistd", "utime", "utmp",
                    "utmpx", "values", "wchar", "wctype", "wordexp", "zlib" };

char *text_files[] = {"header_file.txt", "functions.txt", "prototypes.txt", "definitions.txt", "enums.txt", "includes.txt", "structs.txt"};

/*
    This function runs the command 

    parameter: char * input_text
        The updated pointer to the input. Looking for name of header file. Will look for more later
    
    paramter: uint32_t command
        The command flags that have been set. each pair of flags creates a unique number. just have to
        check what command equals

    return: void 
*/
void
run_command(char * input_text, uint32_t command)
{
    int i = 0;
    FILE *fp = NULL;

    char file[128] = "my_brain/";
    int index = -1;

    if ((index = find_directory(input_text))  == -1) {
        // error
        walkie("Error with finding the directory");
        return;
    }
    strcat(file, directories[index]);
    strcat(file, "/");

    uint32_t l1_command = command & 255;
    uint32_t l2_command = command >> 8;
    
    switch(l1_command) {
        case 2: // PRINT
            strcat(file, text_files[(walkie_log2(l2_command))]);
            break;
        default:
            break;
    }

    walkie_print_file(file);
    walkie("Anything else I can help you with? Over.\n");

    return;
}


/*
    This function finds the directory

    parameter: char * input_text
        The updated pointer to the input. Looking for name of header file

    return: index to the directory found within directories[] or -1 if not found. 
*/
int
find_directory(char * input_text) 
{
    char token[32] = "\0";
    size_t size = sizeof(directories)/sizeof(directories[0]);
    size_t num_characters = 0;

    while(sscanf(input_text, "%s ", token) != EOF) {
        num_characters = strlen(token);
        while(num_characters--){
            input_text++;
        }

        // gets rid of leading space if there is one
        if(*input_text == 32) input_text++;

        for (int i = 0; i < size; i++) {
            if (!strcmp(token, directories[i])) {
                return i;
            }
        }
    }

    return -1;
}

/*
    This function mimics log2 algorithm using bit shifts 

    parameter: char * input_text
        The updated pointer to the input. Looking for name of header file

    return: index to the directory found within directories[] or -1 if not found. 
*/
int
walkie_log2(uint32_t x)
{
    int i;
    for (i = 0; i < 7; i++){
        if ((x | 1) == 1) break;
        x >>= 1;
    }

    return i;
}