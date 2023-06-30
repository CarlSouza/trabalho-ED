#include <iostream>

#include "../headers/LinkedList.hpp"
#include "../headers/Utils.hpp"

// Funcao de ordenacao em INSERTION SORT
void insertionSort(struct ListNode** head, bool showSort_)
{
    // Verificar se a lista esta vazia ou se possui apenas um elemento
    if ((*head) == nullptr || (*head)->ptrNext == nullptr)
    {
        // Caso base: a lista está vazia ou possui apenas um elemento. Nesse caso, a lista ja esta ordenada, entao retornamos imediatamente.
        return;
    }
    
    // ptrOrdered aponta para o node atualmente sendo verificado na parte "ordenada" da lista
    struct ListNode* ptrOrdered = (*head);
    // ptrUnordered ira apontar para os nodes que serao realocados dentro da lista ordenada
    struct ListNode* ptrUnordered = nullptr;

    // Continuar enquanto ainda houver nodes nao verificados na lista
    while(ptrOrdered != nullptr)
    {
        // Verificar se o node atual (ptrOrdered) esta fora de ordem em relação ao node anterior (ptrOrdered->ptrPrev)
        if(ptrOrdered->ptrPrev != nullptr && ptrOrdered->iData < ptrOrdered->ptrPrev->iData)
        {
            // Se o node atual esta fora de ordem, ptrUnordered aponta para ele e inicia a operacao de realocacao
            ptrUnordered = ptrOrdered;

            // Chama a funcao swapNode para trocar o node atual (ptrOrdered) com o node anterior (ptrOrdered->ptrPrev)
            swapListNodes(head, ptrOrdered->ptrPrev, ptrOrdered);

            // Continuar a trocar o node ptrUnordered para tras ate encontrar sua posicao correta na lista ordenada
            while(ptrUnordered->ptrPrev != nullptr && ptrUnordered->iData < ptrUnordered->ptrPrev->iData)
            {
                // Chama a função swapNode para trocar o node ptrUnordered com o node anterior (ptrUnordered->ptrPrev)
                swapListNodes(head, ptrUnordered->ptrPrev, ptrUnordered);

                // Visualizar o ordenamento
                if(showSort_ == true) {
                    print_bars(*head);
                }
            }
        }
        // Mover para o proximo node na lista nao ordenada
        ptrOrdered = ptrOrdered->ptrNext;
    }

    return;
}