/* sorting using divide and conquer i.e. merge sort */git 

#include <stdio.h>

void merge ( int arr[] , int left , int mid , int right );

void mergeSort ( int arr[] , int left , int right );

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
    mergeSort(arr , 0 , n-1 );
    printf("Sorted array: \n");
    print(arr, n);
    return 0;
}


void mergeSort ( int arr[] , int left , int right ){

	if(left < right){
		
		int mid = (left + right) / 2 ;
		
		mergeSort(arr , left , mid);
		mergeSort(arr , mid+1 , right);
		merge(arr , left , mid , right);

	}
}

void merge(int arr[] , int left , int mid , int right){

	int leftSize = mid - left + 1;
	int rightSize = right - mid ;

	int leftArr[leftSize] , rightArr[rightSize] ;

	for(int i = 0 ; i < leftSize ; i++)
		leftArr[i] = arr[left + i] ;

	for(int i = 0 ; i < rightSize ; i++)
		rightArr[i] = arr[mid + 1 + i];

	int p = 0 , q = 0 , r = left ;	
	while( p < leftSize && q < rightSize){
		if (leftArr[p] <= rightArr[q]){
			arr[r] = leftArr[p] ;
			p++; 
		}else{
			arr[r] = rightArr[q] ;
			q++;	
		}
		r++;
	}

	while(p < leftSize)
	{
		arr[r] = leftArr[p];
		p++;
		r++;
	}
	while(q < rightSize)
	{
		arr[r] = rightArr[q];
		q++;
		r++;
	}
}
