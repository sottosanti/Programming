/*
  shell - the shell that prompts for input
     
 ********************************************************************
   version: 1.0
   date:    August 2021
   author:  Stephen Sottosanti, stephensottosanti@gmail.com
   history: 
 
 *******************************************************************/

#include "walkieApi.h"

int main(void)
{
  
  init_shell();

  char * text = NULL;
  char * ptr = NULL;
  uint32_t FLAGS = 0;

  while(1) {
    text = input("talkie: ");
    text[strlen(text) -1] = '\0';

    ptr = text;
    for ( ; *ptr; ++ptr) *ptr = tolower(*ptr);
    ptr = NULL;
    
    if ( !(strstr(text, "over")) ) {
      no_over(text);
      free(text);
      text = NULL;
      continue;
    } 
    else if ( strstr(text, "over and out") != NULL ) {
      walkie("Til next time talkie, over and out.\n");
      free(text);
      text = NULL;
      break;
    }

    ptr = text;
    ptr = set_functions_l1(text, &FLAGS);
    
    if(FLAGS <= 0) {
      // call l1 error
      printf("uh oh, l1 error. Over.\n");
      break;
    }
    
    ptr = set_functions_l2(ptr, &FLAGS);
    
    if(FLAGS <= 255) {
      // call l1 error
      printf("uh oh, l2 error. Over.\n");
      break;
    }

    run_command(ptr, FLAGS);

    // if(ptr != NULL) {
    //   printf("ptr: %s\n", ptr);
    // }

  }

  return EXIT_SUCCESS;
}

