/* Minimum subarray having given sequence ---> O(n) */

#include <stdio.h>

int minSub(int arr[] , int n , int k){
	int count[100] = {0};
	int i, j;
	for(i = 0 ; i < n ; i++)
		if(arr[i] <= k)
			count[arr[i]]++;

	for(i = 0 ; i < n ; i++)
		if(arr[i] <= k && --count[arr[i]] == 0)
			break;

	for(j = n-1 ; j > 0 ; j--)
		if(arr[j] <= k && --count[arr[j]] == 0)
			break;

	return j-i+1 ; 
	
}

int main(){
	int arr[] = {1 , 2 , 10 , 6 , 3 , 1 , 2 , 7 , 6 , 4 , 2 , 8 , 6 , 7 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 4 ;
	printf("%d",minSub(arr , n , k));
	return 0;
}
