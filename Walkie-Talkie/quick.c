#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(void) 
{
    FILE *fp = fopen("directories.txt", "r");

    char * buffer = NULL;
    size_t buff_size = 16;
    buffer = (char*) malloc(sizeof(char) * buff_size); 
    
    char header_file[] = "/header_file.txt";
    char examples_folder[] = "/examples";
    char structs[] = "/structs.txt";
    char functions[] = "/functions.txt";
    char includes[] = "/includes.txt";
    char prototypes[] = "/prototypes.txt";
    char definitions[] = "/definitions.txt";
    char enums[] = "/enums.txt";

    while(getline(&buffer, &buff_size, fp) != EOF) {
        // char command[128] = "touch dict/";
        char command[128] = "touch dict/";
        buffer[strlen(buffer) -1] = '\0';
        strcat(command, buffer);
        // strcat(command, header_file);
        // strcat(command, examples_folder);
        // strcat(command, structs);
        // strcat(command, functions);
        // strcat(command, includes);
        // strcat(command, prototypes);
        // strcat(command, definitions);
        strcat(command, enums);

        #ifdef TEST
            printf("%s\n", command);
            break;
        #endif
        
        #ifdef RUN
            system(command);
        #endif
        
        // char copyin_command[128] = "cat /usr/include/";
        // strcat(copyin_command, buffer);
        // strcat(copyin_command, ".h > dict/");
        // strcat(copyin_command, buffer);
        // strcat(copyin_command, header_file);

        // #ifdef RUN
        //     system(copyin_command);
        // #endif

        // #ifdef TEST
        //     printf("%s\n", copyin_command);
        //     break;
        // #endif
    } 


    return 0;
}