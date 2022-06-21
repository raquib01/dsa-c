/*
	Binary Search Tree
		8
	   / \
	  5   12
	 / \  / \
	3   7 9 13

*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int data;
	node* left;
	node* right;
};

node* create(int data){
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void inorder(node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int main(){
	//creating node
	node* root = create(8);
	node* p1 = create(5);
	node* p2 = create(12);
	node* q1 = create(3);
	node* q2 = create(7);
	node* q3 = create(9);
	node* q4 = create(13);

	//linking
	root->left = p1;
	root->right = p2;
	p1->left = q1;
	p1->right = q2;
	p2->left = q3;
	p2->right = q4;

	//inorder traversal
	printf("Inorder Traversal:\n");
	inorder(root);
	printf("\n");
	return 0;
}