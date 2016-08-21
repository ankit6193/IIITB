/* Sorting using Bubble sort O(n^2) */

#include <stdio.h>

void swap(int *num1,int *num2){
	int temp = *num1;
	int *num1 = *num2;
	int *num2 = temp;
}

void sort(int arr[] , int n){
	bool swapping;
	for(int i = 0; i<n-1 ; i++){
		swapping = false;
		for(int j = 0 ; j<n-1-i ; i++){
			if(arr[j] > arr[j+1]) {
				swap(&arr[j],&arr[j+1]);
				swapping = true;
			}
		}
		if(swapping == false)
			break;
	}
}
void print(int arr[], int size)
{
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int arr[] = {4, 3, 26, 122, 56, 202, 900};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
