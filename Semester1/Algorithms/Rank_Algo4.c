/* Rank using GOOD PIVOT to save space ---> only for 5 elements
--> http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-046j-introduction-to-algorithms-sma-5503-fall-2005/video-lectures/lecture-6-order-statistics-median/
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void merge ( int arr[] , int left , int mid , int right );
void mergeSort ( int arr[] , int left , int right );
int rank(int arr[] , int left , int right , int r);
int partition(int arr[] , int low , int high , int num);
//int randomP(int arr[] , int left , int rank);
void swap(int *num1 ,int *num2);
int findmedian(int arr[] , int n);

void print(int arr[], int size)
{
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {4, 3, 26, 122, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr , 0 , n-1);
    //printf("%d  llool",arr[2]);
    //getchar();
    int input;
    //printf("Sorted array: \n");
    print(arr, n);
    scanf("%d" , &input);
    printf("%d", rank(arr , 0 , n-1, input));
    return 0;
}


int rank(int arr[] , int left , int right , int r){
	if(r > 0 && r <= right - left + 1){
		int n = right - left + 1 ;  //number of elements
		int i , median[10000] ; //divide in group of 5 
		
		for(int i = 0 ; i < n/5 ; i++)
			median[i] = findmedian(arr+left+i*5 , 5);
		
		if(i*5 < n){
			median[i] = findmedian(arr+left+i*5 , n%5);
		i++;
		}  // for group not containing 5 members
		
		//recursive calls for median
		
		

		int medOfMed;
		if(i == 1)
			medOfMed = median[i-1];
		else
			medOfMed = rank(median , 0 , i-1 ,i/2);	
	
		
		int index = partition(arr , left , right , medOfMed);
		
		if(index - left == r - 1)
			return arr[index];
		if(index - left > r - 1)
			return rank(arr, left , index-1 , r);  //discarding ranks greater then r 
		else
			return rank(arr, index + 1 , right ,r+left-index-1); //have to add ranks on left side
	}

	return INT_MAX ;
}
//num is pivot for partition
int partition(int arr[] , int low , int high , int num){
	
	int i;
	for(int i = low ; i < high ; i++)
		if(arr[i] == num)
			break;
	swap(&arr[i] , &arr[high]);  //moving element to last 
	//int pivot = arr[high] ;  // last element as pivot
	i = low - 1 ; 	// before 1st element
	for(int j = low ; j < high ; j++){
		if(arr[j] <= num){
			i++;   //increment index and swap index and i
			swap(&arr[i],&arr[j]);		
		}	
	}
	swap(&arr[i+1], &arr[high]);
	return i+1 ;
}

void swap(int *num1 ,int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
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
void mergeSort ( int arr[] , int left , int right ){

	if(left < right){
		
		int mid = (left + right) / 2 ;
		//printf("%d" , mid);
		//getchar();
		mergeSort(arr , left , mid);
		mergeSort(arr , mid+1 , right);
		merge(arr , left , mid , right);

	}
}
int findmedian(int arr[] , int n){
	return arr[n/2];   //middle element
}
