/* K-Smallest elements using Max Heap */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void swap(int *num1 , int *num2);

int k = 10000;
int heap[100000],heapSize;

void init(){
	heapSize = 0;
	heap[0] = INT_MAX;
}

void deleteRoot(){
	//printf("Deleting root process started\n");
	int root = heap[1];
	//printf("Root now -->%d\n", root);
	heap[1] = heap[heapSize];
	//printf("Heap[heapsize] is now heap[1] -- >   %d\n",heap[heapSize]);
	int size = heapSize;
	size--;
	int parent = 1;
	int child = 2;

	while(child <= size){
		//printf("%d<--child   	%d<-- size\n" , child , size);
			if(heap[child] < heap[child + 1]){
				child++;
			}
			if (heap[child] > heap[parent])
			{
				swap(&heap[child] , &heap[parent]);
				parent = child;
				child = parent * 2;
			}else{
				//child = size;
				break;
			}
	}
}

void heapify(int element){
	int temp = heapSize;
			while(heap[temp/2] < element){
				heap[temp] = heap[temp/2];
				temp /= 2;
			}
	heap[temp] = element;
}

void insert(int element){
	//printf("Inside insert\n");
	if(heapSize < k){
		//printf("Inside if condition of insert\n");
		heapSize++;
		heap[heapSize] = element;	 	//insert in last node
		heapify(element);	
	}else if (element < heap[1]){
		//printf("Deleting because of %d\n", element);
		deleteRoot();						//top down heapifying by deleting max node 
		heap[heapSize] = element;
		heapify(element);
	}	
}

int main(int argc, char const *argv[])
{
	long int i,n;
	n = 1000000;
	int arr[n];
	
	for(i = 0; i < n; i++){
		arr[i] = rand() % 1000;
	}
	init();
	/*for (int i = 0; i < n; ++i)
	{	
			printf("%d\n",arr[i] );
	}*/
	
	//printf("Now Inserting\n");

	for (int i = 0; i < n; ++i)
	{	
			insert(arr[i]);
	}
	//printf("%d\n",heap[1] );
	for (int i = 1; i <= k; ++i)
	{	
			printf("%d\n",heap[i] );
	}
	return 0;
}

void swap(int *num1 ,int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
