#ifndef __QUEUE_HPP_
#define __QUEUE_HPP_

#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

void enQueue(struct Queue** queue, int iValue);
int deQueue(struct Queue** queue);
void printQueue(struct Queue* queue);
bool isEmpty(struct Queue* queue);
struct QueueNode* newQueueNode(int iData);
struct Queue* newQueue();

struct QueueNode {
    int iData;
    struct QueueNode* ptrNext;
};

struct Queue {
    struct QueueNode* ptrFront;
    struct QueueNode* ptrRear;
};

#endif  // __QUEUE_HPP_