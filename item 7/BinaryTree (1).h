#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

struct BinaryTree {
    TreeNode* ptrRoot; // Ponteiro para a raiz da árvore

    BinaryTree(); // Construtor da árvore

    void insert(int iData); // Função para inserir um elemento na árvore
    bool remove(int iData); // Função para remover um elemento da árvore. Retorna true se a remoção for bem-sucedida.
    bool search(int iData); // Função para pesquisar um elemento na árvore. Retorna true se o elemento estiver presente.
};

#endif  // BINARYTREE_H

