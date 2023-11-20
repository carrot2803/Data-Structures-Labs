#include "BinarySearchTree.h"

#include <cstdlib>
#include <iostream>

#include "BinaryTree.h"
#include "NodeTypes.h"

using namespace std;

// Write insertBST function here (Lab #5, Question 2)

BTNode* insertBST(BTNode* root, int data) {
    BTNode* newNode = createBTNode(data);
    if (root == NULL) return newNode;

    BTNode* curr = root;

    while (true) {
        if (newNode->data < curr->data) {
            if (curr->left == NULL) {
                curr->left = newNode;
                newNode->parent = curr;
                return root;
            }
            curr = curr->left;
        } else {
            if (curr->right == NULL) {
                curr->right = newNode;
                newNode->parent = curr;
                return root;
            }
            curr = curr->right;
        }
    }
}

// Write insertBSTRec function here (Lab #5, Question 9)

BTNode* insertBSTRec(BTNode* root, int data) {
    if (root == NULL) return createBTNode(data);
    if (data < root->data) {
        root->left = insertBSTRec(root->left, data);
        root->left->parent = root;
    } else {
        root->right = insertBSTRec(root->right, data);
        root->right->parent = root;
    }
    return root;
}

// Write containsBST function here (Lab #5, Question 3)

BTNode* containsBST(BTNode* root, int key) {
    if (root == NULL)
        return NULL;
    else if (key == root->data)
        return root;
    else if (key < root->data)
        return containsBST(root->left, key);
    return containsBST(root->right, key);
}

// Write deleteLeafNode function here (Lab #5, Question 5)

bool deleteLeafNode(BTNode* node) {
    if (node->left == NULL && node->right == NULL) {
        if (node->parent->left == node)
            node->parent->left = NULL;
        else
            node->parent->right = NULL;
        delete node;
        return true;
    }
    return false;
}
