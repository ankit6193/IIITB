/* Maximum Subarray problem O(n) with atLEAST length L */

#include <stdio.h>
#define MAX( a, b ) ( ( a > b) ? a : b )

int maxSum(int arr[] , int n , int l){
	int j = 0;
	
	int currentSum = arr[0];
	int currentMax = arr[0];

	for(int i = 1 ; i < n ; i++){
		currentSum = MAX(arr[i] , currentSum + arr[i]) ;

		if(currentMax < MAX(currentSum , currentMax)){
				
				j = i - j;
				//printf("%d Index\n",j);

				if(j >= l)
					currentMax = MAX(currentSum , currentMax) ;
		}
	}

	return currentMax;
}

int main(){
	int arr[] = {-2 , -3 , 4 , -1 , -2 , 1 , 5, -3 };
	int l = 5 ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	printf("%d",maxSum(arr,n,l)) ;
	return 0;
}
