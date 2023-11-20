#ifndef _BINARYTREE_H
#define _BINARYTREE_H

struct BTNode {
	int data;
	BTNode * left;
	BTNode * right;
};

// function prototypes for Lab #3, Question 3

BTNode * createBTNode (int data);
void preOrder (BTNode * root);
void inOrder (BTNode * root);
void postOrder (BTNode * root);

#endif
