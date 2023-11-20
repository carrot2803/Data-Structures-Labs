#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

// function prototypes for Lab #5
#include "NodeTypes.h"

BTNode* insertBST(BTNode* root, int data);
BTNode* insertBSTRec(BTNode* root, int data);
BTNode* containsBST(BTNode* root, int key);
bool deleteLeafNode(BTNode* root);

#endif
