#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

struct Node {
   int data;
   Node * next;
};


Node * createNode (int n);
Node * insertAtHead (Node * top, int n);
Node * insertAtTail (Node * top, int n);
Node * insertAtIndex (Node * top, int n, int index);
Node * deleteAtHead (Node * top);
Node * getIndex (Node * top, int index);
Node * getLast (Node * top);
bool contains (Node * top, int key);
int size (Node * top);
void printList (Node * top);

// prototypes for recursive functions in Lab #2, Question 2

void printListRec (Node * top);
void printListReverseRec (Node * top);
int sizeRec (Node * top);
bool containsRec (Node * top, int key);
int sumRec (Node * top);

#endif
