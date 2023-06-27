#ifndef __TREE_NODE_H_
#define __TREE_NODE_H_

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


// Três tipos de sequenciamento de árvores: pré-ordem, pós-ordem, e em ordem
struct TreeNode* newNode(int iData)
{
    struct TreeNode* newNodePtr = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNodePtr->iData = iData;
    newNodePtr->ptrLeft = nullptr;
    newNodePtr->ptrRight = nullptr;

    return newNodePtr;
}


// node eh o node inicial da arvore
struct TreeNode* insertNode(struct TreeNode* node, int iVal)
{
    if(node == nullptr)
        return newNode(iVal);
    if(iVal < node->iData)
        node->ptrLeft = insertNode(node->ptrLeft, iVal);
    else
        node->ptrRight = insertNode(node->ptrRight, iVal);

    return node;
}


// Primeiro o nó à esquerda, depois o atual, depois à direita
void printTree(struct TreeNode* ptrStartingNode)
{
    if (ptrStartingNode == nullptr) 
        return;

    printTree(ptrStartingNode->ptrLeft);
    cout << " " << ptrStartingNode->iData;
    printTree(ptrStartingNode->ptrRight);
}

#endif // __TREE_NODE_H_