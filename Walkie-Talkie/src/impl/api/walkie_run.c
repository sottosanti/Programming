#include "walkie_run.h"

char *directories[] = {"aio", "aliases", "alloca", "ar", "argp", "argz", "assert", "byteswap", "complex", "cpio", "crypt",
                    "ctype", "dirent", "dlfcn", "elf", "endian", "envz", "err", "errno", "error", "execinfo", "fcntl", "features",
                    "fenv", "fmtmsg", "fnmatch", "fts", "ftw", "gconv", "getopt", "glob", "gnu-versions", "gnumake", "grp", "gshadow",
                    "iconv", "ifaddrs", "inttypes", "langinfo", "libgen", "libintl", "limits", "link", "locale", "malloc", "math", "memory",
                    "mntent", "monetary", "mqueue", "netdb", "nl_types", "nss", "obstack", "printf", "proc_service", "pthread", "pty", "pwd",
                    "re_comp", "regex", "regexp", "sched", "search", "semaphore", "setjmp", "sgtty", "shadow", "signal", "spawn", "stab",
                    "stdc-predef", "stdint", "stdio_ext", "stdio", "stdlib", "string", "strings", "sudo_plugin", "syscall", "sysexits",
                    "syslog", "tar", "tgmath", "thread_db", "threads", "time", "uchar", "ucontext", "ulimit", "unistd", "utime", "utmp",
                    "utmpx", "values", "wchar", "wctype", "wordexp", "zlib" };

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