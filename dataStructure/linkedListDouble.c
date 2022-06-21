/*
Always watch for the exception case:
1. list is empty i.e head==NULL
2. list is full i.e new==NULL
3. list has one element head->next==NULL
4. insert or delete At Index 0
5. if node is last in insertAtIndex and deleteAtIndex
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
	node* prv;
	node* next;
};

void display(node* ptr){
	if(ptr==NULL){
		printf("List is Empty\n");
		return;
	}
	int i = 0;
	while(ptr!=NULL){
		printf("[%d]: %d\n",i,ptr->data);
		ptr=ptr->next;
		i++;
	}
}

node* insertAtStart(node* head, int data){
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->prv = NULL;
	new->next = head;
	if(head==NULL){
		return new;
	}
	head->prv = new;
	return new;
}

node* insertAtEnd(node* head, int data){
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->next = NULL;
	if(head==NULL){
		new->prv = NULL;
		return new;
	}
	node* ptr = head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next = new;
	new->prv = ptr;
	return head;
}

node* deleteAtStart(node* head){
	if(head==NULL){
		return head;
	}
	node* ptr = head->next;
	free(head);
	if(ptr==NULL){
		return ptr;
	}
	ptr->prv = NULL;
	return ptr;
}

void* deleteAtEnd(node* head){
	if(head==NULL){
		return head;
	}
	if(head->next==NULL){
		free(head);
		return NULL;
	}
	node* q = head;
	while(q->next!=NULL){
		q=q->next;
	}
	node* p = q->prv;
	p->next = NULL;
	free(q);
	return head;

}

node* insertAtIndex(node* head, int index, int data){
	if(index==0){
		return head;
	}
	node* new = (node*)malloc(sizeof(node));
	new->data = data;

	int i = 0;
	node* p = head;
	for(int i = 0; i<(index-1); i++){
		p=p->next;
	}
	node* q = p->next;
	p->next = new;
	new->prv = p;
	new->next = q;
	if(q==NULL){
		return head;
	}
	q->prv = new;
	return head;
}

node* deleteAtIndex(node* head, int index){
	if(index==0){
		return head;
	}
	int i = 0;
	node* p = head;
	for(int i = 0; i<(index-1); i++){
		p=p->next;
	}
	node* q = p->next;
	node* r = q->next;
	free(q);
	p->next = r;
	if(r==NULL){
		return head;
	}
	r->prv = p;
	return head;
}

int main(){
	node* head = NULL;
	display(head);
	return 0;
}