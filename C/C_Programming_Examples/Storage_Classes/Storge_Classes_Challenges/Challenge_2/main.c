/**
* Challenge 1: Write a C program that finds the sum of various numbers
*   - you can't pass any variable representing the running total to the sum() function
*
*/
#include <stdio.h>

int sum (int num){
    static int var_sum =  0;

    var_sum += num;
    return var_sum;
}

int main(){
    printf("%d ", sum(25));
    printf("%d ", sum(15));
    printf("%d\n", sum(30));

    return 0;
}