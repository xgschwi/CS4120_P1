#ifndef HEAP_SORT_H
#define HEAP_SORT_H
int heapsort(int [], size_t);

size_t parent(size_t);

size_t leftChild(size_t);

size_t rightChild(size_t);

void makeHeap(int [], size_t, int&);

void heapify(int [], size_t, int&);
#endif