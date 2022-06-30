#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
typedef struct Node{
  int value;
  struct Node *next;
  struct Node *previous;
}Node;
 
typedef struct Queue{
  Node *front;
  Node *back;
  int size;
}Queue;
/*
typedef struct nodepriority_
{
  int value;
  int priority;
  struct Node *next;
  struct Node *previous;
}Nodep;

typedef struct priorityqueue_
{
  Nodep *front;
  Nodep *back;
  int size;
}Priority_Queue;

Node *new_node_priority(int x, int priority)
{
  Nodep *node = (Node*) malloc(sizeof(Node));
  node->value = x;
  node->priority = priority;
  node->next = NULL;
  node->previous = NULL;
  return node;
}

Priority_Queue *new_pq()
{
  Priority_Queue *p_queue = (Priority_Queue*)malloc(sizeof(Priority_Queue));
  p_queue->front = p_queue->back = NULL;
  p_queue->size = 0;
  return p_queue;
}

void enqueue_priority(Priority_Queue *pq, int value, int priority)
{
  Nodep *new_node = (Nodep*) malloc(sizeof(Nodep));
  new_node->value = value;
  new_node->priority = priority;
  if ((pq->front == NULL) || (priority > pq->front->priority))
  {
    new_node->next = pq->front;
    pq->front = new_node;
  } 
  else 
  {
    Nodep *current = pq->front;
    Nodep *proximo = current->next;
    while ((current->next != NULL) && (proximo->priority > priority))
    {
      current = current->next;
      proximo = current->next;
    }
    new_node->next = proximo;
    current->next = new_node;
  }
  pq->size++;
}

int *dequeuepriority(Priority_Queue *pq)
{
  if (pq->size == 0)
  {
    printf("Priority Queue underflow\n");
    return -1;
  }
  int value = pq->front->value;  
  if(pq->size == 1)
    {
      free(pq->back);
      pq->front = pq->back = NULL;
  }
  else 
  {
    Nodep *temp = pq->front;
    pq->front = temp->next;
    pq->front->previous = NULL;
    free(temp);
  }
  pq->size--;
  return value;
}
*/

Node *createNode(int value){
  Node *node = (Node*) malloc(sizeof(Node));
  node->next = NULL;
  node->previous = NULL;
  node->value = value;
  return node;
}
 
Queue *createQueue(){
  Queue *queue = (Queue*)malloc(sizeof(Queue));
  queue->front = queue->back = NULL;
  queue->size = 0;
  return queue;
}
 
void enqueue(Queue *queue, int value){
  Node *node = createNode(value);
  if(queue->size == 0){
    queue->front = queue->back = node;
  } else {
    queue->back->next = node;
    node->previous = queue->back;
    queue->back = node;
  }
  queue->size++;
}
 
int dequeue(Queue *queue){
  if(queue->size == 0){
    printf("Fila Vazia\n");
    return -1;
  }
  int value = queue->front->value;
  if(queue->size == 1){
      free(queue->back);
      queue->front = queue->back = NULL;
  } else {
    Node *temp = queue->front;
    queue->front = temp->next;
    queue->front->previous = NULL;
    free(temp);
  }
  queue->size--;
  return value;
}
 
int main() {
  Queue *q = createQueue();
  int i;
  for(i = 1 ; i <= 10; i++)
  {
    enqueue(q, i);
  }
  for(i = 1; i<= 10; i++)
  {
    printf("%d\n", dequeue(q));
  }
  return 0;
}
