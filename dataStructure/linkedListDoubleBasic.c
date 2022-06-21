#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    node *prv;
    int data;
    node *next;
};
int main(){
    	//creating pointer of type node
	node *head,*first,*second,*last;

	//creating memory of all node in heap
	head = (node*)malloc(sizeof(node));
	first = (node*)malloc(sizeof(node));
	second = (node*)malloc(sizeof(node));
	last = (node*)malloc(sizeof(node));

	//linking all  nodes
    head->prv = NULL;
	head->next = first;
    first->prv = head;
	first->next = second;
    second->prv = first;
	second->next = last;
    last->prv = second;
	last->next = NULL;

	//Storing data
	head->data = 5;
	first->data = 10;
	second->data = 15;
	last->data = 20;

	//traversing and displaying
    //From Left to Right
	node *ptr;
	ptr = head;
	int i = 0;
    printf("From left to right\n");
    while(ptr!=NULL){
        printf("[%d] element of list is %d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
    printf("From right to left\n");
    //From Right to Left
    ptr = last;
    while(ptr!=NULL){
        printf("[%d] element of list is %d\n",i,ptr->data);
        i++;
        ptr=ptr->prv;
    }
    return  0;
}