#include <iostream>
#include "../headers/LinkedList.hpp"

using std::cout;
using std::endl;

// Funcao para inserir novos nodes a lista duplamente encadeada
void insertListNode(struct ListNode** head, int iVal)
{
    // Criamos um novo node
    struct ListNode* newNode = createNode(iVal, nullptr, nullptr);

    // Se a lista esta vazia, newNode eh o head
    if((*head) == nullptr)
        (*head) = newNode;
    else
    {
        // Percorremos a lista ate o final
        struct ListNode* current = (*head);
        while(current->ptrNext != nullptr)
            current = current->ptrNext;

        // e adicionamos o novo node apos o "antigo" ultimo 
        current->ptrNext = newNode;
        newNode->ptrPrev = current;
    }

    return;
}


// Funcao para trocar dois nodes de uma lista encadeada de posicao
void swapListNodes(struct ListNode** head, struct ListNode* Node1, struct ListNode* Node2)
{
    if(Node1 == nullptr || Node2 == nullptr || Node1 == Node2)
    {
        cout << "Ao menos um dos nodes fornecidos eh nulo ou eles sao iguais." << endl;
        return;
    }
    // A funcao considera que node1 vem antes de node2

        // Dois casos
    // Node1 e Node2 sao adjacentes
    if(Node1->ptrNext == Node2)
    {
        // Atualizamos os ponteiros "externos" a node1 e node2
        if(Node1->ptrPrev != nullptr)
        {
            Node2->ptrPrev = Node1->ptrPrev;
            Node1->ptrPrev->ptrNext = Node2;
        }
        else
            Node2->ptrPrev = nullptr;

        if(Node2->ptrNext != nullptr)
        {
            Node1->ptrNext = Node2->ptrNext;
            Node2->ptrNext->ptrPrev = Node1;
        }
        else
            Node1->ptrNext = nullptr;

        // Atualizar os ponteiros "internos" a node1 e node2
        Node2->ptrNext = Node1;
        Node1->ptrPrev = Node2;

        // Atualizar a cabeca da lista, se necessario
        if((*head) == Node1)
            (*head) = Node2;
    }

    // Node1 e Node2 nao sao adjacentes
    else
    {
            // Alterando os ponteiros que apontam para Node1 e Node2:
        // Antecessor -> Node1 ==> Anterior -> Node2
        if(Node1->ptrPrev != nullptr)
            Node1->ptrPrev->ptrNext = Node2;
        // Node1 <- Sucessor ==> Node2 <- Sucessor
        Node1->ptrNext->ptrPrev = Node2;
        // Antecessor -> Node2 ==> Antecessor -> Node1
        Node2->ptrPrev->ptrNext = Node1;
        // Node2 <- Sucessor ==> Node1 <- Sucessor
        if(Node2->ptrNext != nullptr)
            Node2->ptrNext->ptrPrev = Node1;

            // Alterando os ponteiros de Node1 e Node2
        // Ponteiro temporario para node anterior a Node1
        struct ListNode* ptrAntNode1 = Node1->ptrPrev;
        // Anterior_de_node1 <- Node1 ==> Anterior_de_node2 <- Node1
        Node1->ptrPrev = Node2->ptrPrev;
        // Anterior_de_node2 <- Node2 ==> Anterior_de_node1 <- Node2
        Node2->ptrPrev = ptrAntNode1;
        
        // Ponteiro temporario para node posterior a Node1
        struct ListNode* ptrPosNode1 = Node1->ptrNext;
        // Node1 -> Posterior_de_node1 ==> Node1 -> Posterior_de_node2
        Node1->ptrNext = Node2->ptrNext;
        // Node2 -> Posterior_de_node2 ==> Node2 -> Posterior_de_node1
        Node2->ptrNext = ptrPosNode1;

        // Atualizar a cabeca da lista, se necessario
        if((*head) == Node1)
            (*head) = Node2;        // Ponteiro de head aponta para Node2, o novo head
    }

    return;
}


// Funcao para imprimir a lista
void printList(struct ListNode* head)
{
    if(head == nullptr)
        cout << "A lista esta vazia!" << endl;

    while(head != nullptr)
    {
        cout << head->iData << " ";
        head = head->ptrNext;
    }
    cout << endl;

    return;
}