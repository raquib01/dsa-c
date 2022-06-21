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

void insertion(node* root, int data){
	node* prv = NULL;
	while(root!=NULL){
		prv = root;
		if(root->data==data){
			printf("Cannot Insert %d, Already Exist\n",data);
			return;
		}
		if(root->data>data){
			root = root->left;
		}
		else{
			root = root->right;
		}
	}
	if(prv->data>data){
		prv->left = create(data);
	}
	else{
		prv->right = create(data);
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

	//insertion
	insertion(root,1);
	insertion(root,2);
	insertion(root,55);

	//inorder traversal
	inorder(root);
	printf("\n");

	return 0;
}