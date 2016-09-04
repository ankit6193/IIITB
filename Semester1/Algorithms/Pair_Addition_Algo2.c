/* Finding ABS max difference O(n) Method by using Hash Concept */

#include <stdio.h>

int main(){

	int arr[] = { 10 , 43 , 22 , 45 , 55 , -4 } ; //works for -ve number
	int hash[1000000] = {0} ;
	int sum = 32;
	int size = sizeof(arr) / sizeof(arr[0]) ;
	for(int i = 0 ; i < size ; i++)
	{
		hash[arr[i]] = i ;	//marking seen members and can be done after if loop of below for loop
	}
	for(int i = 0 ; i < size ; i++){
					
		if(arr[i] < sum){
			if(hash[sum - arr[i]] != 0){ 	//check if complement of number is seen or not , if seen it should not be equal to i
				printf("Pairs : %d and %d", sum-arr[i] , arr[i]); 
				break;
			}
		} 
	}
}
