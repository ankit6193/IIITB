/* Algorithm with O(nlogn) + O(n) */

#include <stdio.h>

void quickSort(int arr[], int l , int r);
int partition(int arr[] , int l , int r);
int checkForElements(int arr[] , int n , int sum);
void swap(int *num1 , int *num2);

int main(){
	int arr[] = {12 , 13 , 43 , 54 , 45 , -65 , -100};
	int num = 25;
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr , 0 , n-1);
	//print(arr , n);
	if(checkForElements(arr , n , num) == 1)
		printf("Yes");
	else
		printf("No");

	return 0;
}	

int partition(int arr[] , int l , int r){
	int e = arr[r];				//pivot as right element
	int i = l - 1;				//scan
	int j ;					//swap
	
	for(j = l ; j < r ; j++){
		if( arr[j] <= e ){
			i++;
			swap(&arr[i],&arr[j]);		
		}
	}

	swap(&arr[i+1],&arr[r]);
	return i+1 ;
}

int checkForElements(int arr[] , int n , int sum){
	
	int l = 0;
	int r = n-1;

	while(l < r){
		if(arr[l] + arr[r] == sum)
			return 1;
		else if(arr[l] + arr[r] > sum)
			r--;
		else
			l++;
	}
	
	return 0;
}

void quickSort(int arr[] , int l , int r){
	int p;
	if(l < r){				//partition element
		p = partition(arr , l , r);
		quickSort(arr , l , p - 1);
		quickSort(arr , p + 1 , r);	
	}
}

void swap(int *num1 , int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
