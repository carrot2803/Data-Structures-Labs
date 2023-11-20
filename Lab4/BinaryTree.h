#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include "NodeTypes.h"

// function prototypes from Lab #3, Question 3

BTNode* createBTNode(int data);
void preOrder(BTNode* root);
void inOrder(BTNode* root);
void postOrder(BTNode* root);

// function prototypes for Lab #4, Question 1

int moment(BTNode* root);
int numOneChild(BTNode* root);
int numTerminal(BTNode* root);
int maximum(BTNode* root);

// function prototypes for Lab #4, Question 3

void inOrderNonRecursive(BTNode* root);
void preOrderNonRecursive(BTNode* root);
void postOrderNonRecursive(BTNode* root);

#endif
