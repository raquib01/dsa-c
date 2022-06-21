/*
Always watch for the exception case:
1. list is empty i.e head==NULL
2. list is full i.e new==NULL
3. list has one element head->next==NULL
4. insert or delete At Index 0
*/

/*
recommended:
add if(new==NULL) then list is full
condition after every request for heap memory
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int data;
	node* next;
};

void display(node* head){
	if(head==NULL){
		printf("List is Empty\n");
		return;
	}
	int i = 0;
	node* ptr = head;
	do{
		printf("[%d]: %d\n",i,ptr->data);
		ptr=ptr->next;
		i++;
	}while(ptr!=head);
}

node* insertAtStart(node* head, int data){
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	if(head==NULL){
		new->next=new;
		return new;
	}
	new->next = head;
	
	node* ptr = head;
	while(ptr->next!=head){
		ptr=ptr->next;
	}
	ptr->next = new;
	return new;
}

node* insertAtEnd(node* head, int data){
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	if(head==NULL){
		new->next=new;
		return new;
	}
	new->next = head;

	node* ptr = head;
	while(ptr->next!=head){
		ptr=ptr->next;
	}
	ptr->next = new;
	return head;
}

node* deleteAtStart(node* head){
	if(head==NULL){
		return head;
	}
	if(head->next==head){
		free(head);
		return NULL;
	}
	node* new_head = head->next;

	node* ptr = head;
	while(ptr->next!=head){
		ptr=ptr->next;
	}
	ptr->next = new_head;
	free(head);
	return new_head;
}

node* deleteAtEnd(node* head){
	if(head==NULL){
		return head;
	}
	if(head->next==head){
		free(head);
		return NULL;
	}
	node* p = head;
	node* q = head->next;
	while(q->next!=head){
		p=p->next;
		q=q->next;
	}
	p->next=head;
	free(q);
	return head;

}

node* insertAtIndex(node* head, int data, int index){
	if(index==0){
		return head;
	}
	node* new = (node*)malloc(sizeof(node));
	new->data = data;

	node* ptr = head;
	for(int i = 0; i<(index-1); i++){
		ptr=ptr->next;
	}
	new->next = ptr->next;
	ptr->next = new;
	return head;
}

node* deleteAtIndex(node* head, int index){
	if(index==0){
		return head;
	}
	node* p = head;
	for(int i = 0; i<(index-1); i++){
		p=p->next;
	}
	node* q = p->next;
	p->next = q->next;
	free(q);
	return head;

}
int main(){
	node* head = NULL;
	display(head);

	return 0;
}