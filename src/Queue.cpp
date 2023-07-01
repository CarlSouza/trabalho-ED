#include "../headers/Queue.hpp"

struct QueueNode* newQueueNode(int iData) {
    struct QueueNode* ptrTemp = (struct QueueNode*) malloc(sizeof(struct Queue));
    ptrTemp->iData = iData;
    ptrTemp->ptrNext = nullptr;
    
    return ptrTemp;
}

struct Queue* newQueue() {
    // Criar um struct convertendo um ponteiro de void para o struct Node
    struct Queue* ptrTemp = (struct Queue*) malloc(sizeof(struct Queue));
    ptrTemp->ptrFront = nullptr;
    ptrTemp->ptrRear = nullptr;
    
    return ptrTemp;
};

// função de insert com um nome diferente :/
void enQueue(struct Queue** queue, int iValue) {
    struct QueueNode* ptrTemp = newQueueNode(iValue);

    if ((*queue)->ptrRear == nullptr) {
        (*queue)->ptrFront = (*queue)->ptrRear = ptrTemp;
        return;
    }

    (*queue)->ptrRear->ptrNext = ptrTemp;
    (*queue)->ptrRear = ptrTemp;
}

int deQueue(struct Queue** queue) {
    if ((*queue)->ptrFront == nullptr) {
        return -1;
    }

    struct QueueNode* ptrTemp = (*queue)->ptrFront;

    (*queue)->ptrFront = (*queue)->ptrFront->ptrNext;

    if ((*queue)->ptrFront == nullptr) {
        (*queue)->ptrRear = nullptr;
    }

    int iData = ptrTemp->iData;

    free(ptrTemp);
    return iData;
}

void printQueue(struct Queue* queue) {
    struct QueueNode* ptrTemp = queue->ptrFront;

    while (ptrTemp != nullptr) {
        cout << ptrTemp->iData << " ";
        ptrTemp = ptrTemp->ptrNext;
    }

    cout << endl;
}

bool isEmpty(struct Queue* queue) {
    return queue->ptrFront == nullptr;
}