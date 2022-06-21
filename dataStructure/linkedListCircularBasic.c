#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;


int main(){
	//creating pointer of type node
	node *head,*first,*second,*last;

	//creating memory of all node in heap
	head = (node*)malloc(sizeof(node));
	first = (node*)malloc(sizeof(node));
	second = (node*)malloc(sizeof(node));
	last = (node*)malloc(sizeof(node));

	//linking all  nodes
	head->next = first;
	first->next = second;
	second->next = last;
	last->next = head;

	//Storing data
	head->data = 5;
	first->data = 10;
	second->data = 15;
	last->data = 20;

	//traversing and displaying
	node *ptr;
	ptr = head;
	int i = 0;
	do{
		printf("%d element is %d\n",i,ptr->data);
		i++;
		ptr=ptr->next;
	}while(ptr!=head);
	return  0;
}