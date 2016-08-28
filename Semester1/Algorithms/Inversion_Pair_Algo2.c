/* Using merge sort O(nlogn) */

#include <stdio.h>

int mergeSort(int arr[] , int left , int right);
int merge(int arr[] , int left , int mid , int right);


int main(){
	int arr[] = {12 , 13 , 43 , 54 , 45 , -65 , -100};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("%d" , mergeSort(arr , 0 , n-1));
	return 0;
}

int mergeSort ( int arr[] , int left , int right ){
	int count = 0;
	if(left < right){
		
		int mid = (left + right) / 2 ;
		
		count = mergeSort(arr , left , mid);
		count += mergeSort(arr , mid+1 , right);
		count += merge(arr , left , mid , right);

	}
	return count;
}

int merge(int arr[] , int left , int mid , int right){
	
	int count = 0;
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
			count += mid - p ;		//if leftArr[i] > leftArr[j] --> Inversion will be all the elements in left array from i to leftSize
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
	return count ;
}
