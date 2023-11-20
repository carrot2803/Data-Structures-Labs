#include <iostream>
#include <vector>

#include "BinarySearchTree.h"
#include "BinaryTree.h"

using namespace std;

int main() {
    BTNode* root = NULL;

    // Write code to create binary search tree and test functions in Lab #5,
    // Part 1

    int arr[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (int i = 0; i < 11; i++) {
        root = insertBST(root, arr[i]);
    }

    inOrder(root);
    cout << endl << endl;
    postOrder(root);
    cout << endl << endl;

    BTNode* contains;

    contains = containsBST(root, 12);
    if (contains == NULL) {
        cout << "Node not found in tree." << endl << endl;
    }

    contains = containsBST(root, 13);
    cout << contains->data << endl << endl;

    contains = containsBST(root, 17);
    cout << contains->data << endl << endl;

    bool result;

    result = deleteLeafNode(contains);
    if (result == true) {
        cout << "The node with 17 was deleted." << endl << endl;
    } else {
        cout << "The node with 17 was NOT deleted." << endl << endl;
    }

    inOrder(root);
    cout << endl << endl;

    int depth = nodeDepth(root->left->right);
    cout << "The depth is " << depth << endl << endl;

    return 0;
}
