#include <iostream>
#include "../headers/LinkedList.hpp"
// #include "../headers/SelectionSort.hpp"
#include "../headers/Utils.hpp"

// Funcao de ordenacao em SELECTION SORT
void selectionSort(struct ListNode** head, bool showSort_)
{
    // Ponteiro para o node externo
    struct ListNode* ptrOuter = (*head);
    // Ponteiro para o node interno 
    struct ListNode* ptrInner = nullptr;

    // Enquanto nao chegarmos ao final da lista externa
    while(ptrOuter != nullptr)
    {
        // Ponteiro iterno comeca apontando para o "proximo" do ponteiro externo
        ptrInner = ptrOuter->ptrNext;
        // Enquanto não chegarmos ao final da lista interna
        while(ptrInner != nullptr)
        {
            // Verifica se o valor do node externo eh maior que o valor do node interno
            if(ptrOuter->iData > ptrInner->iData)
            {
                // Cria um ponteiro temporario para o node interno
                struct ListNode* ptrTemp = ptrInner;

                // Chama uma funcao para trocar os nodes de posicao
                swapListNodes(head, ptrOuter, ptrInner);

                // Atualiza o ponteiro externo para o node temporario (para continuar a partir desse ponto)
                ptrOuter = ptrTemp;
                // Atualiza o ponteiro interno para o proximo node apos o node temporario/externo        
                ptrInner = ptrTemp->ptrNext;
                
                // Visualizar o ordenamento
                if(showSort_ == true) {
                        print_bars(*head);
                }
            }
            // Avanca para o proximo node interno
            ptrInner = ptrInner->ptrNext;
        }
        // Avanca para o proximo node externo
        ptrOuter = ptrOuter->ptrNext;
    }

    return;
}