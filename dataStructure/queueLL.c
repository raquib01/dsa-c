#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int data;
	node* next;
};
//initializing node as global var
	node* f = NULL;
	node* r = NULL;

void enqueue(int data){
	node* new = (node*)malloc(sizeof(node));
	if(new==NULL){
		printf("Queue Overflow...\n");
		return;
	}
	new->data = data;
	new->next=NULL;
	if(f==NULL){
		f=new;
		r=new;
		return;
	}
	r->next=new;
	r=new;
}

void dequeue(){
	if(f==NULL){
		printf("Queue Underflow...\n");
		return;
	}
	node* temp;
	temp = f;
	f = f->next;
	free(temp);
}

void display(){
	if(f==NULL){
		printf("Queue is Empty\n");
		return;
	}
	node* ptr = f;
	while(ptr!=NULL){
		printf("%d | ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int main(){
	display(f);
	return  0;
}