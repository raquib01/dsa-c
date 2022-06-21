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

int isEmpty(node* head){
	return head==NULL;
}

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
	if(new==NULL){
		printf("List Overflow\n");
		return head;
	}
	new->data = data;
	new->next = head;
	return new;
}

node* insertAtEnd(node* head, int data){
	node* new = (node*)malloc(sizeof(node));
	if(new==NULL){
		printf("List Overflow\n");
		return head;
	}
	new->data = data;
	new->next = NULL;
	if(head==NULL){
		return new;
	}
	node* ptr = head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=new;
	return head;
}

node* deleteAtStart(node* head){
	if(head==NULL){
		return head;
	}
	node* temp = head->next;
	free(head);
	return temp;
}

node* deleteAtEnd(node* head){
	if(head==NULL){
		return head;
	}
	if(head->next==NULL){
		free(head);
		return NULL;
	}
	node* p = head;
	node* q = head->next;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	free(q);
	p->next=NULL;
	return head;
}

node* insertAtIndex(node* head, int index, int data){
	if(index==0){
        return head;
    }
	node* new = (node*)malloc(sizeof(node));
	if(new==NULL){
		printf("List Overflow\n");
		return head;
	}
	new->data = data;
	node* temp = head;
	for(int i=0;i<(index-1);i++){
		temp=temp->next;
	}
	new->next = temp->next;
	temp->next = new;
	return head;

}

node* deleteAtIndex(node* head, int index){
	if(index==0){
        return head;
    }
	node* p = head;
	for(int i=0;i<(index-1);i++){
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