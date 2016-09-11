/* K smallest number using randomised pivot */


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int rank(int arr[] , int left , int right , int r);
int partition(int arr[] , int low , int high);
int randomP(int arr[] , int left , int rank , int r);
void swap(int *num1 ,int *num2);

int main()
{
    int k;
    //j=k;
    scanf("%d" , &k);


    long int i,inputSize;
	inputSize = 10000000; // 10^10
	int input[2*k];
	for (int j = 0; j < k; ++j)
	{
		input[j] = rand() % 100000000 + 100;
	}
	//printf("%d\n", input[0]);
	for (int i = k ; i < inputSize;)
	{	//printf("hell\n");
		for(int j = k ; j < 2*k ; j++){
			input[j] = rand() % 100000000 + 100;	
		}
		printf("=====%d\n",i);
		rank(input, 0, 2*k - 1, k);
		i=i+k;
	}



	for(int j = 0 ; j < k ; j++){
		printf("%d\n",input[j]);
	}

    return 0;
}


int rank(int arr[] , int left , int right , int r){
	if(r > 0 && r <= right - left + 1){
		int index = randomP(arr , left , right , r);
		//printf("%d",index);


		if(index - left == r - 1){
			
			//exit(0);
			return 0;
		}
		if(index - left < r - 1){
			//printf("Hello\n");
			return rank(arr, left , index-1 , r);  //discarding ranks greater then r 
		}
		else{
			return rank(arr, index + 1 , right ,r+left-index-1); //have to add ranks on left side
		}

		
	}

	return INT_MAX ;
}

int partition(int arr[] , int low , int high){
	int pivot = arr[high] ;  // last element as pivot
	int i = low - 1 ; 	// before 1st element
	for(int j = low ; j < high ; j++){
		if(arr[j] <= pivot){
			i++;   //increment index and swap index and i
			swap(&arr[i],&arr[j]);		
		}	
	}
	swap( &arr[i+1], &arr[high]);
	return i+1 ;
}

int randomP(int arr[], int left , int rank , int r){
	int n = rank - left + 1;  //numberof elements on left side of given partition
	int pivot = rand() % n;
	if(pivot > r){
		swap(&arr[left+pivot] , &arr[rank]);
	}else{
		randomP(arr , left , rank , r);
	}
	
	return partition(arr , left , rank);
}

void swap(int *num1 ,int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}



