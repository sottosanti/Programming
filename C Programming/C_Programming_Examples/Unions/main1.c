#include <stdio.h>

struct {
    char *name;
    enum symbolType type;
    union {
        int     i;
        float   f;
        char    c;
    } data;
} table [entries];