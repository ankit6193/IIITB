/* O(n) Method by using Hash Concept */

#include <stdio.h>

int main(){

	int arr[] = { 10 , 43 , 22 , 45 , 55 , -4 } ; //works for -ve number
	int hash[1000000] = {0} ;
	int sum = 6;
	int size = sizeof(arr) / sizeof(arr[0]);
	for(int i = 0 ; i < size ; i++){
		hash[arr[i]] = 1 ;
		if(arr[i] < sum){
			if(hash[sum - arr[i]] != i){
				printf("Pairs : %d and %d", sum-arr[i] , arr[i]); 
				break;
			}
		} 
	}
}
