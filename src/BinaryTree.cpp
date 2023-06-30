#include "../headers/BinaryTree.hpp"
#include <fstream>
#include <iostream>

using std::string;
using std::endl;

// Construtor
BinaryTree::BinaryTree() : ptrRoot(nullptr) {};

// Destrutor
BinaryTree::~BinaryTree() {
    // Aqui devemos adicionar a lógica para deletar todos os nós da árvore.
    // Mas por enquanto, vamos deixar isso em branco
};

// Função para inserir um novo nó na árvore binária de busca.
//A inserção ocorre de tal forma que a propriedade da árvore binária de busca seja mantida,
//ou seja, para qualquer nó, os valores à esquerda são menores e os valores à direita são maiores.

void BinaryTree::insert(int iData) {
    std::cout << "HEY " << ptrRoot << std::endl;
    // Caso a árvore esteja vazia (ou seja, a raiz é nula), crie um novo nó e torne-o a raiz.
    if (ptrRoot == nullptr) {
        std::cout << "lelek " << std::endl;
        ptrRoot = new TreeNode;
        ptrRoot->iData = iData;
        ptrRoot->ptrLeft = nullptr;
        ptrRoot->ptrRight = nullptr;
    } else {
        // Caso contrário, procuramos o local apropriado para inserir o novo nó.
        TreeNode* currentNode = ptrRoot;
        TreeNode* parentNode;
        std::cout << "lhbe  " << std::endl;
        while (true) {
            parentNode = currentNode;
            // Se o novo valor é menor que o valor do nó atual, movemos para a esquerda
            if (iData < currentNode->iData) {
                currentNode = currentNode->ptrLeft;
                // Se alcançarmos um ponto onde um nó não tem filho à esquerda, inserimos o novo nó aqui.
                if (currentNode == nullptr) {
                    parentNode->ptrLeft = new TreeNode;
                    parentNode->ptrLeft->iData = iData;
                    return;
                }
            // Se o novo valor é maior que o valor do nó atual, movemos para a direita
            } else {
                currentNode = currentNode->ptrRight;
                // Se alcançarmos um ponto onde um nó não tem filho à direita, inserimos o novo nó aqui.
                if (currentNode == nullptr) {
                    parentNode->ptrRight = new TreeNode;
                    parentNode->ptrRight->iData = iData;
                    return;
                }
            }
        }
    }
}

//Função para encontrar o nó com o valor mínimo na árvore (ou subárvore) a partir do nó fornecido.
//Em uma árvore binária de busca, o nó com o valor mínimo sempre está no fim da "esquerda" da árvore.
TreeNode* BinaryTree::findMin(TreeNode* node) {
    // Continuamos nos movendo para a esquerda até alcançarmos o fim.
    while (node->ptrLeft != nullptr) {
        node = node->ptrLeft;
    }
    // Retornamos o nó com o menor valor.
    return node;
}

//Função auxiliar para remover um nó da árvore a partir de um determinado nó (geralmente a raiz).
//Este é um método recursivo que encontra o nó a ser removido, realiza a remoção e reorganiza a
//árvore para manter a propriedade da árvore binária de busca.*/
TreeNode* BinaryTree::remove(int iData, TreeNode* node) {
    // Caso base da recursão: se o nó é nulo, simplesmente o retornamos.
    if (node == nullptr) {
        return node;
    }
    // Se o valor a ser removido é menor que o valor do nó, movemos para a esquerda.
    if (iData < node->iData) {
        node->ptrLeft = remove(iData, node->ptrLeft);
    // Se o valor a ser removido é maior que o valor do nó, movemos para a direita.
    } else if (iData > node->iData) {
        node->ptrRight = remove(iData, node->ptrRight);
    // Se o valor é igual ao do nó, então este é o nó que queremos remover.
    } else {
        // Se o nó é uma folha (ou seja, não tem filhos), simplesmente o removemos.
        if (node->ptrLeft == nullptr && node->ptrRight == nullptr) {
            delete node;
            node = nullptr;
        // Se o nó tem um único filho (neste caso, um filho à direita), substituímos o nó pelo seu filho.
        } else if (node->ptrLeft == nullptr) {
            TreeNode* temp = node;
            node = node->ptrRight;
            delete temp;
        // Se o nó tem um único filho (neste caso, um filho à esquerda), substituímos o nó pelo seu filho.
        } else if (node->ptrRight == nullptr) {
            TreeNode* temp = node;
            node = node->ptrLeft;
            delete temp;
        // Se o nó tem dois filhos, precisamos encontrar o nó sucessor (ou seja, o nó com o menor valor à direita do nó atual)
        // Substituímos o valor do nó atual pelo valor do sucessor e, em seguida, removemos o sucessor.
        } else {
            TreeNode* temp = findMin(node->ptrRight);
            node->iData = temp->iData;
            node->ptrRight = remove(temp->iData, node->ptrRight);
        }
    }
    // Retorna o nó (potencialmente modificado ou substituído).
    return node;
}

