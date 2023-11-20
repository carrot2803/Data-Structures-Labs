#include "MaxHeap.h"

#include <fstream>
#include <iostream>
using namespace std;

MaxHeap* initMaxHeap() {
    MaxHeap* heap = new MaxHeap;
    heap->size = 0;
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
        exit(1);
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

MaxHeap* initMaxHeapFromArray(int A[], int numElements) {
    MaxHeap* heap = new MaxHeap;
    for (int i = 0; i < numElements; i++)
        heap->A[i + 1] = A[i];
    heap->size = numElements;
    return heap;
}

void displayMaxHeap(MaxHeap* heap) {
    for (int i = 1; i <= heap->size; i = i + 1)
        cout << heap->A[i] << " ";
    cout << endl;
}

int sizeMaxHeap(MaxHeap* heap) {
    return heap->size;
}

bool isEmptyMaxHeap(MaxHeap* heap) {
    return (heap->size == 0);
}

bool maxHeapPropertyHolds(MaxHeap* heap, int i) {
    if (i < 1 || i > heap->size) return false;
    if (i == 1) return true;
    int parent = i / 2;
    return (heap->A[parent] >= heap->A[i]);
}

bool isMaxHeap(MaxHeap* heap) {
    int heapSize = heap->size;
    for (int i = 2; i <= heapSize; i++)
        if (!maxHeapPropertyHolds(heap, i))
            return false;
    return true;
}

void maxHeapify(MaxHeap* heap, int i) {
    int left, right, largest;

    left = i * 2;
    right = i * 2 + 1;

    if (left <= heap->size && heap->A[left] > heap->A[i])
        largest = left;
    else
        largest = i;

    if (right <= heap->size && heap->A[right] > heap->A[largest])
        largest = right;

    if (largest != i) {
        int temp = heap->A[i];
        heap->A[i] = heap->A[largest];
        heap->A[largest] = temp;
        maxHeapify(heap, largest);
    }
}

int maximum(MaxHeap* heap) {
    return heap->A[1];
}

int deleteMaxHeap(MaxHeap* heap, int i) {
    int toDelete = heap->A[i];
    heap->A[i] = heap->A[heap->size];
    heap->size = heap->size - 1;
    maxHeapify(heap, i);
    return toDelete;
}

void insertMaxHeap(MaxHeap* heap, int data) {
    heap->size = heap->size + 1;
    heap->A[heap->size] = data;

    int i = heap->size;

    while (i > 1 && heap->A[i / 2] < heap->A[i]) {
        int temp = heap->A[i / 2];
        heap->A[i / 2] = heap->A[i];
        heap->A[i] = temp;
        i = i / 2;
    }
}

void buildMaxHeap(MaxHeap* heap) {
    for (int i = (heap->size / 2); i >= 1; i--)
        maxHeapify(heap, i);
}

void deleteAllMaxHeap(MaxHeap* heap) {
    int size = heap->size;
    for (int i = size; i >= 1; i--)
        heap->A[i] = deleteMaxHeap(heap, 1);
}

void heapSort(int A[], int numElements) {
    MaxHeap* heap = initMaxHeapFromArray(A, numElements);
    buildMaxHeap(heap);
    deleteAllMaxHeap(heap);
    for (int i = 1; i <= numElements; i++)
        A[i - 1] = heap->A[i];
}
