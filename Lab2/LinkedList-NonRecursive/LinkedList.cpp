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
    Node* newNode = createNode(n);
    newNode->next = top;
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

// Code for predecessor function

Node* predecessor(Node* top, int n) {
    if (top == NULL || top->data >= n) return NULL;
    Node *previous = top, *curr = top->next;
    while (curr != NULL && curr->data < n) {
        previous = curr;
        curr = curr->next;
    }
    return previous;
}

// Write functions for Lab #2, Question 1

Node* insertSorted(Node* top, int n) {
    Node *newNode = createNode(n), *prev = predecessor(top, n);
    if (prev == NULL) {
        newNode->next = top;
        top = newNode;
    } else {
        newNode->next = prev->next;
        prev->next = newNode;
    }
    return top;
}

bool isEqual(Node* top1, Node* top2) {
    while (top1 != NULL && top2 != NULL) {
        if (top1->data != top2->data) return false;
        top1 = top1->next;
        top2 = top2->next;
    }
    return (!top1 && !top2) ? true : false;
}

Node* copyList(Node* top) {
    Node *newTop = NULL, *last = NULL;
    while (top != NULL) {
        Node* newNode = createNode(top->data);
        (newTop == NULL) ? newTop = newNode : last->next = newNode;
        last = newNode;
        top = top->next;
    }
    return newTop;
}

void clear(Node* top) {
    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

Node* addRest(Node* top, Node* newTop, Node* last) {
    while (top != NULL) {
        Node* newNode = createNode(top->data);
        last->next = newNode;
        last = newNode;
        top = top->next;
    }
    return newTop;
}

Node* merge(Node* top1, Node* top2) {
    Node *newTop = NULL, *newNode = NULL, *last = NULL;
    while (top1 != NULL && top2 != NULL) {
        if (top1->data < top2->data) {
            newNode = createNode(top1->data);
            top1 = top1->next;
        } else {
            newNode = createNode(top2->data);
            top2 = top2->next;
        }
        (!newTop) ? newTop = newNode : last->next = newNode;
        last = newNode;
    }
    last->next = (top1 == NULL) ? top2 : top1;
    return newTop;
}

// Node* merge(Node* top1, Node* top2) {
//     Node *newTop = NULL, *newNode = NULL, *last = NULL;
//     while (top1 && top2) {
//         if (top1->data < top2->data) {
//             newNode = createNode(top1->data);
//             top1 = top1->next;
//         } else {
//             newNode = createNode(top2->data);
//             top2 = top2->next;
//         }
//         (!newTop) ? newTop = newNode : last->next = newNode;
//     }
//     if (!top1) {
//         newTop = addRest(top2, newTop, last);
//     } else {
//         newTop = addRest(top1, newTop, last);
//     }
//     return newTop;
// }