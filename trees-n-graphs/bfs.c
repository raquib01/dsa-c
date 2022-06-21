#include <stdio.h>
#include <stdlib.h>
#define G_SIZE 7
#define Q_SIZE 30
// queue size must be >= Graph Size
typedef struct queue
{
	int front;
	int rear;
	int *arr;
} queue;

int isEmpty(queue *q)
{
	return q->front == -1 || (q->front) > (q->rear);
}

int isFull(queue *q)
{
	return q->rear == G_SIZE - 1;
}

void enqueue(queue *q, int data)
{
	if (isFull(q))
	{
		printf("Queue is Full\n");
		return;
	}
	if (q->front == -1)
	{
		(q->front)++;
	}
	(q->rear)++;
	q->arr[q->rear] = data;
}

int dequeue(queue *q)
{
	if (isEmpty(q))
	{
		return -1;
	}
	int temp = (q->front);
	(q->front)++;
	return temp;
}

int main()
{
	// creating queue
	queue *q = (queue *)malloc(sizeof(queue));
	q->front = -1;
	q->rear = -1;
	q->arr = (int *)malloc(sizeof(int) * Q_SIZE);

	// graph matrix repr
	int a[G_SIZE][G_SIZE] = {
		{0, 1, 1, 1, 0, 0, 0},
		{1, 0, 0, 0, 1, 1, 0},
		{1, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 1},
		{0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0}};

	// BFS
	int visited[G_SIZE] = {0, 0, 0, 0, 0, 0, 0}; // arr of visited node

	// Visiting First/Source Node
	int i = 0;
	printf("%d", i);
	enqueue(q, i);
	visited[i] = 1;

	// Visiting rest of the graph
	int node = -1; // current node
	while (!isEmpty(q))
	{
		node = dequeue(q);
		for (int j = 0; j < G_SIZE; j++)
		{
			if (a[node][j] == 1 && visited[j] == 0) // checking if node is connected and visited or not
			{
				// visiting connected and unvisited node
				printf("%d", j);
				enqueue(q, j);
				visited[j] = 1;
			}
		}
	}
	return 0;
}