#ifndef __WALKIE_RUN_H__
#define __WALKIE_RUN_H__

#include "walkieApi.h"
#include "walkie_io.h"

void
run_command(char *input_text, uint32_t command);

int
find_directory(char * input_text);

int
walkie_log2(uint32_t x);


#endif // __WALKIE_RUN_H__