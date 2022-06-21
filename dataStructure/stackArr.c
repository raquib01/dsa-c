#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct stack
{
	int top;
	int *arr;
} stack;

stack *create()
{
	stack *a = (stack *)malloc(sizeof(stack));
	a->arr = (int *)malloc(sizeof(int) * SIZE);
	a->top = -1;
	return a;
}

int isEmpty(stack *s)
{
	return (s->top == -1);
}

int isFull(stack *s)
{
	return (s->top == SIZE - 1);
}

void display(stack *s)
{
	if (isEmpty(s))
	{
		printf("Stack is Empty\n");
		return;
	}
	for (int i = s->top; i >= 0; i--)
	{
		printf("[%d]: %d\n", i, s->arr[i]);
	}
}

void stackTop(stack *s)
{
	if (isEmpty(s))
	{
		return;
	}
	printf("%d is at the top\n", s->arr[s->top]);
}

void stackBottom(stack *s)
{
	if (isEmpty(s))
	{
		return;
	}
	printf("%d is at the bottom\n", s->arr[0]);
}

void peek(stack *s, int index)
{
	if (index > s->top)
	{
		return;
	}
	printf("[%d]: %d\n", index, s->arr[index]);
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

void pop(stack *s)
{
	if (isEmpty(s))
	{
		printf("Stack Underflow\n");
		return;
	}
	(s->top)--;
}
int main()
{
	stack *a = create();

	display(a);
	return 0;
}