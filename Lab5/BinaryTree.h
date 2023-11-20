#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include "NodeTypes.h"

// function prototypes from Lab #3

BTNode * createBTNode (int data);
void preOrder (BTNode * root);
void inOrder (BTNode * root);
void postOrder (BTNode * root);

// function prototypes from Lab #4

int moment (BTNode * root);
int numOneChild (BTNode * root);
int numNonTerminal (BTNode * root);
int maximumBT (BTNode * root);

// function prototype for Lab #5, Question 4

int nodeDepth (BTNode * node);

#endif
