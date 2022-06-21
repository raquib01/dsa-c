/*
	1. Time complexity:
		worst case: O(n^2)
		best case: O(n^2)
	2. Space complexity
		O(1) cos Inplace sorting algo
	3. Non Adaptive
	4. Non Stable
	5. Non-resursive*/
#include<stdio.h>
#define SIZE 10

void selectionSort(int* arr){
	int minIndex, temp;
	for(int i = 0; i<SIZE-1; i++){
		minIndex = i;
		for(int j = i+1; j<SIZE; j++){//finding minimum
			if(arr[j]<arr[minIndex]){
				minIndex = j;
			}
		}
		if(minIndex!=i){//swapping 
			temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}
int main(){
	int arr[SIZE] = {3,2,8,6,1,9,0,4,7,5};
	selectionSort(arr);
	for(int i = 0; i<SIZE; i++){
		printf("%d, ",arr[i]);
	}
	printf("\n");
	return 0;
}