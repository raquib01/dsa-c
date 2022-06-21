#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct queue{
	int front;
	int rear;
	int* arr;
}queue;

int isFull(queue* q){
	return (q->rear+1)%SIZE == q->front;
}

int isEmpty(queue* q){
	return q->front==-1;
}

void display(queue* q){
	if(isEmpty(q)){
		printf("Queue is Empty\n");
		return;
	}
	for(int i = q->front; i!=q->rear; i=(i+1)%SIZE){
		printf("%d | ",q->arr[i]);
	}
	printf("%d\n",q->arr[q->rear]);
}

void enqueue(queue* q, int data){
	if(isFull(q)){
		printf("Queue Overflow\n");
		return;
	}
	q->rear = (q->rear+1)%SIZE;
	q->arr[q->rear] = data;
	if(q->front==-1){
		(q->front)++;
	}
}

void dequeue(queue* q){
	if(isEmpty(q)){
		return;
	}
	if(q->front==q->rear){
		q->front=-1;
		q->rear=-1;
		return;
	}
	q->front=(q->front+1)%SIZE;

}
int main(){
	//creating queue
	queue* q = (queue*)malloc(sizeof(queue));
	q->arr = (int*)malloc(sizeof(int)*SIZE);
	q->rear = -1;
	q->front = -1;
	display(q);
	
	return 0;
}