#include <iostream>

#include "BinaryTree.h"

using namespace std;

int main() {
    BTNode *root;

    BTNode *node20, *node17, *node30, *node5, *node18;
    BTNode *node25, *node50, *node10, *node45, *node80;

    // Code to create binary tree (Lab #6, Part 1)

    node20 = createBTNode(20);
    node17 = createBTNode(17);
    node30 = createBTNode(30);
    node5 = createBTNode(5);
    node18 = createBTNode(18);

    node25 = createBTNode(25);
    node50 = createBTNode(50);
    node10 = createBTNode(10);
    node45 = createBTNode(45);
    node80 = createBTNode(80);

    root = node20;

    // Write code to connect nodes to their parents (Lab #6, Part 1)
    node20->left = node17;
    node17->left = node5;
    node17->right = node18;
    node5->right = node10;
    node20->right = node30;
    node30->left = node25;
    node30->right = node50;
    node50->left = node45;
    node50->right = node80;

    // Code to test preorder, inorder, and postorder traversals

    cout << "Preorder traversal: ";
    preOrder(root);
    cout << endl << endl;

    cout << "Inorder traversal: ";
    inOrder(root);
    cout << endl << endl;

    cout << "Postorder traversal: ";
    postOrder(root);
    cout << endl << endl;

    // Code to test non-recursive inorder traversal

    cout << endl;

    cout << "Non-recursive Inorder traversal: ";
    inOrderNonRecursive(root);

    cout << endl;

    // Code to test non-recursive preorder traversal

    cout << endl;

    cout << "Non-recursive Preorder traversal: ";
    preOrderNonRecursive(root);

    cout << endl;

    // Write code to test level order traversal (Lab #6, Part 1)
    cout << "Level Order traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
