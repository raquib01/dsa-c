#include<stdio.h>
#define SIZE 10
/*
	1. Time complexity:
		worst case: O(nlogn)
		best case: O(nlogn)
	2. Space complextity: O(n)
	3. Adaptive:
	4. Stable
	5. Resursive
*/
void merge(int* arr, int low, int mid, int high){
	int new[high+1];
	int i, j, k;
	i = low;
	j = mid+1;
	k = low;
	while(i<=mid && j<=high){
		if(arr[i]<=arr[j]){
			new[k] = arr[i];
			i++;
		}
		else{
			new[k] = arr[j];
			j++;
		}
		k++;

	}
	while(i<=mid){
		new[k] = arr[i];
		k++;
		i++;
	}
	while(j<=high){
		new[k] = arr[j];
		k++;
		j++;
	}
	for(int i = low; i<=high; i++){
		arr[i] = new[i];
	}
}
void mergeSort(int* arr, int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
int main(){
	int arr[SIZE] = {3,2,8,6,1,9,0,4,7,5};
	mergeSort(arr,0,9);
	for(int i = 0; i<SIZE; i++){
		printf("%d, ",arr[i]);
	}
	printf("\n");
	return 0;
}