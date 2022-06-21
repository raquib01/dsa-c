#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int data;
	node *next;
};

void display(node* ptr){
	if(ptr==NULL){
		printf("List is Empty\n");
	}
	int i = 0;
	while(ptr!=NULL){ //traversing list and printing it
		printf("%d element of list is %d\n",i,ptr->data);
		ptr=ptr->next;
		i++;
	}
}

void insertAtStart(node** head_ref, int data){
	node* new_ptr = (node*)malloc(sizeof(node)); //creating new node
	new_ptr->data = data; //putting data in new node

	new_ptr->next = (*head_ref); //connection node
	(*head_ref) = new_ptr;	//updating head(becos its inserted at start)
	return;
}

void insertAtIndex(node** head_ref, int data, int index){
	if(index==0 || (*head_ref)==NULL){
		printf("INVALID\n");
		return;
	}
	node* new_ptr = (node*)malloc(sizeof(node)); //creating new node
	new_ptr->data = data; //putting data in new node

	node* ptr = (*head_ref); //cpy head in temp ptr
	int i = 0;
	while(i!=index-1){ //traversing to one node before the index node
		ptr=ptr->next;
		i++;
	}

	new_ptr->next=ptr->next; //linking
	ptr->next=new_ptr; //linking

	return;
}

void insertAtEnd(node** head_ref, int data){
	if((*head_ref)==NULL){
		printf("INVALID\n");
		return;
	}
	node* new_ptr = (node*)malloc(sizeof(node)); //creating new node
	new_ptr->data = data; //putting data in new node

	node* ptr = (*head_ref); //cpy head in temp ptr
	while(ptr->next!=NULL){ //traversing to end node
		ptr=ptr->next;
	}

	ptr->next=new_ptr; //connecting node
	new_ptr->next=NULL; //NULLing new node(becos its inserted at end)

	return;

}


void deleteAtStart(node** head_ref){
	if((*head_ref)==NULL){
		printf("INVALID\n");
		return;
	}
	node* ptr = (*head_ref); //cpy head in ptr
	(*head_ref) = (*head_ref)->next; //updating head
	free(ptr); //free prv head
	return;
}

void deleteAtIndex(node** head_ref,int index){
	if(index==0 || (*head_ref)==NULL){
		printf("INVALID\n");
		return;
	}
	int i = 0;
	node* p = (*head_ref); //cpy head in p
	while(i!=index-1){ //traversing p to index - 1
		p=p->next;
		i++;
	}
	node* q = p->next; //making q pointing to index
	p->next = q->next; //linking
	free(q); //free node
	return;
}

void deleteAtEnd(node** head_ref){
	if((*head_ref)==NULL || (*head_ref)->next==NULL){
		printf("INVALID\n");
		return;
	}
	node* p = (*head_ref); //p pointing to head
	node* q = (*head_ref)->next; //q pointing to one node after head
	while(q->next!=NULL){ //traversing p and q till q reach end
		p=p->next;
		q=q->next;
	}
	p->next=NULL; //nulling n-1 node
	free(q); //free last node
	return; //no changes to head

}


int main(){
	//creating head
	node* head = NULL;
}