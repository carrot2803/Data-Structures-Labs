#ifndef _MAXPRIORITYQUEUE_H
#define _MAXPRIORITYQUEUE_H

#include "MaxHeap.h"

struct MaxPriorityQueue {
	MaxHeap * heap;
};

MaxPriorityQueue * initMaxPQ (int A[], int numElements); 
int maximumPQ (MaxPriorityQueue * maxPQ);
int extractMaximumPQ (MaxPriorityQueue * maxPQ);
void insertMaxPQ (MaxPriorityQueue * maxPQ, int priority);
void increasePriority (MaxPriorityQueue * maxPQ, int i, int newPriority);
void displayMaxPQ (MaxPriorityQueue * maxPQ);

#endif
