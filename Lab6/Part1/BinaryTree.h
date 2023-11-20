#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include "NodeTypes.h"

// function prototypes from Lab #4, Question 2

BTNode * createBTNode (int data);
void preOrder (BTNode * root);
void inOrder (BTNode * root);
void postOrder (BTNode * root);

// function prototypes from Lab #4, Question 1

int moment (BTNode * root);
int numOneChild (BTNode * root);
int numNonTerminal (BTNode * root);
int maximumBT (BTNode * root);

// function prototype from Lab #4, Question 3

void inOrderNonRecursive (BTNode * root);
void preOrderNonRecursive (BTNode * root);

// function prototype from Lab #5, Question 4

int nodeDepth (BTNode * node);

// function prototype for Lab #6, Part 1

void levelOrder (BTNode * root);

#endif
