#include "bubblesort.h"
#include "heapsort.h"
#include "insert.h"
#include "quick.h"
#include "merge.h"


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;
typedef chrono::high_resolution_clock Clock;

// Data Set Sizes
const size_t SIZE1 = 1000;
const size_t SIZE2 = 2000;
const size_t SIZE3 = 4000;
const size_t SIZE4 = 8000;

ofstream emptyFile("compsout.txt");
ofstream outFile("compsout.txt", ios::app);

int main () {

    //ofstream emptyFile("compsout.txt");
  //  ofstream outFile("compsout.txt", ios::app);
    emptyFile.close();

    // Prototypes
	void fillArray(int[], size_t, int);
    int* copy(int[], size_t);
    void printTable();
    void printStats(int [], int [], int [], size_t, int(*)(int[], size_t));

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

    outFile << "Runtime in microseconds\n\n";

    cout << "Bubble Sort\n";
    outFile << "Bubble Sort\n";
    sort = &bubblesort;
    printTable();
    printStats(rand1, dsort1, asort1, SIZE1, sort);
    printStats(rand2, dsort2, asort2, SIZE2, sort);
    printStats(rand3, dsort3, asort3, SIZE3, sort);
    printStats(rand4, dsort4, asort4, SIZE4, sort);

    cout << "\nInsertion Sort\n";
    outFile << "\nInsertion Sort\n";
    sort = &insert;
    printTable();
    printStats(rand1, dsort1, asort1, SIZE1, sort);
    printStats(rand2, dsort2, asort2, SIZE2, sort);
    printStats(rand3, dsort3, asort3, SIZE3, sort);
    printStats(rand4, dsort4, asort4, SIZE4, sort);

    cout << "\nQuick Sort\n";
    outFile << "\nQuick Sort\n";
    sort = &quicksort;
    printTable();
    printStats(rand1, dsort1, asort1, SIZE1, sort);
    printStats(rand2, dsort2, asort2, SIZE2, sort);
    printStats(rand3, dsort3, asort3, SIZE3, sort);
    printStats(rand4, dsort4, asort4, SIZE4, sort);

    cout << "\nHeap Sort\n";
    outFile << "\nHeap Sort\n";
    sort = &heapsort;
    printTable();
    printStats(rand1, dsort1, asort1, SIZE1, sort);
    printStats(rand2, dsort2, asort2, SIZE2, sort);
    printStats(rand3, dsort3, asort3, SIZE3, sort);
    printStats(rand4, dsort4, asort4, SIZE4, sort);

    cout << "\n3-Way Merge Sort\n";
    outFile << "\n3-Way Merge Sort\n";
    sort = &mergesort;
    printTable();
    printStats(rand1, dsort1, asort1, SIZE1, sort);
    printStats(rand2, dsort2, asort2, SIZE2, sort);
    printStats(rand3, dsort3, asort3, SIZE3, sort);
    printStats(rand4, dsort4, asort4, SIZE4, sort);

    outFile.close();
}

// Makes a copy of given arrays
int* copy(int original[], size_t n) {
	int* copy = new int[n];
	for (int i = 0; i < n; i++) copy[i] = original[i];
	return copy;
}

void printStats(int rand[], int desc[], int asc[], size_t n, int(*sort)(int[],size_t)) {
	int* r = copy(rand, n);
	int* d = copy(desc, n);
	int* a = copy(asc, n);

    auto rT1 = Clock::now();
	int random = sort(r, n);
    auto rT2 = Clock::now();
    
    auto dT1 = Clock::now();
	int descending = sort(d, n);
    auto dT2 = Clock::now();

    auto aT1 = Clock::now();
	int ascending = sort(a, n);
    auto aT2 = Clock::now();

	cout << left << setw(8) << n << setw(18) << random << setw(18) << descending <<
		setw(18) << ascending << setw(18) << chrono::duration_cast<chrono::microseconds>(rT2 - rT1).count() << setw(20) 
        << chrono::duration_cast<chrono::microseconds>(dT2 - dT1).count() << setw(18) << chrono::duration_cast<chrono::microseconds>(aT2 - aT1).count() << endl;

    outFile << left << setw(8) << n << setw(18) << random << setw(18) << descending <<
		setw(18) << ascending << setw(18) << chrono::duration_cast<chrono::microseconds>(rT2 - rT1).count() << setw(20) 
        << chrono::duration_cast<chrono::microseconds>(dT2 - dT1).count() << setw(18) << chrono::duration_cast<chrono::microseconds>(aT2 - aT1).count() << endl;

	delete[] r;
	delete[] d;
	delete[] a;
}

void printTable() {
	cout << left << setw(8) << "Size" << setw(18) << "Random" << setw(18) << "Descending" << setw(18)
		<< "Ascending" << setw(18) << "Runtime Random" << setw(20) << "Runtime Descending" << setw(18)
        << "Runtime Ascending" << endl;

	outFile << left << setw(8) << "Size" << setw(18) << "Random" << setw(18) << "Descending" << setw(18)
		<< "Ascending" << setw(18) << "Runtime Random" << setw(20) << "Runtime Descending" << setw(18)
        << "Runtime Ascending" << endl;
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