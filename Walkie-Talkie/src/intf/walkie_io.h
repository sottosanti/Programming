#ifndef __WAKLIE_IO_H__
#define __WAKLIE_IO_H__

#include "walkieApi.h"

/* Prototype Decleration */
void
init_shell(void);

char *
input(const char *out_text);

void
no_over(char *out_text);

void 
walkie(const char *out_text);

void 
walkie_print(const char *out_text);


#endif // __WAKLIE_IO_H__