/*
Consider head as top
so that operations will be smooth
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int data;
	node* next;
};

int isEmpty(node* top){
	return top==NULL;
}

void display(node* ptr){
	if(ptr==NULL){
		printf("Stack is Empty\n");
		return;
	}
	int i = 0;
	while(ptr!=NULL){
		printf("[%d]: %d\n",i,ptr->data);
		ptr=ptr->next;
		i++;
	}
}

void stackTop(node* top){
	if(isEmpty(top)){
		return;
	}
	printf("%d is at the top\n",top->data);
}

void stackBottom(node* top){
	if(isEmpty(top)){
		return;
	}
	node* ptr = top;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	printf("%d is at bottom\n",ptr->data);
}

node* push(node* top, int data){
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->next = top;
	return new;
}

node* pop(node* top){
	if(top==NULL){
		return top;
	}
	node* ptr = top->next;
	free(top);
	return ptr;
}

int main(){
	node* top = NULL;
	display(top);
	
	return 0;
}