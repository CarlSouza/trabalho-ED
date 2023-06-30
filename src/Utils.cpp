#include "../headers/Utils.hpp"
#include "../headers/LinkedList.hpp"
#include "../headers/TreeNode.hpp"
// #include "../headers/BubbleSort.hpp"
// #include "../headers/InsertionSort.hpp"
// #include "../headers/SelectionSort.hpp"
// #include "../headers/ShellSort.hpp"

// Funcao para percorrer a arvore de forma iterativa, adicionando os elementos a uma lista.
void treeToList(struct TreeNode* root, struct ListNode** head)
{
    // Arvore vazia
    if (root == nullptr)
        return;
    
    // Insere o node atual na lista
    insertListNode(head, root->iData);

    // Percorre a sub-arvore da esquerda
    treeToList(root->ptrLeft, head);

    // Percorre a sub-arvore da direita
    treeToList(root->ptrRight, head);

    return;
};

void sort(struct TreeNode* root, int iTypeSort)
{
    // Criamos um head para a lista duplamente encadeada
    struct ListNode* head = nullptr;

    // Adicionamos os nodes na arvore na lista
    treeToList(root, &head);

    // Imprimimos a lista ainda nao ordenada
    // printList(head);
    // cout << endl;

    // Escolhe a forma de ordenacao
    switch(iTypeSort)
    {
        case 11:
            bubbleSort(&head);
            printList(head);
            break;
        case 12:
            selectionSort(&head);
            printList(head);
            break;
        case 13:
            insertionSort(&head);
            printList(head);
            break;
        case 14:
            shellSort(&head);
            printList(head);
            break;
        default:
            break;
    }

    return;
};