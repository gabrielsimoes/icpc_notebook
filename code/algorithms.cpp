#include <algorithm> 
// sort, search, array
sort(startaddress, endaddress)
binary_search(startaddress, endaddress, valuetofind)
reverse(first_iterator, last_iterator)
*max_element (first_iterator, last_iterator) 
*min_element (first_iterator, last_iterator) 
accumulate(first_iterator, last_iterator, initial value of sum) //summation of vector elements
count(first_iterator, last_iterator,x) //occurrences of x
find(first_iterator, last_iterator, x) // points to last if not found
lower_bound(first_iterator, last_iterator, x) //first element in range [first, last) which has a value not less than x
upper_bound(first_iterator, last_iterator, x) 
arr.erase(position to be deleted) // erased element in vector
arr.erase(unique(arr.begin(),arr.end()),arr.end()) // erases the duplicate occurrences in sorted vector in a single line.
next_permutation(first_iterator, last_iterator) 
prev_permutation(first_iterator, last_iterator)
distance(first_iterator,desired_position) //very useful while finding the index.
all_of(ar, ar+6, [](int x) { return x>0; }) ?//check every element for condition
any_of() //check if there is an element with condition
none_of() //check if none 
copy_n(source, size, dest) //copy one array into another
iota(ar, ar+6, 20); // ar = 20, 21, 22, 23, 24, 25

// partition
partition(beg, end, condition)
is_partitioned(beg, end, condition)
stable_partition(beg, end, condition) //order is preserved
partition_point(beg, end, condition) //returns iterator pointing to partion point
partition_copy(beg, end, beg1, beg2, condition) // separate between true and false

