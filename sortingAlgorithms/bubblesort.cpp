// Xavier Gschwind
// 0020358483

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "bubblesort.h"
using namespace std;

int bubblesort(int data[], size_t n) {
	int c = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (++c && data[j] > data[j + 1]) swap(data[j], data[j + 1]);
		}
	}
	return c;
}