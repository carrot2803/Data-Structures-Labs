#include <cstring>
#include <iostream>

#include "MaxHeap.h"
using namespace std;

int main() {
    MaxHeap* heap;
    char filename[25] = "MaxHeap-Q2.txt";
    bool isHeap;

    // Question 2

    cout << "Question 2" << endl;
    heap = initMaxHeapFromFile(filename);
    maxHeapify(heap, 1);
    displayMaxHeap(heap);

    // Question 3

    cout << endl << endl;
    cout << "Question 3" << endl;
    delete (heap);
    int arr[] = {85, 81, 72, 63, 75, 70, 65, 50, 60, 74, 40};
    heap = initMaxHeapFromArray(arr, 11);
    if (isMaxHeap(heap)) {
        cout << "Heap property is confirmed for all nodes." << endl;
    } else {
        cout << "It is not a heap\n";
    }
    displayMaxHeap(heap);

    // Question 4

    cout << endl << endl;
    cout << "Question 4" << endl;
    int arr2[] = {50, 48, 40, 41, 33, 22, 38, 35, 28, 30, 25};
    MaxHeap* heap3 = initMaxHeapFromArray(arr2, 12);

    int num2 = deleteMaxHeap(heap3, 1);
    insertMaxHeap(heap3, 75);
    maxHeapify(heap3, 1);
    displayMaxHeap(heap3);

    // Question 5

    cout << endl << endl;
    cout << "Question 5" << endl;
    int arr3[] = {60, 20, 41, 15, 25, 75, 30, 35, 50, 23, 38, 45};
    heapSort(arr3, 12);
    for (int i : arr3) cout << i << " ";

    return 0;
}
