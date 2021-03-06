/* Minimum Subarray containing sum greater then given ---> problem O(n) */

#include <stdio.h>
#define MAX( a, b ) ( ( a > b) ? a : b )

int minSub(int arr[] , int n , int sum){
	int currentSum = arr[0];
	int currentMax = arr[0];
	int start = 0 ,j ;
	for(int i = 1 ; i < n ; i++){
		currentSum = MAX(arr[i] , currentSum + arr[i]) ;
		currentMax = MAX(currentSum , currentMax) ;
		
		if(currentMax >= sum){
			for(j = 0 ; j <= i ; j++){
				if(sum < (currentMax-arr[j])){
					currentMax -= arr[j];
					//printf("%d --> currentMax , %d --> index \n",currentMax,j);
				}else
					break;		
			}		
			return i-j+1;
		}
	}

	return 0;
}

int main(){
	int arr[] = {1 , 2 , -6 , 45 , 0 , 119 , 345 , 560};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 905 ;
	printf("%d",minSub(arr,n,sum));
	return 0;
}
