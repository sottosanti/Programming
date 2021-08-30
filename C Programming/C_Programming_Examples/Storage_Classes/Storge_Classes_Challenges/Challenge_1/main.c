/**
* Challenge 1: Write a small program that declares the following variables
*   - an int variable with block scope and temporary storage
*   - a global double variable that is only accessible inside this file
*   - a global float variable that is accessible within the entire program
*   - a float local variable with permanent storage
*   - a register int variable
*   - a function that is only accessible with the file it is defined 
*
*
*/
#include <stdio.h>

// a function that is only accessible with this file
static void myFunction(void) {}

// a global double variable, only accessible inside this file
static double var_global_local = 10;

// a global float variable that is accessible with the entire program
float var_global = 10;


int main() {

    // an int variable with block scope and temperary storage
    auto int var_auto_int = 0;

    // a float local variable with permanent storage
    static float var_float = 0;

    // a register int variable
    register int var_register = 0; 
    return 1;
}