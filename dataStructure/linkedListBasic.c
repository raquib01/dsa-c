#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int data;
	node* next;
};
int main(){
	//heap memory for nodes
	node* head = (node*)malloc(sizeof(node));
	node* first = (node*)malloc(sizeof(node));
	node* second = (node*)malloc(sizeof(node));
	node* third = (node*)malloc(sizeof(node));	
	node* last = (node*)malloc(sizeof(node));

	//linking nodes
	head->next = first;
	first->next = second;
	second->next = third;
	third->next = last;
	last->next = NULL;

	//putting datas
	head->data = 4;
	first->data = 5;
	second->data = 6;
	third->data = 7;
	last->data = 8;

	//traversing
	node* ptr = head;
	int i = 0;
	while(ptr!=NULL){
		printf("[%d] %d\n",i,ptr->data);
		ptr=ptr->next;
		i++;
	}
	return  0;
}