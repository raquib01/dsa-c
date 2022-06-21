/*
	1. Time complexity:
		worst case: O(n^2)
		best case: O(n)
	2. Space complexity
		O(1) cos Inplace sorting algo
	3. Adaptive
	4. Stable
	5. Non-resursive
*/
#include<stdio.h>
#define SIZE 10

void insertionSort(int* arr){
	int key;
	for(int i = 1; i<SIZE; i++){
		key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>key){//shifting greater elements
			arr[j+1] = arr[j]; 
			j--;
		}
		arr[j+1] = key;//putting key at the righ place

	}

}
int main(){
	int arr[SIZE] = {3,2,8,6,1,9,0,4,7,5};
	insertionSort(arr);
	for(int i = 0; i<SIZE; i++){
		printf("%d, ",arr[i]);
	}
	printf("\n");
	return 0;
}