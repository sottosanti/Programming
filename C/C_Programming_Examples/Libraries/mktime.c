#include <stdio.h>
#include <time.h>

int main(void)
{
    const char *day[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const char *month[12] = {"Januray", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    const char *suffix[] = { "st", "nd", "rd", "th"};

    enum sufindex { st, nd, rd, th } sufsel = th; // Suffix selector

    struct tm birthday = {0};
    char name[30] = {'\0'};

    printf("Enter a name: ");
    scanf("%s", name);

    printf("Enter the birthday for %s as day month year integers seperated by spaces.",
            "\ne.g. Enter 1st February 1985 as 1 2 1985 : ");

    scanf("%d %d %d", &birthday.tm_mday, &birthday.tm_mon, &birthday.tm_year);

    birthday.tm_mon -= 1;
    birthday.tm_year -= 1900;

    if(mktime(&birthday) == -1) {
        fprintf(stderr, "Operation failed.\n");
        return 1;
    }

    switch(birthday.tm_mday)
    {
        case 1: case 21: case 31:
            sufsel = st;
            break;
        case 2: case 22:
            sufsel = nd;
            break;
        case 3: case 23:
            sufsel = rd;
            break;
        default:
            sufsel = th;
            break;
    }

    printf("%s was born on the %d%s %s %d, which was a %s.\n", name, birthday.tm_mday, suffix[sufsel], month[birthday.tm_mon], birthday.tm_year, day[birthday.tm_wday]);

    return 0;
}