/* Maximum Subarray problem O(n) */

#include <stdio.h>
#define MAX( a, b ) ( ( a > b) ? a : b )

int maxSum(int arr[] , int n){
	int currentSum = arr[0];
	int currentMax = arr[0];

	for(int i = 1 ; i < n ; i++){
		currentSum = MAX(arr[i] , currentSum + arr[i]) ;
		currentMax = MAX(currentSum , currentMax) ;
	}

	return currentMax;
}

int main(){
	int arr[] = {-1 , -2 , -2 , -3 , -4 , -5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("%d",maxSum(arr,n));
	return 0;
}
