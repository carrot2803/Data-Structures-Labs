#include "BinaryTree.h"

#include <cstdlib>
#include <iostream>

using namespace std;

// write code for Lab #3, Question 3 functions here

BTNode* createBTNode(int data) {
    BTNode* newNode = new BTNode;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(BTNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BTNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(BTNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
