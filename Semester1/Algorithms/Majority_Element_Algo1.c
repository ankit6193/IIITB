/* Majority using Moore's Algorithm */

#include <stdio.h>

int majIndex(int arr[] , int n){
	int index = 0 , count = 1 ;
	for(int i = 1 ; i < n ; i++){
		if(arr[i] == arr[index])
			count++ ;
		else 
			count-- ;
		if(count == 0){
			count = 1;
			index = i;
		}
	} 
	
	return index;
}

int check(int arr[] , int n , int index){
	int count = 0;
	for(int i = 0 ; i < n ; i++){
		if(arr[i] == arr[index])
			count++;
	}
	if(count > n/3)
		return 0;
	else
		return -1;
}

int main(){
	int arr[] = {1 , 1 , 4 , 5 , 4 , 5 , 4 , 5 , 4 , 4 , 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int index = majIndex(arr,n);
	int j = check(arr, n , index);
	if(j == 0)
		printf("%d" , arr[index]);
	else
		printf("No Majority");
	return 0;
}
