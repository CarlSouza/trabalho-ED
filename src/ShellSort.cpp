#include <iostream>
#include "../headers/LinkedList.hpp"
// #include "../headers/ShellSort.hpp"

using std::cout; //Pois há um cout na linha 27 e 37
using std::endl;

// Funcao de ordenacao em SHELL SORT
void shellSort(struct ListNode** head)
{
    struct ListNode* ptrCurrent = nullptr;

    if((*head) == nullptr || (*head)->ptrNext == nullptr)
        return;

    struct ListNode* ptrTemp = nullptr;
    struct ListNode* ptrSlow = nullptr;
    struct ListNode* ptrFast = nullptr;
    bool bUnordered = true;

    while(bUnordered)
    {
        bUnordered = false;
        ptrFast = (*head);
        ptrSlow = (*head);
        ptrCurrent = (*head);

        cout << "Inicio loop " << ptrSlow->iData << " " << ptrFast->iData << " " << endl;

        while(ptrFast->ptrNext != nullptr && ptrFast->ptrNext->ptrNext != nullptr && ptrFast->ptrNext != ptrTemp && ptrFast->ptrNext->ptrNext != ptrTemp)
        {
            ptrFast = ptrFast->ptrNext->ptrNext;
            ptrSlow = ptrSlow->ptrNext;
        }

        // Salvar o valor de ptrSlow em ptrTemp antes de ser modificado
        ptrTemp = ptrSlow;
        cout << "Apos divisao " << ptrSlow->iData << " " << ptrFast->iData << " " << ptrTemp->iData << endl;

        if(ptrSlow == ptrFast)
            break;

        while(ptrSlow->ptrNext != nullptr)
        {
            if(ptrCurrent->iData > ptrSlow->iData)
                {
                    if(ptrSlow == ptrTemp)
                        ptrTemp = ptrCurrent;

                    struct ListNode* TempSlow = ptrSlow;
                    swapListNodes(head, ptrCurrent, ptrSlow);
                    bUnordered = true;
                    ptrSlow = ptrCurrent;
                    ptrCurrent = TempSlow;
                }
            
            cout << "Trocou " << ptrSlow->iData << " <-> " << ptrCurrent->iData << " T: " << ptrTemp->iData << " =        ";

            ptrSlow = ptrSlow->ptrNext;
            ptrCurrent = ptrCurrent->ptrNext;

            // printList(*head);
        }

    }
    // bubbleSort(head);
    // printList(*head);

    return;
}