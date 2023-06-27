#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

void insertListNode(struct ListNode** head, int iVal);
void swapListNodes(struct ListNode** head, struct ListNode* Node1, struct ListNode* Node2);
void printList(struct ListNode* head);

// Estrutura de node das listas duplamente encadeadas
struct ListNode
{
    int iData;
    struct ListNode* ptrNext;
    struct ListNode* ptrPrev;
};


// Funcao para criar novos nodes
struct ListNode* createNode(int iVal, struct ListNode* next, struct ListNode* prev)
{
    struct ListNode* newNode = new struct ListNode;
    newNode->iData = iVal;
    newNode->ptrNext = next;
    newNode->ptrPrev = prev;

    return newNode;
}

#endif // __LINKED_LIST_H_