//Função principal que é usada para remover um nó com um determinado valor da árvore
bool BinaryTree::remove(int iData) {
    if (search(iData)) {
        ptrRoot = remove(iData, ptrRoot);
        return true;
    }
    return false;
}

//Função para verificar se um determinado valor existe na árvore.
//Começamos pela raiz e nos movemos para a esquerda ou para a direita, 
//dependendo de o valor ser menor ou maior que o valor do nó atual.
bool BinaryTree::search(int iData) {
    TreeNode* current = ptrRoot;  // Começamos na raiz

    while(current != nullptr) {  // Enquanto não chegamos ao fim da árvore
        if(iData == current->iData) {  // Se o valor do nó atual for o que estamos procurando, retornamos true
            return true;
        } else if(iData < current->iData) {  // Se o valor que estamos procurando for menor que o valor do nó atual, vamos para a esquerda
            current = current->ptrLeft;
        } else {  // Se o valor que estamos procurando for maior que o valor do nó atual, vamos para a direita
            current = current->ptrRight;
        }
    }

    return false;  // Se chegamos ao fim da árvore sem encontrar o valor, retornamos false
}

// Retorna a altura da árvore
int BinaryTree::getHeight() {
    return height(ptrRoot);
}

// Retorna o tamanho da árvore
int BinaryTree::getSize() {
    return size(ptrRoot);
}

// Funções auxiliares para calcular a altura e o tamanho de um nó especificado
int BinaryTree::height(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    } else {
        int leftHeight = height(node->ptrLeft);
        int rightHeight = height(node->ptrRight);
        return std::max(leftHeight, rightHeight) + 1;
    }
}

int BinaryTree::size(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return size(node->ptrLeft) + size(node->ptrRight) + 1;
    }
}


// Função auxiliar para verificar se a árvore a partir do nó fornecido está completa.
//são funções recursivas
bool BinaryTree::isComplete(TreeNode* node, int iIndex, int iNumNodes) {
    if (node == nullptr) {
        return true;
    }
    if (iIndex >= iNumNodes) {
        return false;
    }
    return (isComplete(node->ptrLeft, 2*iIndex + 1, iNumNodes) && isComplete(node->ptrRight, 2*iIndex + 2, iNumNodes));
}

// Função principal para verificar se a árvore inteira está completa.
bool BinaryTree::isComplete() {
    return isComplete(ptrRoot, 0, size(ptrRoot));
}

// Função para verificar se a árvore  é perfeita a partir do nó fornecido 
bool BinaryTree::isPerfect(TreeNode* node, int iDepth, int iLevel) {
    if (node == nullptr) {
        return true;
    }
    if (node->ptrLeft == nullptr && node->ptrRight == nullptr) {
        return (iDepth == iLevel + 1);
    }
    if (node->ptrLeft == nullptr || node->ptrRight == nullptr) {
        return false;
    }
    return (isPerfect(node->ptrLeft, iDepth, iLevel + 1) && isPerfect(node->ptrRight, iDepth, iLevel + 1));
}

// Função principal para verificar se a árvore inteira é perfeita.
bool BinaryTree::isPerfect() {
    int nodeCount = size(ptrRoot);
    int treeDepth = height(ptrRoot);
    return isPerfect(ptrRoot, treeDepth);
}

// Função para construir a árvore a partir de um arquivo de texto.
void BinaryTree::buildFromTextFile(const string &filename) {
    // Abre o arquivo de texto.
    std::ifstream infile(filename);

    // Se o arquivo não pode ser aberto, imprime uma mensagem de erro e retorna.
    if (!infile) {
        std::cerr << "Não foi possível abrir o arquivo: " << filename << endl;
        return;
    }

    // Lê cada valor do arquivo e insere na árvore.
    int iValue;
    while (infile >> iValue) {
        insert(iValue);
    }
}

// Função para construir a árvore a partir de dados digitados pelo usuário.
void BinaryTree::buildFromUserInput(const std::vector<int> &userInput) {
    // Itera sobre cada valor fornecido pelo usuário e insere na árvore.
    for (const int &value : userInput) {
        std::cout <<"opa " << value << std::endl;
        insert(value);
    }
}

