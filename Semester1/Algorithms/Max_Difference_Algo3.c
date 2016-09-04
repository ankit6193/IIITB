/* Maximum absolute difference with i<=j<=i+l   --> Keeping track of two elements --> Max difference and minimum element found so far --> O(n) */

#include <stdio.h>
#include <stdlib.h>

int maxDifference(int arr[] , int size , int l){
	int max = abs(arr[1] - arr[0]) ;
	int min = arr[0] ;
	int minIndex = 0;
	int maxIndex = 1;
	for(int i = 1 ; i < size ; i++){
	
		if(abs(arr[i] - min) > max){
			maxIndex = i;
			if((maxIndex - minIndex) <= l && minIndex <= maxIndex){
				printf("%d max\n",i);
				max = arr[i] - min ;
				
			}
		}

		if(arr[i] < min){
			printf("%d min\n",i);
			min = arr[i] ;
			minIndex = i ;
		}
		
	}
	return max;
}

int main(){
	
	int arr[] = { 2  , 3 , 10 , 15 , 4 , 8 , 15 , 35 , 12 , 55 , 203 , 223 , 450 , 550 , 100, 600} ;
	int size = sizeof(arr) / sizeof(arr[0]);
	int l = 5;
	printf("%d" , maxDifference(arr , size , l)) ;
}
