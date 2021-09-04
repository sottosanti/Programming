/*
  caesar - paste in a text and have it rotated 
     
 ********************************************************************
   version: 1.0
   date:    September 2021
   author:  Stephen Sottosanti, stephensottosanti@gmail.com
 
   description: 
 *******************************************************************/

#include "cipher.h"

int main(void) {

  FILE * output = DEFAULT_OP;

  fprintf(output, "%sPress enter for the defaults\n", WHITE);
  fprintf(output, "%sHow many characters? (default is 32): ", WHITE);
  fflush(output);

  int buff_size = 32;
  int ch = 0;

  if((ch = getchar()) != '\n'){
    ungetc(ch, stdin);
    fscanf(DEFAULT_IP, "%d", &buff_size);
  }

  if(buff_size <= 0) {
    fprintf(output, "%s%d? Why'd you even start me then? Smh.\n", WHITE, buff_size);
    exit(0);
  }

  char * buffer = (char*) malloc(sizeof(char) * buff_size);
  getline(&buffer, &buff_size, stdin);
  
  fprintf(output, "\n%sEnter number of rotations. (Default is 25): \n", WHITE);
  fflush(output);
}