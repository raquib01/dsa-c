#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct queue{
	int front;
	int rear;
	int* arr;
}queue;

int isEmpty(queue* q){
	return q->front==-1 || (q->front)>(q->rear);
}

int isFull(queue* q){
	return q->rear==SIZE-1;
}

void display(queue* q){
	if(isEmpty(q)){
		printf("Queue is Empty\n");
		return;
	}
	for(int i = q->front; i<=q->rear; i++){
		printf("%d | ",q->arr[i]);
	}
	printf("\n");
}

void enqueue(queue* q, int data){
	if(isFull(q)){
		printf("Queue is Full\n");
		return;
	}
	if(q->front==-1){
		(q->front)++;
	}
	(q->rear)++;
	q->arr[q->rear] = data;
}

void dequeue(queue* q){
	if(isEmpty(q)){
		return;
	}
	(q->front)++;
}

void peek(queue* q){
	if(isEmpty(q)){
		return;
	}
	printf("%d is at front\n",q->arr[q->front]);
}

void reset(queue* q){
	q->front = -1;
	q->rear = -1;
}
int main(){
	//creating queue
	queue* q = (queue*)malloc(sizeof(queue));
	q->front = -1;
	q->rear = -1;
	q->arr = (int*)malloc(sizeof(int)*SIZE);

	display(q);
	return 0;
}