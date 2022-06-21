#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int data;
	node* left;
	node* right;
	int height;
};

node* create(int data){
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	new->height = 0;
	return new;
}

void preorder(node* root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int getHeight(node* n){
	if(n==NULL){
		return -1;
	}
	return n->height;
}

int getBF(node* n){
	if(n==NULL){
		return 0;
	}
	return getHeight(n->left) - getHeight(n->right);
}

int max(node* x,node* y){
	return getHeight(x) > getHeight(y) ? getHeight(x) : getHeight(y);
}
	/*
	Left Rotate wrt x
	
		x		|		y
	   / \		|	  /  \
 	 t1   y		|	 x   t3
	     / \	|	/ \
       t2  t3	|  t1 t2

*/

node* leftRotate(node* x){
	node* y = x->right;
	node* t2 = y->left;

	//rewiring
	y->left = x;
	x->right = t2;

	//updating height
	x->height = max(x->left,x->right) + 1;
	y->height = max(y->left,y->right) + 1;

	return y; //returning new root node of given subtree
}
/*
	Right Rotate wrt y
	
		y		|		x
	  /  \		|	   / \
	 x   t3		| 	 t1   y
	/ \			|	     / \
   t1 t2		|       t2  t3

*/

node* rightRotate(node* y){
	node* x = y->left;
	node* t2 = x->right;

	//rewiring
	x->right = y;
	y->left = t2;

	//updating height
	x->height = max(x->left,x->right) + 1;
	y->height = max(y->left,y->right) + 1;

	return x; //returning new root node of given subtree
}

node* insertion(node* root, int data){
	if(root==NULL){
		return create(data);
	}
	if(root->data>data){
		root->left = insertion(root->left,data);
	}
	else if(root->data<data){
		root->right = insertion(root->right,data);
	}
	else{
		printf("Cant insert, Already Exist\n");
		return root;
	}

	//updating height of node
	//(this will be executed if insertion will be under this node)
	root->height = 1 + max(root->left,root->right);

	//getting balance factor
	int bf = getBF(root);

	//left left insertion case
	if(bf>1 && data < root->left->data){
		return rightRotate(root);
	}

	//right right insertion case
	if(bf<-1 && data > root->right->data){
		return leftRotate(root);
	}

	//left right insertion case
	if(bf>1 && data > root->left->data){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	//right left insertion case
	if(bf<-1 && data < root->right->data){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
int main(){
	node* root = NULL;
	root = insertion(root,10);
	root = insertion(root,20);
	root = insertion(root,30);
	root = insertion(root,40);
	root = insertion(root,50);
	root = insertion(root,60);
	
	preorder(root);
	return 0;
}