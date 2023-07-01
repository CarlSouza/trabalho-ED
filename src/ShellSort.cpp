#include <iostream>
#include <bits/stdc++.h>

#include "../headers/LinkedList.hpp"

using std::cout;
using std::endl;

// Funcao para retornar o
int nextGap(double gap)
{
    if (gap < 2)
    	return 0;
    return (int)std::ceil(gap / 2);
}

// Calcula o comprimento da lista duplamente encadeada
int length(struct ListNode* head)
{
    int iLength = 0;
    
    while(head != nullptr) 
    {
        head = head->ptrNext;
        iLength++;
    }
    
    return iLength;
}

// Funcao de ordenacao em SHELL SORT
void shellSort(struct ListNode** head)
{
    // Se a lista esta vazia ou possui apenas um elemento, ela ja esta ordenada
    if ((*head) == nullptr || (*head)->ptrNext == nullptr)
        return;
    
    int iLength = length(*head);

    // Calcula o valor inicial do intervalo
    int iGap = iLength / 2;

    // Para todas as lacunas do tamanho k ate 1
    for (; iGap > 0; iGap = nextGap(iGap)) 
    {
        // Inicializa os ponteiros ptrLag, ptrMiddle e ptrLead
        struct ListNode* ptrLag = nullptr;
        struct ListNode* ptrMiddle = (*head);
        struct ListNode* ptrLead = (*head);
        
        // Contadores para colocar ptrLag e ptrLead na posicao correta
        int count = iGap;
        int count2;

        // Move o ponteiro "ptrLead" "iGap" nodes a frente
        while(count-- > 0)
            ptrLead = ptrLead->ptrNext;
        
        // Compara e troca os nodes apontados pelos ponteiros ptrMiddle e ptrLead
        for (; ptrLead != nullptr; ptrMiddle = ptrMiddle->ptrNext, ptrLead = ptrLead->ptrNext)
        {
            // se o valor do node apontado por ptrMiddle eh maior do que o valor do node apontado por ptrLead
            if (ptrMiddle->iData > ptrLead->iData)
            {
                struct ListNode* ptrTemp = ptrMiddle;
                
                // Trocamos ptrMiddle e ptrLead de posicao;
                swapListNodes(head, ptrMiddle, ptrLead);
                
                ptrMiddle = ptrLead;
                ptrLead = ptrTemp;
                
                // Conferimos se o node anterior ao ptrMiddle (considerando "iGap") eh maior do que ptrMiddle
                // ptrLag fica "iGap" nodes atras de ptrMiddle
                ptrLag = ptrMiddle;
                bool bSwapped = true;
                
                while(bSwapped)
                {
                    bSwapped = false;
                    
                    // Move o ponteiro "ptrLag" "iGap" nodes para tras
                    count2 = iGap;
                    while(ptrLag != nullptr && count2-- > 0)
                        ptrLag = ptrLag->ptrPrev;
                    
                    
                    if(ptrLag != nullptr && ptrLag->iData > ptrMiddle->iData)
                    {
                        bSwapped = true;
                        struct ListNode* ptrTemp = ptrLag;
                        
                        // Trocamos ptrLag e ptrMiddle de posicao;
                        swapListNodes(head, ptrLag, ptrMiddle);
                        
                        ptrLag = ptrMiddle;
                        ptrMiddle = ptrTemp;
                    }
                }
            }
        }
    }

    return;
}