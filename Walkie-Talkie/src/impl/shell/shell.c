/*
  shell - the shell that prompts for input
     
 ********************************************************************
   version: 1.0
   date:    August 2021
   author:  Stephen Sottosanti, stephensottosanti@gmail.com
   history: 
 
 *******************************************************************/
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include "shellApi.h"

int main(void)
{
  
  init_shell();

  char * text = '\0';
  // while(1) {
      text = input(">>> ");
  // }
  printf("%s", text);

  return EXIT_SUCCESS;
}

