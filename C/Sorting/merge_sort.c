/*

take an array and split it into two subarrays
and then keep spliting until down to arrays of size 1
then rebuild

using a left cursor and a right cursor
the left cursor points at the beginning of the first subarray
the right cursor points at the beginning of the second subarray
starts with two subarrays of size 1 so you are just comparing two numbers
compare left cursor to the right cursor
if left is smaller
insert first and move left cursor over 1 (if you can)
you get it...

best: O(nlgn)
avg: O(nlgn)
worst: O(nlgn)
*/