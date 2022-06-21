/*
pass: n-1
swap: n-1-i
+ Time Complexity:
	worst case: O(n^2)
	best case: O(n) if it is upgraded to adaptivity
+ Space Complexity:
	O(1) cos Inplace Sorting Algo
+ Adaptivity
	not adaptive by default, but can be upgraded to adaptive
	if not a single swap in a pass, then sorted
+ Stable: true
+ Non-recursive
*/
#include<stdio.h>
#define SIZE 10
void bubbleSort(int* arr){
	int temp;
	int flag;
	for(int i = 0; i<(SIZE-1); i++){//n-1 passes
		flag=0;
		for(int j = 0; j<(SIZE-1-i); j++){//n-1-i swaps
			if(arr[j]>arr[j+1]){//comparing adjacent elements
				flag=1;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if(flag==0){//if no swap in a pass, then it is sorted
			break;
		}
	}
}
int main(){
	int arr[SIZE] = {3,2,8,6,1,9,0,4,7,5};
	bubbleSort(arr);
	for(int i = 0; i<SIZE; i++){
		printf("%d, ",arr[i]);
	}
	printf("\n");
	return 0;
}