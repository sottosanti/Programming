/*
  shell - the shell that prompts for input
     
 ********************************************************************
   version: 1.0
   date:    August 2021
   author:  Stephen Sottosanti, stephensottosanti@gmail.com
   history: 
 
 *******************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "walkieApi.h"

int main(void)
{
  
  init_shell();

  char * text = NULL;
  while(1) {
    text = input("talkie: ");
    text[strlen(text) -1] = '\0';

    char * p = text;
    for ( ; *p; ++p) *p = tolower(*p);
    p = NULL;

    char *token = NULL;    
    // token = strstr(text, "over");
    
    if ( !(strstr(text, "over")) ) {
      no_over(text);
      free(text);
      continue;
    } else 
    if ( strstr(text, "over and out") != NULL ) {
      walkie("Til next time talkie, over and out.\n");
      free(text);
      break;
    }

  }

  return EXIT_SUCCESS;
}

