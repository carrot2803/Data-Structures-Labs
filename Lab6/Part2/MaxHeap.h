#ifndef _MAXHEAP_H
#define _MINHEAP_H

#define MAXHEAPSIZE	100

struct MaxHeap {
	int A [MAXHEAPSIZE];
	int size;
};

// Function prototypes for Lab 6, Part 2

MaxHeap * initMaxHeap();
MaxHeap * initMaxHeapFromArray (int A[], int numElements);
MaxHeap * initMaxHeapFromFile (char filename[]);

void displayMaxHeap (MaxHeap * heap);
int sizeMaxHeap (MaxHeap * heap);
bool isEmptyMaxHeap (MaxHeap * heap);
bool maxHeapPropertyHolds (MaxHeap * heap, int i);
bool isMaxHeap (MaxHeap * heap);

#endif
