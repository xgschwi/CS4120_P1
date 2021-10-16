// Xavier Gschwind
// 0020358483

#include <cstdlib>
#include <iostream>
#include "merge.h"
using namespace std;

int mergesort(int data[ ], size_t n) {
    int c = 0;

    if (n > 1) {
        int *copy = new int[n];

        for (int i = 0; i < n; i++) copy[i] = data[i];

        merge3Rec(copy, 0, n, data, c);

        for(size_t i = 0; i < n; i++) data[i] = copy[i];
    }
    return c;
}

void merge3Rec(int copy[], size_t l, size_t r, int data[], int& c) {
    
    if (r - l < 2) return;

    size_t midL = l + (r-l)/3;
    size_t midR = l + 2*((r-l)/3) + 1;

    merge3Rec(data, l, midL, copy, c);
    merge3Rec(data, midL, midR, copy, c);
    merge3Rec(data, midR, r, copy, c);

    merge(data, l, midL, midR, r, copy, c);
}

void merge(int copy[ ], size_t left, size_t midL, size_t midR, size_t right, int data[], int& c) {
    size_t i = left;
    size_t j = midL;
    size_t k = midR;
    size_t l = left;

    while ((i < midL) && (j < midR) && (k < right)) {
        if(++c && copy[i] < copy[j]) {
            if(++c && copy[i] < copy[k]) data[l++] = copy[i++];
            else data[l++] = copy[k++];
        }
        else {
            if(++c && copy[j] < copy[k]) data[l++] = copy[j++];
            else data[l++] = copy[k++];
        }
    }

    while (i < midL && j < midR) {
        if(++c && copy[i] < copy[j]) data[l++] = copy[i++];
        else data[l++] = copy[j++];
    }

    while (j < midR && k < right) {
        if(++c && copy[j] < copy[k]) data[l++] = copy[j++];
        else data[l++] = copy[k++];
    }

    while (i < midL && k < right) {
        if(++c && copy[i] < copy[k]) data[l++] = copy[i++];
        else data[l++] = copy[k++];
    }

    while (i < midL) data[l++] = copy[i++];
    while (j < midR) data[l++] = copy[j++];
    while (k < right) data[l++] = copy[k++];
}

