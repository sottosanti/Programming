#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fp = NULL;
    char buff[255];

    fp = fopen("data.txt", "r");

    while(fscanf(fp, "%s", buff) != EOF)
    {
        printf("%s", buff);
    }

    fclose(fp);
    return 0;
}