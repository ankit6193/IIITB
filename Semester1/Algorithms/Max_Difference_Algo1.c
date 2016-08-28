/* Maximum absolute difference --> Keeping track of two elements --> Max difference and minimum element  found so far --> O(n) */

#include <stdio.h>
#include <stdlib.h>

int maxDifference(int arr[] , int size){
	int max = abs(arr[1] - arr[0]) ;
	int min = arr[0] ;
	for(int i = 1 ; i < size ; i++){
		if(abs(arr[i] - min) > max)
			max = arr[i] - min ;
		if(arr[i] < min)
			min = arr[i] ;	
	}
	return max ;
}

int main(){
	
	int arr[] = { 10 , 43 , 22 , 45 , 55 , -4 } ;
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("%d" , maxDifference(arr , size)) ;
}
