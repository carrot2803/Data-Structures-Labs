#ifndef _MAXHEAP_H
#define _MAXHEAP_H

#define MAXHEAPSIZE	100

struct MaxHeap {
	int A [MAXHEAPSIZE];
	int size;
};


MaxHeap * initMaxHeap();
MaxHeap * initMaxHeapFromFile (char filename[]);
MaxHeap * initMaxHeapFromArray (int A[], int numElements);
void displayMaxHeap (MaxHeap * heap);
int sizeMaxHeap (MaxHeap * heap);
bool isEmptyMaxHeap (MaxHeap * heap);
bool maxHeapPropertyHolds (MaxHeap * heap, int i);
bool isMaxHeap (MaxHeap * heap);


void maxHeapify (MaxHeap * heap, int i);
int maximum (MaxHeap * heap);
int deleteMaxHeap (MaxHeap * heap, int i);
void insertMaxHeap (MaxHeap * heap, int data);
void buildMaxHeap(MaxHeap * heap);
void deleteAllMaxHeap (MaxHeap * heap);
void heapSort (int A[], int numElements);

#endif
