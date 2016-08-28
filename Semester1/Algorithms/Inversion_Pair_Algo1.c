/* Inversion Pair using Right side scanning for lower elements then current one and increasing the inversion count --> O(n^2) */

#include <stdio.h>

int count(int arr[] , int size){
	
	int count = 0;
	for(int i = 0 ; i < size - 1 ; i++)
		for(int j = i+1 ; j < size ; j++)
			if( arr[i] > arr [j] )
				count++;

	return count ;
}

int main(){
	int arr[] = {12 , 13 , 43 , 54 , 45 , -65 , -100};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("%d" , count(arr , n));
	return 0;
}
