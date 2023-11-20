#include "MaxHeap.h"

#include <fstream>
#include <iostream>
using namespace std;

MaxHeap* initMaxHeap() {
    MaxHeap* heap;

    heap = new MaxHeap;
    heap->size = 0;

    return heap;
}

MaxHeap* initMaxHeapFromArray(int A[], int numElements) {
    MaxHeap* heap;

    heap = new MaxHeap;

    for (int i = 0; i < numElements; i++) {
        heap->A[i + 1] = A[i];
    }

    heap->size = numElements;

    return heap;
}

MaxHeap* initMaxHeapFromFile(char filename[100]) {
    ifstream inputFile;
    MaxHeap* heap;
    int index;
    int num;

    inputFile.open(filename);

    if (!inputFile.is_open()) {
        cout << "File could not be opened to create heap: " << filename << endl;
        return NULL;
    }

    heap = new MaxHeap;

    index = 0;

    inputFile >> num;
    while (!inputFile.eof()) {
        index++;
        heap->A[index] = num;
        inputFile >> num;
    }

    inputFile.close();

    heap->size = index;

    return heap;
}

// Write the code for the following functions (Lab #6, Part 2)

void displayMaxHeap(MaxHeap* heap) {
    for (int i = 1; i <= heap->size; i++) cout << heap->A[i] << " ";
}

int sizeMaxHeap(MaxHeap* heap) { return heap->size; }

bool isEmptyMaxHeap(MaxHeap* heap) { return heap->size == 0; }

bool maxHeapPropertyHolds(MaxHeap* heap, int i) {
    if (i > heap->size || i < 1) return false;
    if (i == 1) return true;
    int parent = i / 2;
    return heap->A[parent] >= heap->A[i];
}

bool isMaxHeap(MaxHeap* heap) {
    for (int i = 1; i <= heap->size; i++) {
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left < heap->size && heap->A[left] > heap->A[i]) return false;
        if (right < heap->size && heap->A[right] > heap->A[i]) return false;
    }
    return true;
}
