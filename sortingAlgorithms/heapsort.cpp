#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "heapsort.h"
using namespace std;

int heapsort(int data[ ], size_t n) {
    int c = 0;

    makeHeap(data, n, c);

    for (int i = n; i > 1; --i) {
        swap(data[0], data[i]); // root swapped with end
        heapify(data, i, c); 
    }

    return c;
}

size_t parent(size_t i) {
    return (i-1)/2;
}
size_t leftChild(size_t i) {
    return (2*i) + 1;
}

size_t rightChild(size_t i) {
    return (2*i) + 2;
}

void makeHeap(int data[ ], size_t n, int& c)  {
    size_t i, j;

    for (int i = 1; i < n; ++i) {
        j = i;
        while (j > 0 && (++c && data[j] > data[parent(j)])) {
            swap(data[j], data[parent(j)]);
            j = parent(j);
        }
    }
}

void heapify(int data[ ], size_t n, int& c) {
    size_t i, largeIndex;
    bool heapified = false;

    i = 0;
    while ((!heapified) && (leftChild(i) < n)) {
        if (rightChild(i) >= n) largeIndex;
        else if (++c && data[leftChild(i)] > data[rightChild(i)]) largeIndex = leftChild(i);
        else largeIndex = rightChild(i);

        if (++c && data[i] < data[largeIndex]) {
            swap(data[i], data[largeIndex]);
            i = largeIndex;
        }
        else heapified = true;
    }
}