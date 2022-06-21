#include<stdio.h>
#define SIZE 10

int binarySearch(int* arr, int data){
	int low = 0;
	int high = SIZE-1;
	int mid;
	while(low<=high){//until we have a single element in our arr
		mid = (low+high)/2;
		if(data==arr[mid]){
			return mid;
		}
		if(data>arr[mid]){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return -1;
}
int main(){
	int arr[SIZE] = {12,23,36,45,68,72,80,99,106,112};
	printf("[%d] position\n",binarySearch(arr,112));
	return 0;
}