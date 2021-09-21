/*

a pivot is going to be how it is going to seperate
used to create subarrays
all the way down until it is an arra of size of 1 or 2
divide and conquer approach
using recursion

after choosing a pivot everything to the left is less than the pivot and everything to the right of it is greater than it
can pick the first element and then sort it
left subarray is to the left of pivot in new spot, right subarray is to the right of the pivot
repeat everything with the new subarrays as if they were the original array
until the array is of size 1 or 2

best: O(nlgn)
avg: O(nlgn)
worst: O(n^2)
*/