/* Sorting using Selection sort O(n^2) */

#include <stdio.h>

void swap(int *num1,int *num2){
	int temp = *num1;
	int *num1 = *num2;
	int *num2 = temp;
}

void sort(int arr[] , int n){
	int min = arr[0] ;   //Index of minimum number
	for(int i = 0; i < n-1 ; i++){
		for(int j = i+1 ; j < n ; i++){
			if(arr[j] < arr[min]) {
				min = j ;
			}
		}
		swap(&arr[min],&arr[i]);
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
