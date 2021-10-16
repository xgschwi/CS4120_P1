#include "bubblesort.h"
#include "heapsort.h"
#include "insert.h"
#include "quick.h"
#include "merge.h"


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
// Data Set Sizes
const size_t SIZE1 = 1000;
const size_t SIZE2 = 2000;
const size_t SIZE3 = 4000;
const size_t SIZE4 = 8000;

int main () {
    // Prototypes
	void fillArray(int[], size_t, int);
    void printTable(int[][2]);

	// Function pointer to sorting functions
	int (*sort)(int[], size_t);


    // Stores comparisons and runtime
    int stats[12][2];

    // Random Arrays
	int rand1[SIZE1];
	int rand2[SIZE2];
	int rand3[SIZE3];
	int rand4[SIZE4];

    // Sorted Arrays
	int dsort1[SIZE1];
	int dsort2[SIZE2];
	int dsort3[SIZE3];
	int dsort4[SIZE4];

	int asort1[SIZE1];
	int asort2[SIZE2];
	int asort3[SIZE3];
	int asort4[SIZE4];

    fillArray(rand1, SIZE1, 0);
    fillArray(asort1, SIZE1, 1);
    fillArray(dsort1, SIZE1, 2);

    fillArray(rand2, SIZE2, 0);
    fillArray(asort2, SIZE2, 1);
    fillArray(dsort2, SIZE2, 2);

    fillArray(rand3, SIZE3, 0);
    fillArray(asort3, SIZE3, 1);
    fillArray(dsort3, SIZE3, 2);

    fillArray(rand4, SIZE4, 0);
    fillArray(asort4, SIZE4, 1);
    fillArray(dsort4, SIZE4, 2);

    int res = heapsort(rand1, SIZE1);
    cout << res << endl;
    for (int i = 0; i < SIZE1; i++) {
        cout << rand1[i] << endl;
    }


}

void fillArray(int arr[], size_t n, int type ) {
    string line;
    int i = 0;
    ifstream inFile;

    if (n == SIZE1 && type == 0) {
        inFile.open("../data/rand1000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }
    else if (n == SIZE1 & type == 1) {
        inFile.open("../data/sort1000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }
    else if (n == SIZE1 & type == 2) {
        inFile.open("../data/desc1000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }

    else if (n == SIZE2 & type == 0) {
        inFile.open("../data/rand2000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }
    else if (n == SIZE2 & type == 1) {
        inFile.open("../data/sort2000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }
    else if (n == SIZE2 & type == 2) {
        inFile.open("../data/desc2000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }

    else if (n == SIZE3 & type == 0) {
        inFile.open("../data/rand4000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }
    else if (n == SIZE3 & type == 1) {
        inFile.open("../data/sort4000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }
    else if (n == SIZE3 & type == 2) {
        inFile.open("../data/desc4000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }

    else if (n == SIZE4 & type == 0) {
        inFile.open("../data/rand8000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }
    else if (n == SIZE4 & type == 1) {
        inFile.open("../data/sort8000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }
    else if (n == SIZE4 & type == 2) {
        inFile.open("../data/desc8000.txt");
        while ( getline(inFile, line)) {
            arr[i] = stoi(line);
            i++;
        }
    }

    inFile.close();
}