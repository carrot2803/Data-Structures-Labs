#ifndef _NODETYPES_H
#define _NODETYPES_H

#include <iostream>
using namespace std;

// Modify the BTNode struct to store the address of the node's parent

struct BTNode {
    int data;
    BTNode* left;
    BTNode* right;
    BTNode* parent;
};

#endif
