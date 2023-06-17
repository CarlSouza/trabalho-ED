#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

struct BinaryTree {
    BinaryTree();
    void insert(int iData);
    TreeNode* ptrRoot;
    TreeNode* insert(int iData, TreeNode* node);
};

#endif  // BINARYTREE_H