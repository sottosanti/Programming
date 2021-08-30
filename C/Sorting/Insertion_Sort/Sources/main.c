/**
 * Author: Percy Knox
 * 
 * Program: Insertion Sort
 * O(n) running time algorithm
 * An effiecient algorithm for sorting a small number of elements
 * 
 **/

#include "insertion.h"

void insertion_sort(int* array[]){
    int i, j, key;
    int size = sizeof(array)/ sizeof(array[0]);              

    for(j = 1; j < size; j++){
        key = array[j];
        
        // Insert array[j] into the sorted sequence array[1.. j-1]
        i = j - 1;
        while(i >= 0 && array[i] > key){
            array[i+1] = array[i];
            i--; 
        }

        array[i+1] = key;
    }

    //return sorted array
}