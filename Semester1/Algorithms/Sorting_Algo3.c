/* Sorting using Insertion sort worst = O(n^2) best = O(n) i.e. Sorted */

#include <stdio.h>

void sort(int arr[] , int n){
	int key;
	for(int i = 1; i < n ; i++){
		key = arr[i];
		j = i-1;

		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j] ;
			j = j-1;
		}
		
		arr[j+1] = key ;
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
