#include "BinaryTree.h"

#include <cstdlib>
#include <iostream>

#include "Queue.h"
#include "Stack.h"

using namespace std;

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

int maximum(BTNode* root) {
    int max, maxLeft, maxRight;

    if (root == NULL) return INT8_MIN;

    maxLeft = maximum(root->left);
    maxRight = maximum(root->right);

    if (maxLeft > maxRight)
        max = maxLeft;
    else
        max = maxRight;

    if (max > root->data)
        return max;
    else
        return root->data;
}

// Code for non-recursive inorder traversal from Lab #4

void inOrderNonRecursive(BTNode* root) {
    Stack* s = initStack();

    BTNode* curr;
    bool finished;

    curr = root;
    finished = false;

    while (!(finished)) {
        while (curr != NULL) {
            push(s, curr);
            curr = curr->left;
        }
        if (isEmptyStack(s))
            finished = true;
        else {
            curr = pop(s);
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

// Code for non-recursive preorder traversal from Lab #4

void preOrderNonRecursive(BTNode* root) {
    Stack* s = initStack();

    BTNode* curr;
    bool finished;

    curr = root;
    finished = false;

    while (!(finished)) {
        while (curr != NULL) {
            cout << curr->data
                 << " ";  // only change necessary from inorder traversal
            push(s, curr);
            curr = curr->left;
        }
        if (isEmptyStack(s))
            finished = true;
        else {
            curr = pop(s);
            curr = curr->right;
        }
    }
}

// Code for finding the depth of a node from Lab #5

int nodeDepth(BTNode* node) {
    int branch;

    branch = 0;

    if (node == NULL) return -1;

    while (node->parent != NULL) {
        node = node->parent;
        branch++;
    }

    return branch;
}

// Write code for the level order traversal from Lab #6, Part 1

void levelOrder(BTNode* root) {
    Queue* q = initQueue();
    enqueue(q, root);
    while (!isEmptyQueue(q)) {
        BTNode* node = dequeue(q);
        cout << node->data << " ";
        if (node->left != NULL) enqueue(q, node->left);
        if (node->right != NULL) enqueue(q, node->right);
    }
}
