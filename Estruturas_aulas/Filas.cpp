/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
// fila e pilha 26/04
using  std::cout;
using  std::cin;
using  std::endl;
using  std::string;




//Define a estrutura

struct Node 
{ 
   int iData;
   struct Node* Next;
};

// Fila usando linked list 
struct Queue 
{
 struct Node* front; // primeiro elemento
 struct Node* rear;  // ultimo elemento
 
};

struct Node* newNode(int iVal){// é uma função auxiliar que retornar um novo nó
    struct Node* temp=(struct Node*)malloc (sizeof(struct Node)); // ponteiro temporario
    temp->iData=iVal;
    temp->Next=nullptr;
    
    return temp;
    
}





struct Queue* newQueue()// é uma função auxiliar que retornar um ponteiro tipo fila
{
    struct Queue* temp=(struct Queue*)malloc (sizeof(struct Queue)); // ponteiro temporario
    temp->front=nullptr;
    temp->rear=nullptr;
    
    return temp;
    
}
// imprime o primeiro elemento
void FirstElement(struct Queue* queue)
{
    cout<<" Primeiro da Fila:  "<<((queue->front!=nullptr)?(queue->front)->iData:-1)<<endl;
    // o primeiro elemento é nulo ? 
}

// imprime o ultimo elmento
void LastElement(struct Queue* queue)
{
    cout<<" Último da Fila:  "<<((queue->rear!=nullptr)?(queue->rear)->iData:-1)<<endl;
    // o primeiro elemento é nulo ? 
}

// enfileirar
void enQueue(struct Queue* queue,int iVal)
{
    struct Node* temp = newNode(iVal);
    if (queue->rear == nullptr)
    {
        queue->front=temp;
        queue->rear=temp; // o primeiro e p último elemento tem que ser o mesmo cara
    }
    else
    {
        queue->rear->Next=temp;
        queue->rear=temp; 
    }
    return;
}

// desenfilerar 
void deQueue(struct Queue* queue)
{
  if(queue->front==nullptr)
  {
  cout<<"Fila vazia"<<endl;
  return;
      
  }
  struct Node* temp=queue->front;
  queue->front=queue->front->Next;
  
  //Dever 1: arrumar rear em cada fila vazia
  if(queue->front==nullptr) queue->rear=nullptr; 
  
  cout<<"deQueue: "<<temp->iData<<endl;
  
  free(temp);
}

//Dever 2:função printQueue
  
int main()
{
   
   struct Queue* queue=newQueue();
   
   
   
   enQueue(queue,3);
   enQueue(queue,7);
   enQueue(queue,10);
   enQueue(queue,666);
   
   cout<<"==============="<<endl;
   
   FirstElement(queue);
   LastElement(queue);
   
   cout<<"==============="<<endl;
   
   deQueue(queue);
   
   FirstElement(queue);
   LastElement(queue);
   
   
   
   cout<<"HEllo world"<<endl;   
   return 0;
}