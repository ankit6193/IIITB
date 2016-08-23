/* Rank using random select method i.e. quick sort as whole to find the rank  average case O(n) ---> stop when pivot is the element --> partition using randomised pivot
--> http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-introduction-to-algorithms-sma-5503-fall-2005/video-lectures/lecture-6-order-statistics-median/
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int rank(int arr[] , int left , int right , int r);
int partition(int arr[] , int low , int high);
int randomP(int arr[] , int left , int rank);
void swap(int *num1 ,int *num2);

int main()
{
    int arr[] = {4, 3, 26, 122, 56, 202, 900};
    int n = sizeof(arr)/sizeof(arr[0]);
    //sort(arr , 0 , n-1 );
    int input;
    //printf("Sorted array: \n");
    //print(arr, n);
    scanf("%d" , &input);
    printf("%d", rank(arr,0,n-1,input));
    return 0;
}


int rank(int arr[] , int left , int right , int r){
	if(r > 0 && r <= right - left + 1){
		int index = randomP(arr , left , right);
		//printf("%d",index);
		if(index - left == r - 1)
			return arr[index];
		if(index - left > r - 1)
			return rank(arr, left , index-1 , r);  //discarding ranks greater then r 
		else
			return rank(arr, index + 1 , right ,r+left-index-1); //have to add ranks on left side
	}

	return INT_MAX ;
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
	swap( &arr[i+1], &arr[high]);
	return i+1 ;
}

int randomP(int arr[], int left , int rank){
	int n = rank - left + 1;  //numberof elements on left side of given partition
	int pivot = rand() % n;
	swap(&arr[left+pivot] , &arr[rank]);
	return partition(arr , left , rank);
}

void swap(int *num1 ,int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

