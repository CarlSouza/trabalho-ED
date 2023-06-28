#include <iostream>
#include "../headers/LinkedList.hpp"
#include "PrintSort.hpp"

// Função de representação gráfica. Declaração aqui, implementação em PrintSort.cpp
void print_bars(const std::vector<int>& vec);

// Função auxiliar para converter a lista vinculada em um vetor
std::vector<int> linkedListToVector(struct ListNode** head) {
    std::vector<int> vec;
    struct ListNode* temp = *head;
    while (temp != nullptr) {
        vec.push_back(temp->iData);
        temp = temp->ptrNext;
    }
    return vec;
}

// Funcao de ordenacao em BUBBLE SORT
void bubbleSort(struct ListNode** head)
{
    // Ponteiro para o maior valor da lista
    struct ListNode* ptrLarger = nullptr;
    // Ponteiro para o valor atual do loop ("next de ptrLarger")
    struct ListNode* ptrCurrent = nullptr;
    // Booleano para indicar se lista esta desordenada (true por padrao)
    bool bUnordered = true;

    // Enquanto a lista esta desordenada, ela eh percorrida. 
    // Se a funcao de swap eh acionada pelo menos uma vez, eh pq a lista esta desordenada. O status de desordem eh "verdadeiro".
    // Se a funcao de swap nao eh acionada, eh pq a lista esta ordenada. O status de desordem eh "false" e o loop termina.
    while(bUnordered)
    {
        // A cada loop, reiniciamos os ponteiros e o status de ordenacao
        ptrLarger = (*head);
        ptrCurrent = (*head)->ptrNext;
        bUnordered = false;

        // A lista eh percorrida ate o ponteiro do maior valor chegar ao ultimo elemento da lista
        while(ptrLarger->ptrNext != nullptr)
        {
            // Se o maior valor encontrado ate agora (ptrLarger) for maior do que o valor seguinte a ele (ptrCurrent):
            if(ptrLarger->iData > ptrCurrent->iData)
                {   
                    swapListNodes(head, ptrLarger, ptrCurrent); // trocamos eles de posicao;
                    bUnordered = true; // trocamos o status de desordenado para verdadeiro
                    std::vector<int> vec = linkedListToVector(head);
                    print_bars(vec); // Chama função de impressão após a troca

                    ptrCurrent = ptrCurrent->ptrNext; // avancamos o ponteiro atual para o seu "proximo", pois com o swap ele passa a ficar atras de ptrLarger
                }
            // Caso contrario, o maior valor passa a ser o do ponteiro atual
            else
                ptrLarger = ptrCurrent;
            
            // Avancamos o ponteiro atual para o proximo node, o "proximo" de ptrLarger
            ptrCurrent = ptrCurrent->ptrNext;
        }
    }

    return;
}
