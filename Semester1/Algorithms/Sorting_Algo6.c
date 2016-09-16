/* Counting Sort O(n+k) --> time, O(n+k) --> space*/

#include <stdio.h>
#include <stdlib.h>

void countSort(int arr[] , int n){
	int count[100] = {0};
	int output[n];

	for (int i = 0; i < n; ++i)
	{
		count[arr[i]]++;
	}
	
	for (int i = 1; i < 100; ++i)
	{
		count[i] += count[i-1]; 
	}

	for (int i = 0; i < n; ++i)
	{
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}

	for(int i = 0 ; i < n ; i++){
		printf("%d\n",output[i]);
	}
}

int main(){
	int arr[] = {4, 3, 26, 4, 5, 3, 26};
    int n = sizeof(arr)/sizeof(arr[0]);
    countSort(arr , n);
    return 0;
}