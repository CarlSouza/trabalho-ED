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
void enQueue(struct Queue* queue, int iValue) {
    struct QueueNode* ptrTemp = newQueueNode(iValue);
    if (queue->ptrRear == nullptr) {
        queue->ptrFront = ptrTemp;
        queue->ptrRear = ptrTemp;
    } else {
        // lembra que o último da fila tá apontando pra nullptr? nós fazemos o último apontar pra esse novo elemento
        queue->ptrFront->ptrNext = ptrTemp;
        // Agora temos que fazer o struct da fila reconhecer esse novo elemento como último
        queue->ptrRear = ptrTemp;
    }
}

void deQueue(struct Queue* queue) {
    // tanto faz perguntae se o último ou o primeiro estão vazios
    if (queue->ptrFront == nullptr) {
        cout << "Fila vazia." << endl;
    } else {
        struct QueueNode* ptrTemp = queue->ptrFront;
        
        queue->ptrFront = queue->ptrFront->ptrNext;
        // para o caso de se remover o último elemento, precisamos modificar o ponto rear antes de apagar
        if (queue->ptrFront == nullptr) queue->ptrRear = nullptr;
        cout << "deQueue: " << ptrTemp->iData << endl;
        
        free(ptrTemp);
    }
}