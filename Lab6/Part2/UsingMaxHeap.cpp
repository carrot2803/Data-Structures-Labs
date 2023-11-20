#include <cstring>
#include <iostream>

#include "MaxHeap.h"
using namespace std;

int main() {
    // Lab #6, Part 2

    MaxHeap* heap;
    int size;
    bool isHeap;
    char filename[25];

    cout << "Lab #6, Part 2" << endl << endl;

    int A[10] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

    // Write the code here for Lab #6, Part 2 (a)

    heap = initMaxHeapFromArray(A, 10);
    displayMaxHeap(heap);
    cout << endl;
    if (isMaxHeap(heap))
        cout << "It is a max-heap." << endl;
    else
        cout << "It is NOT a max-heap." << endl;

    // Write the code here for Lab #6, Part 2, Problem 2 (b, c, d)

    strcpy(filename, "maxheap1.txt");

    heap = initMaxHeapFromFile(filename);
    displayMaxHeap(heap);
    cout << endl;
    if (isMaxHeap(heap))
        cout << "It is a max-heap." << endl;
    else
        cout << "It is NOT a max-heap." << endl;

    strcpy(filename, "maxheap2.txt");

    heap = initMaxHeapFromFile(filename);
    displayMaxHeap(heap);
    cout << endl;
    if (isMaxHeap(heap))
        cout << "It is a max-heap." << endl;
    else
        cout << "It is NOT a max-heap." << endl;

    strcpy(filename, "maxheap3.txt");

    heap = initMaxHeapFromFile(filename);
    displayMaxHeap(heap);
    cout << endl;
    if (isMaxHeap(heap))
        cout << "It is a max-heap." << endl;
    else
        cout << "It is NOT a max-heap." << endl;

    return 0;
}
