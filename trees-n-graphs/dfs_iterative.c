#include <stdio.h>
#include <stdlib.h>
#define G_SIZE 7
#define S_SIZE 30
// stack size should be >= graph size
typedef struct stack
{
	int top;
	int *arr;
} stack;

int isEmpty(stack *s)
{
	return (s->top == -1);
}

int isFull(stack *s)
{
	return (s->top == S_SIZE - 1);
}

void push(stack *s, int data)
{
	if (isFull(s))
	{
		printf("Stack Overflow\n");
		return;
	}
	(s->top)++;
	s->arr[s->top] = data;
}

int pop(stack *s)
{
	if (isEmpty(s))
	{
		printf("Stack Underflow\n");
		return -1;
	}
	int temp = s->arr[s->top];
	(s->top)--;
	return temp;
}

int main()
{
	// creating stack
	stack *s = (stack *)malloc(sizeof(stack));
	s->arr = (int *)malloc(sizeof(int) * S_SIZE);
	s->top = -1;

	// graph matrix repr
	int a[G_SIZE][G_SIZE] = {
		{0, 1, 1, 1, 0, 0, 0},
		{1, 0, 0, 0, 1, 1, 0},
		{1, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 1},
		{0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0}};

	// DFS
	int visited[G_SIZE] = {0, 0, 0, 0, 0, 0, 0}; // arr of visited node

	// Visiting First/Source Node
	int i = 0;
	visited[i] = 1;
	push(s, i);

	// Visiting rest of the graph
	int node; // current node
	while (!isEmpty(s))
	{
		node = pop(s);
		printf("%d", node);

		for (int j = 0; j < G_SIZE; j++)
		{
			if (a[node][j] == 1 && visited[j] == 0) // checking if node is connected and visited or not
			{
				// visiting connected and unvisited node
				visited[j] = 1;
				push(s, j);
			}
		}
	}
	return 0;
}