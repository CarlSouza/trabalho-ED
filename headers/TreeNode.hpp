#ifndef __TREE_NODE_H_
#define __TREE_NODE_H_

#include <iostream>

using std::cout;

struct TreeNode* newNode(int iData);
struct TreeNode* insertNode(struct TreeNode* node, int iVal);
void printTree(struct TreeNode* ptrStartingNode);

// Definindo um nó da árvore
struct TreeNode {
    
    int iData;  // valor do nó
    TreeNode* ptrLeft;  // ponteiro para o nó à esquerda
    TreeNode* ptrRight; // ponteiro para o nó à direita
    
    // Construtor
    TreeNode() : ptrLeft(nullptr), ptrRight(nullptr), iData(0) {}
};


#endif // __TREE_NODE_H_