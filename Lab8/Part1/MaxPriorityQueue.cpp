#include "MaxPriorityQueue.h"

#include <iostream>

#include "MaxHeap.h"

using namespace std;

MaxPriorityQueue *initMaxPQ(int A[], int numElements) {
    MaxPriorityQueue *mpq = new MaxPriorityQueue;
    mpq->heap = initMaxHeapFromArray(A, numElements);
    return mpq;
}

int maximumPQ(MaxPriorityQueue *maxPQ) {
    if (isEmptyMaxHeap(maxPQ->heap)) return -1;
    return maxPQ->heap->A[1];
}

int extractMaximumPQ(MaxPriorityQueue *maxPQ) {
    if (isEmptyMaxHeap(maxPQ->heap)) return -1;
    int n = deleteMaxHeap(maxPQ->heap, 1);
    return n;
}

void insertMaxPQ(MaxPriorityQueue *maxPQ, int priority) {
    insertMaxHeap(maxPQ->heap, priority);
}

void increasePriority(MaxPriorityQueue *maxPQ, int i, int newPriority) {
    if (i > maxPQ->heap->size || maxPQ->heap->A[i] >= newPriority)
        return;
    maxPQ->heap->A[i] = newPriority;
    maxHeapify(maxPQ->heap, i);
}

void displayMaxPQ(MaxPriorityQueue *maxPQ) {
    displayMaxHeap(maxPQ->heap);
}
