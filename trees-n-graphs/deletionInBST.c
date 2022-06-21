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

node* isuccessor(node* root){//leftmost node of the right child
	while(root->left!=NULL){
		root = root->left;
	}
	return root;
}
node* deletion(node* root, int data){
	if(root==NULL){//base condition
		return root;
	}
	if(root->data>data){//if data is lessor,deletion in left tree
		root->left = deletion(root->left,data);
	}
	else if(root->data<data){//if data is bigger,deletion in right tree
		root->right = deletion(root->right,data);
	}
	else{//if this node to be deleted
		if(root->left==NULL){
			//if left is null, join the right child direcly to parent of this node
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			//if right is null, join the left child direcly to parent of this node
			node* temp = root->left;
			free(root);
			return temp;
		}
		else{//if node is somewhere in the middle
			node* isucc = isuccessor(root->right);//finding inorder successor
			//can also find inorder predessor
			root->data = isucc->data;
			//interchanging the data with isucc
			root->right = deletion(root->right,isucc->data);
			//deletion of isuccor 
		}
	}
	return root;
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

	//deletion
	deletion(root,8);

	//inorder traversal
	printf("Inorder Traversal:\n");
	inorder(root);
	printf("\n");
	return 0;
}