/*
	Tree A:
		 12
	    /  \
	   9    15
	  / \
	 5  13
*/
/*
	Tree B:
		 12
	    /  \
	   9    15
	  / \
	 5  11

*/
//every node is visited exaclty one time, therfore
//time complexity is O(n)
#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int data;
	node* left;
	node* right;
};

int isBST(node* root, node* min, node* max){
	//min and max is the lower and upper limit of corresponding node
	if(root==NULL){//empty node is BST || base condition
		return 1;
	}
	if(min!=NULL && root->data<=min->data){
		//data of node must be greater than min
		return 0;
	}
	if(max!=NULL && root->data>=max->data){
		//data of node must be smaller than max
		return 0;
	}

	//checking if childrens are BST or not
	int isLeftBST = isBST(root->left,min,root);
	int isRightBST = isBST(root->right,root,max);

	return isLeftBST && isRightBST;
}

node* create(int data){
	node* new = (node*)malloc(sizeof(node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}
int main(){
	//Tree A:
	node* rootA = create(12);
	rootA->left = create(9);
	rootA->right = create(15);
	(rootA->left)->left = create(5);
	(rootA->left)->right = create(13);


	//Tree B:
	node* rootB = create(12);
	rootB->left = create(9);
	rootB->right = create(15);
	(rootB->left)->left = create(5);
	(rootB->left)->right = create(11);
	
	//checking Tree A is BST or not
	printf("%d\n",isBST(rootA,NULL,NULL));

	//checking Tree B is BST or not
	printf("%d\n",isBST(rootB,NULL,NULL));
	return 0;
}