/**
 * Author: Stephen Sottosanti
 * 
 * Program: Merge Sort
 * O(n) running time algorithm
 * Closely follows the divide-and-conquer paradigm
 * 
 * Divide: Divide the n-element sequence to be sorted into two subsequence of n/2 elements each
 *
 * Conquer: Sort the two subsequences recursively using merge sort
 * 
 * Combine: Merge the two sorted subsequences to produce the sorted answer
 **/
#include "merge.h"

void merge(int* array[], p, q, r){

}

void merge_sort(int* array[]){
    int size = sizeof(array)/ sizeof(array[0]);              
    int p = 0;
    int q = size / 2;
    int r = size - 1;

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