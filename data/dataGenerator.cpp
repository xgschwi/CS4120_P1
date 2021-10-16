// Created by Xavier Gschwind, not continuing for current timing
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void randomData();
void sortedData();
void descendingSortedData();


int main () {
    int choice = 0;

    while (choice != -1) {
    cout << "Welcome to the data generator\n"
        << "Type 1 for random data\n"
        << "Type 2 for sorted data\n"
        << "Type 3 for descending sorted data\n"
        << "Type -1 to exit\n";

        cin >> choice;

        if (choice == 1) randomData();
        else if (choice == 2) sortedData();
        else if (choice == 3) descendingSortedData();
    }
}

void randomData() {
    int size = 0;
    int maxVal = 0;
    string fileName;

    cout << "Welcome to random data! What is the number of elements you want?";
    cin >> size;

    cout << "Now what is the max value you want?";
    cin >> maxVal

    cout << "Lastly, what file would you like this written to?";
    cin >> fileName;


    return;
}

void sortedData() {
    return;
}

void descendingSortedData() {
    return;
}