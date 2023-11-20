#include "LinkedList.h"

#include <cstdlib>
#include <iostream>

using namespace std;

Node* createNode(int n) {
    Node* newNode;

    newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtHead(Node* top, int n) {
    Node* newNode;

    newNode = createNode(n);
    newNode->next = top;  // this works even if the list is empty (i.e., top = NULL)
    top = newNode;

    return top;  // return pointer to new head of list
}

Node* insertAtTail(Node* top, int n) {
    Node* newNode;
    Node* lastNode;

    newNode = createNode(n);
    lastNode = getLast(top);

    if (lastNode == NULL)  // linked list has no elements
        top = newNode;     // let top be the address of the node just created
    else                   // let lastNode refer to the node just created
        lastNode->next = newNode;

    return top;  // return top in case it got changed
}

Node* insertAtIndex(Node* top, int n, int index) {
    int len;
    Node* curr;
    Node* newNode;
    Node* previous;

    len = size(top);

    if (index < 0 || index > len) return NULL;  // invalid index

    if (index == 0)
        return insertAtHead(top, n);  // insert at the top of the list
    else if (index == len)            // insert at the tail of the list
        return insertAtTail(top, n);
    else {  // insert somewhere inside the list
        newNode = createNode(n);
        curr = top;
        int i = 0;
        while (i < index) {
            previous = curr;
            curr = curr->next;
            i++;
        }
        newNode->next = previous->next;
        previous->next = newNode;
        return top;
    }
}

Node* deleteAtHead(Node* top) {
    Node* curr;

    curr = top;
    if (top == NULL)
        return NULL;
    else {
        curr = top;
        top = top->next;
        delete (curr);
        return top;
    }
}

Node* getIndex(Node* top, int index) {
    int i, len;
    Node* curr;

    curr = top;
    len = size(top);

    if (index >= 0 && index < len) {
        for (i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr;
    } else
        return NULL;
}

Node* getLast(Node* top) {
    Node* curr;
    Node* last;

    last = NULL;
    curr = top;
    while (curr != NULL) {
        last = curr;
        curr = curr->next;
    }

    return last;
}

bool contains(Node* top, int key) {
    Node* curr;

    curr = top;
    while (curr != NULL) {
        if (curr->data == key)
            return true;
        else
            curr = curr->next;
    }
    return false;
}

int size(Node* top) {
    Node* curr;
    int numNodes = 0;

    curr = top;
    while (curr != NULL) {
        numNodes = numNodes + 1;
        curr = curr->next;
    }
    return numNodes;
}

void printList(Node* top) {
    Node* curr;

    curr = top;
    while (curr != NULL) {
        cout << curr->data << "\t";
        curr = curr->next;
    }

    cout << "\n";
}

// Insert function definitions for Lab #2, Question 3

bool isEqualRec(Node* top1, Node* top2) {
    if (top1 == NULL && top2 == NULL)
        return true;
    else if (top1 == NULL || top2 == NULL)
        return false;
    else if (top1->data != top2->data)
        return false;
    return isEqualRec(top1->next, top2->next);
}

Node* copyListRec(Node* top) {
    if (top == NULL) return NULL;
    Node* copy = createNode(top->data);
    copy->next = copyListRec(top->next);
    return copy;
}

Node* insertSortedRec(Node* top, int n) {
    if (top == NULL || n < top->data) {
        Node* newNode = createNode(n);
        newNode->next = top;
        return newNode;
    }
    top->next = insertSortedRec(top->next, n);
    return top;
}

Node* mergeRec(Node* top1, Node* top2) {
    if (top1 == NULL) return top2;
    if (top2 == NULL) return top1;

    Node* newTop = NULL;

    if (top1->data < top2->data) {
        newTop = createNode(top1->data);
        newTop->next = mergeRec(top1->next, top2);
    } else {
        newTop = createNode(top2->data);
        newTop->next = mergeRec(top2->next, top1);
    }
    return newTop;
}
