/* if size small merge sort more complex hence quick sort use*/
#include <stdio.h>

void swap(int *num1 , int *num2);
int partition(int arr[] ,int low ,int high);
void sort(int arr[] , int low , int high);

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
    sort(arr , 0 , n-1 );
    printf("Sorted array: \n");
    print(arr, n);
    return 0;
}

void sort(int arr[] , int low , int high){
	
	if(low < high){
		int p = partition(arr , low , high);
		sort(arr , low , p-1);
		sort(arr , p+1 , high);
	}

}

int partition(int arr[] , int low , int high){
	int pivot = arr[high] ;  // last element as pivot
	int i = low - 1 ; 	// before 1st element
	for(int j = low ; j < high ; j++){
		if(arr[j] <= pivot){
			i++;   //increment index and swap index and i
			swap(&arr[i],&arr[j]);		
		}	
	}
	swap(&arr[i+1],&arr[high]);
	return i+1 ;
}

void swap(int *num1 ,int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
