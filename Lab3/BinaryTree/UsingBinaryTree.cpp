#include <iostream>

#include "BinaryTree.h"

using namespace std;

int main() {
    BTNode* root;
    BTNode *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8;

    // Write code to create binary tree and test traversals in Question 3

    node1 = createBTNode(30);
    node2 = createBTNode(10);
    node1->left = node2;
    node2->right = createBTNode(25);
    node1->right = createBTNode(50);
    node1->right->left = createBTNode(40);
    node1->right->left->left = createBTNode(35);
    node1->right->right = createBTNode(90);
    node1->right->right->left = createBTNode(70);

    // Connect node1 and node2 like this:

    // node1->left = node2;

    // set root to the address of the node with 30:

    // write code for 3(d) to test traversals:

    cout << "Preorder Traversal: ";
    preOrder(node1);
    cout << endl;

    cout << "Inorder Traversal: ";
    inOrder(node1);
    cout << endl;

    cout << "Postorder Traversal: ";
    postOrder(node1);
    cout << endl;

    return 0;
}
