#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define MAX_QUEUE_SIZE 100

typedef struct adj_list{
	int item;
	struct adj_list *next;
}adj_list;

typedef struct graph{
	adj_list *vertices[MAX_SIZE];
	short visited[MAX_SIZE];
}Graph;

typedef struct queue{
	int current_size;
	int head;
	int tail;
	int items[MAX_QUEUE_SIZE];
}queue;

queue* create_queue()
{
	queue *new_queue = (queue*) malloc(sizeof(queue));
	new_queue->current_size = 0;
	new_queue-> head =0;
	new_queue->tail = MAX_QUEUE_SIZE-1;
	return new_queue;
}

void enqueue(queue *queue, int item)
{
	if(queue->current_size >= MAX_QUEUE_SIZE)
	{
		printf("Queue overflow");
	}
	else
	{
		queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
		queue->items[queue->tail] = item;
		queue->current_size++;
	}
	//printf("numero adicionado na posição %d\n", queue->tail);
}

int is_empty(queue *queue)
{
	return(queue->current_size == 0);
}

int dequeue(queue *queue)
{
	int dequeued=-1;
	if((is_empty(queue)))
	{
		printf("Underflow\n");
	}
	else
	{
		dequeued = queue->items[queue->head];
		queue->head = (queue->head +1)%MAX_QUEUE_SIZE;
		queue->current_size--;
		return dequeued;
	}
}

Graph* create_graph()
{
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	int i;
	for(i = 1; i <= MAX_SIZE - 1; i++)
	{
		graph->vertices[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

adj_list* create_adj_list(int item)
{
	adj_list *new_adj_list = (adj_list*) malloc(sizeof(adj_list));
	new_adj_list->item = item;
	new_adj_list->next = NULL;
	return new_adj_list;
}

void add_edge(Graph *graph, int vertex1, int vertex2)
{
	adj_list *vertex = create_adj_list(vertex2);
	vertex->next = graph->vertices[vertex1];
	graph->vertices[vertex1] = vertex;
	//Undirected graph. Edge to the other direction as well.
	vertex = create_adj_list(vertex1);
	vertex->next = graph->vertices[vertex2];
	graph->vertices[vertex2] = vertex;
}

void dfs(Graph *graph, int source)
{
	graph->visited[source] = 1;
	printf("%d\n", source);
	adj_list *adj_list = graph->vertices[source];
	while(adj_list != NULL)
	{
		if(!graph->visited[adj_list->item])
		{
			dfs(graph, adj_list->item);
		}
		adj_list = adj_list->next;
	}
}

void bfs(Graph *graph, int source)
{
	queue *queue = create_queue();
	int dequeued;
	adj_list *adj_list = graph->vertices[source];
	graph->visited[source] = 1;
	enqueue(queue,source);

	while(!is_empty(queue))
	{
		dequeued = dequeue(queue);
		adj_list = graph->vertices[dequeued];
		while(adj_list != NULL)
		{
			if(!graph->visited[adj_list->item])
			{
				printf("%d\n", adj_list->item);
				graph->visited[adj_list->item] = 1;
				enqueue(queue, adj_list->item);
			}
			adj_list = adj_list->next;
		}
	}
}

void print_graph(Graph *graph);

void menu();

void clean(Graph *graph)
{
	int i;
	for(i=1; i<= MAX_SIZE - 1; i++)
	{
		graph->visited[i] = 0;
	}

}

int main()
{
	int number,number2;
	Graph *undirected_graph = create_graph();
	int op;
	while(1)
	{
		menu();
		clean(undirected_graph);
		scanf("%d", &op);
		printf("\n");
		if(op == 1)
		{
			printf("Write two number: ");
			scanf("%d %d", &number,&number2);
			printf("\n");
			add_edge(undirected_graph, number,number2);
		}
		if(op == 2)
		{
			printf("Write a number for a search: ");
			scanf("%d", &number);
			printf("\n");
			dfs(undirected_graph,number);
			printf("\n");
		}
		if(op == 3)
		{
			printf("Write a number for a search: ");
			scanf("%d", &number);
			printf("\n");
			bfs(undirected_graph,number);
			printf("\n");
		}
	}
	return 0;
}

void menu()
{
	printf("1....Add_edge\n");
	printf("2....Depth-first Search\n");
	printf("3....Breath-first Search\n");
	printf("\n");
	printf("choose an option....\n");
}