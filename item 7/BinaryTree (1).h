#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

struct BinaryTree {
    TreeNode* ptrRoot;

    BinaryTree();
    void insert(int iData);
    TreeNode* insert(int iData, TreeNode* node);
    bool remove(int iData);
};

#endif  // BINARYTREE_H