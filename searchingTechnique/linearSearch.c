#include<stdio.h>
#define SIZE 10
int linearSearch(int* ptr, int data){
	for(int i = 0; i<SIZE; i++){
		if(ptr[i]==data){
			return i;
		}
	}
	return -1;
}
int main(){
	int arr[SIZE]={45,12,6,94,2,111,62,26,75,13};
	printf("[%d] position\n",linearSearch(arr,111));
	return  0;
}