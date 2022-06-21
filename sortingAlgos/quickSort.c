#include<stdio.h>
#define SIZE 10
int partition(int* arr, int low, int high){
	int pivot = arr[high];//setting high element as pivot
	int i = low-1;//starting i one prior to low
	int temp;
	for(int j = low; j<high; j++){
		//moving from low to (high-1), cos high is pivot
		if(arr[j]<pivot){//if it is less than pivot, swap with ith element
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

		}
	}
	//placing pivot at right place
	arr[high] = arr[i+1];
	arr[i+1] = pivot;
	return i+1;
}
void quickSort(int* arr, int low, int high){
	if(low<high){//until we have 2 elements in arr
		//partition arr into two part, having pivot at right place
		int pi = partition(arr,low,high);//index of pivot
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}

}

int main(){
	int arr[SIZE] = {3,2,8,6,1,9,0,4,7,5};
	quickSort(arr,0,9);
	for(int i = 0; i<SIZE; i++){
		printf("%d, ",arr[i]);
	}
	printf("\n");
	return 0;
}