/* K smallest number using Median of Median approach */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int rank(int arr[] , int left , int right , int r);
int partition(int arr[] , int left , int right , int medOfMed);
void swap(int *num1 ,int *num2);
int findmedian(int arr[] , int n);

int j;


void sort(int arr[] , int n){
	int key , j;
	for(int i = 1; i < n ; i++){
		key = arr[i];
		j = i-1;

		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j] ;
			j = j-1;
		}
			
		arr[j+1] = key ;
	}
}

int main()
{
    //int arr[] = {12, 3, 5, 7, 4, 19, 26};
    //int n = sizeof(arr)/sizeof(arr[0]);
    
    int k;
    //j=k;
    scanf("%d" , &k);


    long int i,inputSize;
	inputSize = 1000000; // 10^10
	int input[inputSize];
	for (int j = 0; j < k; ++j)
	{
		input[j] = rand() % 100000000+100;
	}
	//printf("%d\n", input[0]);
	for (int i = k ; i < inputSize;)
	{	//printf("hell\n");
		for(int j = k ; j < 2*k ; j++){
			input[j] = rand() % 100000000 + 100;	
		}
		//printf("=====%d\n",input[0]);
		rank(input , 0 , 2*k - 1 , k);
		i=i+k;
	}



	for(int j = 0 ; j < k ; j++){
		printf("%d\n",input[j]);
	}

    return 0;
}

int findmedian(int arr[] , int n){
	sort(arr , n);	
	return arr[n/2];   											//middle element
}
//int num = k + 1;
int rank(int arr[], int left , int right , int r){
	//printf("Here\n");
	if(r > 0 && r <= right - left + 1){
		int n = right - left + 1 ;  							//number of elements
		int i , median[(n + 4) / 5] ; 
		//divide in group of 5 
		for(i = 0 ; i < n/5 ; i++)
			median[i] = findmedian(arr+left+i*5 , 5);
		// for group not containing 5 members
		if(i*5 < n){
			median[i] = findmedian(arr+left+i*5 , n%5);
			i++;
		}  
		
		//recursive calls for finding median of median
		
		int medOfMed;
		
		if(i == 1)
			medOfMed = median[i-1];								//Only one element in the median so return last element of median array 
		else
			medOfMed = rank(median, 0, i - 1, i / 2); 			// why i/2 ???

		int position = partition(arr , left , right , medOfMed);	//partition around median of median
		
		if(position - left == r - 1)								//position same as rank
			return 0;
		if(position - left > r - 1)
			return rank(arr, left , position-1 , r);  					//discarding ranks greater then r 
		else
			return rank(arr, position + 1 , right ,r+left-position-1); 		//have to add ranks on left side
	}

	return INT_MAX ;
}

//search for median of median in array and partition around it 

int partition(int arr[] , int left , int right , int medOfMed){
	int i;
	for(i = left ; i < right ; i++)
		if(arr[i] == medOfMed)
			break;

	swap(&arr[i] , &arr[right]);

	//partition algorithm
	i = left - 1;
	for(int j = left ; j < right ; j++){
		if(arr[j] <= medOfMed){
			i++;
			swap(&arr[j] , &arr[i]);
			
		}
	}
	swap(&arr[i+1] , &arr[right]);
	return i + 1;
}


void swap(int *num1 ,int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
