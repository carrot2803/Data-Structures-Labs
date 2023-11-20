#include "BinaryTree.h"

#include <climits>
#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

// Code for Lab #3, Question 3 functions

BTNode* createBTNode(int data) {
    BTNode* newNode;
    newNode = new BTNode;
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

// Write code for Lab #4, Question 1 functions here

int moment(BTNode* root) {
    if (root == NULL) return 0;
    return 1 + moment(root->left) + moment(root->right);
}

// int numOneChild(BTNode* root) {
//     if (root == NULL) return 0;
//     if (root->left == NULL && root->right == NULL) return 0;
//     if (root->left == NULL)
//         return 1 + numOneChild(root->right);
//     else if (root->right == NULL)
//         return 1 + numOneChild(root->left);
//     return (numOneChild(root->left) + numOneChild(root->right));
// }

int numOneChild(BTNode* root) {
    if (root == NULL) return 0;
    int leftCount = numOneChild(root->left);
    int rightCount = numOneChild(root->right);
    return ((!root->left) ^ (!root->right)) + leftCount + rightCount;
}

int numTerminal(BTNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return numTerminal(root->left) + numTerminal(root->right);
}

int maximum(BTNode* root) {
    if (root == NULL) return INT_MIN;
    int left = maximum(root->left);
    int right = maximum(root->right);
    return max(root->data, max(left, right));
}

// Write the code for non-recursive inorder traversal here

void inOrderNonRecursive(BTNode* root) {
    Stack* s = initStack();
    BTNode* curr = root;

    while (curr != NULL || !isEmptyStack(s)) {
        while (curr != NULL) {
            push(s, curr);
            curr = curr->left;
        }
        curr = pop(s);
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preOrderNonRecursive(BTNode* root) {
    Stack* s = initStack();
    BTNode* curr = root;

    while (curr != NULL || !isEmptyStack(s)) {
        while (curr != NULL) {
            cout << curr->data << " ";
            push(s, curr);
            curr = curr->left;
        }
        curr = pop(s);
        curr = curr->right;
    }
}

// Write the code for non-recursive preorder traversal here

void postOrderNonRecursive(BTNode* root) {
    Stack* s = initStack();
    BTNode* curr = root;
    BTNode* lastVisited = NULL;

    while (curr || !isEmptyStack(s)) {
        while (curr != NULL) {
            push(s, curr);
            curr = curr->left;
        }
        BTNode* peekNode = peek(s);
        if (peekNode->right == NULL || peekNode->right == lastVisited) {
            curr = pop(s);
            cout << curr->data << " ";
            lastVisited = curr;
            curr = NULL;
        } else {
            curr = peekNode->right;
        }
    }
}
