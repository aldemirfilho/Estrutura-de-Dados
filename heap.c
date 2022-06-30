#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 10000

typedef struct heap 
{
	int size;
	int data[MAX_HEAP_SIZE];
}HEAP;

HEAP* create_heap()
{
	HEAP *new_heap = (HEAP*) malloc(sizeof(HEAP));
	new_heap->size = 0;
	return new_heap;
}

int get_parent_index(HEAP *heap, int i)
{
	return i/2;
}

int get_left_index(HEAP *heap, int i)
{
	return 2*i;
}

int get_right_index(HEAP *heap, int i)
{
	return 2*i + 1;
}

int item_of(HEAP *heap, int i)
{
	return heap->data[i];
}

void swap(int *x, int *y){ 
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

void max_heapify(HEAP *heap, int i)
{
	int largest;
	int left_index = get_left_index(heap, i);
	int right_index = get_right_index(heap, i);
	if (left_index <= heap->size && heap->data[left_index] > heap->data[i]) 
	{
		largest = left_index;
	} 
	else 
	{
		largest = i;
	}
	if (right_index <= heap->size && heap->data[right_index] > heap->data[largest]) 
	{
		largest = right_index;
	}

	if (heap->data[i] != heap->data[largest]) 
	{
		swap(&heap->data[i], &heap->data[largest]);
		max_heapify(heap, largest);
	}
}

void min_heapify(HEAP *heap, int i) //o no de menor frequencia no topo da heap
{
	int smallest;
	int left_index = get_left_index(heap, i);	
	int right_index = get_right_index(heap, i);
	if (left_index <= heap->size && heap->data[left_index] < heap->data[i])
	{
		smallest = left_index;	//recebe indice do menor: left (esta no lugar errado)
	}
	else
	{
		smallest = i; //meu menor ainda é o i;
	}
	if (right_index <= heap->size && heap->data[right_index] < heap->data[smallest]) 
	{
		smallest = right_index; //recebe o indice do menor: right (esta no lugar erradp)
	}
	if  (heap->data[i] != heap->data[smallest]) // se for menor que o meu topo, ja que sempre i = 1
	{
		swap(&(heap->data[i]), &(heap->data[smallest]));
		min_heapify(heap, smallest);
	}
}

void heapsort(HEAP *heap)
{
	int i;
	for (i = heap->size; i >= 2; i--) 
	{
		swap(&heap->data[1], &heap->data[i]);
		heap->size--;
		max_heapify(heap, 1);
	}
}

void enqueue (HEAP *heap, int item)
{
	if (heap->size >= MAX_HEAP_SIZE)
	{
		printf("Heap overflow");
	}
	else
	{
		heap->data[++heap->size] = item;
		int key_index = heap->size;
		int parent_index = get_parent_index(heap, heap->size);
		while (parent_index >= 1 && heap->data[key_index] > heap->data[parent_index])
		{
			swap(&heap->data[key_index], &heap->data[parent_index]);
			key_index = parent_index;
			parent_index = get_parent_index(heap, key_index);
		}
	}
}

int dequeue (HEAP *heap)
{
	if(heap == NULL || heap->size == 0)
	{
		printf("Heap underflow");
		return -1;
	} 
	else 
	{
		int item = heap->data[1];
		heap->data[1] = heap->data[heap->size];
		heap->size--;
		max_heapify(heap, 1);
		return item;
	}
}

void print_heap(HEAP *heap, int size)
{
	int i;
	for(i = 1; i <= size; i++)
	{
		printf("%d\n", heap->data[i]);
	}
	puts("");
}


int main()
{
	printf("\n");
	int qntd, i, element;
	printf("Digite a quantida de elementos...\n");
	scanf("%d", &qntd);
	printf("\n");
	HEAP *heap = create_heap();
	printf("Digite os elementos que irao compor a Heap...\n");
	for(i = 0; i < qntd; i++)
	{
		scanf("%d", &element);
		enqueue(heap, element);
	}
	printf("\n");
	printf("Heap atual\n");
	print_heap(heap, heap->size);
	printf("Deseja remover algum elemento da heap?\n(SIM) -> Digite 1	(NAO) -> Digite 2\n");
	int op;
	scanf("%d", &op);
	printf("\n");
	if(op == 1)
	{
		while(op == 1)
		{
			dequeue(heap);
			printf("Heap atual\n");
			print_heap(heap, heap->size);
			printf("Deseja remover outro elemento da heap?\n(SIM) -> Digite 1	(NAO) -> Digite 2\n");
			scanf("%d", &op);
			printf("\n");
		}
	}
	printf("Heap atual\n");
	print_heap(heap, heap->size);
	int size = heap->size;
	printf("Deseja ordenar os elementos da heap?\n(SIM) -> Digite 1	(NAO) -> Digite 2\n");
	scanf("%d", &op);
	printf("\n");
	if(op == 1)
	{
		heapsort(heap);
	}
	heap->size =  size;
	printf("Heap atual\n");
	print_heap(heap, heap->size);
	printf("Deseja ver a o conteudo de alguma posicao especifica na heap?\n(SIM) -> Digite 1	(NAO) -> Digite 2\n");
	scanf("%d", &op);
	printf("\n");
	if(op == 1)
	{
		int pos;
		printf("Digite a posicao de interesse...\n");
		scanf("%d", &pos);
		printf("\n");
		printf("Conteudo na posicao [%d] -> %d\n", pos, item_of(heap, 4));
	}
	return 0;
}
