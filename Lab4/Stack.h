#ifndef _STACK_H
#define _STACK_H

#include "NodeTypes.h"
using namespace std;

struct Stack {
    Node* top;
};

Stack* initStack();
bool isEmptyStack(Stack* s);
void push(Stack* s, BTNode* data);
BTNode* pop(Stack* s);
BTNode* peek(Stack* s);

#endif
