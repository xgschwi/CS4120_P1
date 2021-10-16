// Xavier Gschwind
// 0020358483

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "insert.h"
using namespace std;

int insert(int data[], size_t n) {
	int c = 0;

	int index = 0;
	int j = 0;
	for (int i = 1; i < n; i++)
	{
		index = data[i];
		j = i - 1;

		while (j >= 0 && ++c && data[j] > index) {
			data[j + 1] = data[j]; // Shift elements to the right
			j--; // move towards front of list
		}
		data[j + 1] = index;
	}
	return c;
}