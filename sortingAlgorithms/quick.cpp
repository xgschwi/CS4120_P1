// Xavier Gschwind
// 0020358483

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include "quick.h"
using namespace std;

int quicksort(int data[ ], size_t n) {
    int c = 0;

    size_t pivot_index; // Array index for the pivot element
    size_t n1;          // Number of elements before the pivot element
    size_t n2;          // Number of elements after the pivot element

    if (n > 1) {
        // Partition the array, and set the pivot index.
        partition(data, n, pivot_index, c);

        // Compute the sizes of the subarrays.
        n1 = pivot_index;
        n2 = n - n1 - 1;
        
        // Recursive calls to sort the subarrays.
        c += quicksort(data, n1);
        c += quicksort((data + pivot_index + 1), n2);
    }
    return c;
}

void partition(int data[ ], size_t n, size_t& pivot_index, int& c) {

    size_t large = 1;
    size_t small = n-1;
    int middle = (large + small) / 2; // Median pivot implementation
    int pivot = data[middle]; // Median pivot implementation

    while (large <= small) {
        while ((large < n) && (++c && data[large]<=pivot)) large++;
        while (++c && data[small] > pivot) small--;
        if (large < small) swap (data[large], data[small]);
    }

    pivot_index = small;
    data[0] = data[pivot_index];
    data[pivot_index] = pivot;
}