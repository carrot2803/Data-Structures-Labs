#include "Stack.h"

#include <iostream>

#include "NodeTypes.h"

using namespace std;

Stack* initStack() {
    Stack* s = new Stack;
    s->top = NULL;
    return s;
}

bool isEmptyStack(Stack* s) {
    if (s->top == NULL)
        return true;
    else
        return false;
}

void push(Stack* s, BTNode* data) {
    Node* newElement = new Node;
    newElement->data = data;
    newElement->next = s->top;
    s->top = newElement;
}

BTNode* pop(Stack* s) {
    if (isEmptyStack(s)) return NULL;
    Node* toRemove;
    BTNode* data;
    toRemove = s->top;
    data = toRemove->data;
    s->top = s->top->next;
    delete (toRemove);
    return data;
}

BTNode* peek(Stack* s) { return (isEmptyStack(s)) ? NULL : s->top->data; }
