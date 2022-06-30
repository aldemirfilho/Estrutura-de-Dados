#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
  int value;
  struct Node *next;
}Node;
 
typedef struct Stack{
  Node *top;
  int size;
}Stack;

Node *createNode(int value){
  Node *node = (Node*) malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}
 
Stack *createStack(){
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  stack->size = 0;
  stack->top = NULL;
  return stack;
}
 
int getSize(Stack *stack){
  return stack->size;
}
 
int top(Stack *stack){
  if(stack == NULL || stack ->size == 0){
    printf("Pilha Vazia\n");
    return -1;
  }
  return stack->top->value;
}
 
void push(Stack *stack, int value)
{
  Node *node = createNode(value);
  node->next = stack->top;
  stack->top = node;
  stack->size++;
}
 
int pop(Stack *stack){
  if(stack == NULL || stack->size == 0){
    printf("Pilha Vazia\n");
    return -1;
  }
  int value = stack->top->value;
  Node *temp = stack->top;
  stack->top = temp->next;
  free(temp);
  stack->size--;
  return value;
}
 
 
int main()
{
	int qntd, i;
	printf("\n");
	printf("Digite a quantidade de elementos...\n");
	scanf("%d", &qntd);
	printf("\n");
	printf("Digite os elementos...\n");
	int elements[qntd];
	Stack *stack = createStack();
	for (i = 0; i < qntd; i++)
	{
		scanf("%d", &elements[i]);
		push(stack, elements[i]);
	}
	printf("\n");
	int op = 0;
	while(op != 2)
	{
		printf("Deseja remover um elemento do topo?\n(SIM) -> Digite 1	(NAO) -> Digite 2\n");
		scanf("%d", &op);
		if(op == 1)
		{
			int removed = pop(stack);
			printf("removido -> %d\n", removed);
			printf("\n");
		}
	}
	printf("\n");
	printf("Deseja saber o topo atual?\n(SIM) -> Digite 1	(NAO) -> Digite 2\n");
	scanf("%d", &op);
	if(op == 1)
	{
		int topo = top(stack);
		printf("topo -> %d\n", topo);
	}
	return 0;
}
