/*
	     root(5)
	   /        \
	 p1(3)      p2(7)
	 /    \       /   \
  p3(2) p4(4)  p5(6)  Null

*/#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int data;
	node* left;
	node* right;
};

node* create(int data){// creating node and nulling its children
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void preorder(node* root){
	if(root!=NULL){
		printf("%d, ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d, ",root->data);
	}
}
void inorder(node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d, ",root->data);
		inorder(root->right);
	}
}
int main(){
	//creating node
	node* root = create(5);
	node* p1 = create(3);
	node* p2 = create(7);
	node* p3 = create(2);
	node* p4 = create(4);
	node* p5 = create(6);

	//linking
	root->left = p1;
	root->right = p2;
	p1->left = p3;
	p1->right = p4;
	p2->left = p5;

	//preorder
	printf("Preorder: ");
	preorder(root);

	//postorder
	printf("\nPostorder: ");
	postorder(root);

	//inorder
	printf("\nInorder: ");
	inorder(root);
	
	return 0;
}