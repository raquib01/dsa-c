/*
	root
	/  \
   p1  p2
  / \  / \
  N N  N N
  
*/
#include<stdio.h>
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
int main(){
	//creating node
	node* root = create(5);
	node* p1 = create(3);
	node* p2 = create(8);

	//linking
	root->left = p1;
	root->right = p2;
	
	return 0;
}