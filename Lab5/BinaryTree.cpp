#include "BinaryTree.h"

#include <cstdlib>
#include <iostream>

using namespace std;

// Modify the createBTNode function (Lab #5, Question 1)

BTNode* createBTNode(int data) {
    BTNode* newNode;

    newNode = new BTNode;

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

// Code for functions from Lab #3

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

// Code for functions from Lab #4

int moment(BTNode* root) {
    if (root == NULL) return 0;

    return (1 + moment(root->left) + moment(root->right));
}

int numOneChild(BTNode* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 0;

    if (root->left == NULL)
        return 1 + numOneChild(root->right);
    else if (root->right == NULL)
        return 1 + numOneChild(root->left);
    else
        return (numOneChild(root->left) + numOneChild(root->right));
}

int numNonTerminal(BTNode* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 0;

    return (1 + numNonTerminal(root->left) + numNonTerminal(root->right));
}

int maximumBT(BTNode* root) {
    int max, maxLeft, maxRight;

    if (root == NULL) return INT8_MIN;

    maxLeft = maximumBT(root->left);
    maxRight = maximumBT(root->right);

    if (maxLeft > maxRight)
        max = maxLeft;
    else
        max = maxRight;

    if (max > root->data)
        return max;
    else
        return root->data;
}

// Write nodeDepth function (Lab #5, Question 4)

// int nodeDepth(BTNode* node) {
//     int branch = 0;
//     while (node->parent != NULL && node != NULL) {
//         branch++;
//         node = node->parent;
//     }
//     return branch;
// }

int nodeDepth(BTNode* node) {
    if (node == NULL) return -1;
    int depth = 0;
    while (node->parent != NULL) {
        depth++;
        node = node->parent;
    }
    return depth;
}