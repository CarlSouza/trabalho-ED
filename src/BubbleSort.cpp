#include <iostream>
#include "../headers/LinkedList.hpp"
// #include "../headers/BubbleSort.hpp"

#include "../headers/Utils.hpp"

// Funcao de ordenacao em BUBBLE SORT
void bubbleSort(struct ListNode** head, bool showSort_)
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
                    swapListNodes(head, ptrLarger, ptrCurrent);       // trocamos eles de posicao;
                    bUnordered = true;                                // trocamos o status de desordenado para verdadeiro

                    ptrCurrent = ptrCurrent->ptrNext;                // avancamos o ponteiro atual para o seu "proximo", pois 
                                                                      // com o swap ele passa a ficar atras de ptrLarger
                    if(showSort_ == true) {
                        std::cout << "OIIIIII" << std::endl;
                        int max_test = find_max(*head);
                        std::cout << "OPAAAA " << max_test << std::endl;
                    }
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