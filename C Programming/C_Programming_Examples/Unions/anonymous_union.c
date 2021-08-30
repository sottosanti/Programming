#include <stdio.h>

struct owner {
    char socsecurity[12];
};

struct leasecompany {
    char name[40];
    char headquarters[40];
};

struct car_data {
    char make[15];
    int status; /* 0 = owned, 1 = leased */
    
    /* Anonymous Union */
    union {
        struct owner owncar;
        struct leasecompany leasecar;
    };
};