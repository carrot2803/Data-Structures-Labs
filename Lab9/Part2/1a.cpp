#include <iostream>

struct LLNode {
    int data;
    LLNode* next;
};

LLNode* createNode(int n) {
    LLNode* newNode = new LLNode;
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

LLNode* copyLL(LLNode* top) {
    if (top == NULL) return NULL;
    LLNode* newNode = createNode(top->data);
    newNode->next = copyLL(top->next);
    return newNode;
}

bool isSortedRec(LLNode* top) {
    if (top == NULL || top->next == NULL) return true;
    if (top->data > top->next->data) return false;
    return isSortedRec(top->next);
}