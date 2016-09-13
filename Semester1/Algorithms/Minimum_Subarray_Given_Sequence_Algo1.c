/* Minimum subarray having given sequence ---> O(n) */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN( a, b ) ( ( a < b) ? a : b )


int minSlidingWindow(int arr[] , int n , int window );

typedef struct node{
		int data;
		struct node *next;   //self referential structure
		
} Node;

// ADDING in first position

void pushAtFirst(Node** head , int new_data , size_t data_size){ 	//size_t --> size of any object retured by sizeof operator --> to force no negative number i.e. unsigned int

	Node* new_node = (Node*)malloc(sizeof(Node));

	//new_node -> data = malloc(data_size);
	new_node -> next = (*head);

	new_node -> data = new_data ;

	(*head) = new_node ;

}

void pushAtLast(Node **node , int new_data , size_t data_size ,Node **last){

	
	Node* new_node = (Node*)malloc(sizeof(Node));

	//new_node -> data = malloc(data_size);
	new_node -> next = NULL;

	if((*node) == NULL){
		pushAtFirst(node , new_data , data_size);
		(*last) = (*node);
	}else{
		//printf("This %c\n", *(char *)(*last) -> data );
		(*last) -> next = new_node;
		new_node -> data = new_data;
		(*last) = new_node;

		//printf("This %c\n", *(char *)(*last) -> data );
	}
	
}

void deleteFirst(Node** head){
	if((*head) == NULL)
		return;
	else
		(*head) = (*head) -> next;
}

void deleteLast(Node** head , Node** last){
	if((*head) == NULL){
		printf("cannot Delete");
	}else if((*head) -> next == NULL){
		(*head) = NULL;
		
	}

	Node* cur = (*head);

	while(cur -> next -> next != NULL){
		cur = cur -> next;
	}
	
	(*last) = cur;

	cur -> next = NULL;

}
	
	

void printList(Node* node){
	while(node != NULL){
		printf("%d\n",node -> data );
		node = node -> next;
	}
}


int getLast(Node* last){
	return last -> data ;
}

int getFront(Node* head){
	return head -> data ;
}
void minimiseWindow(Node** head ,int arr[] , int count[] , int sequence){
	while((*head) != NULL){
		if(arr[getFront(*head)] <= sequence && count[arr[getFront(*head)]] > 1 ){
			//printf("hello\n");
			count[arr[getFront(*head)]]--;
			deleteFirst(head);
		}else if(arr[getFront(*head)] > sequence){
			deleteFirst(head);
		}else{
			break;
		}
	}
}
int minSlidingWindow(int arr[] , int n , int sequence){
	Node *head = NULL ;
	Node *last = NULL ;

	unsigned int_size = sizeof(int);
	head = NULL;
	
	int window = INT_MAX;
	int count[100] = {0};
	int unique = 0;
	int i , j;
	for(i = 0 ; i < n ; i++){
		if(unique == sequence)
			break;

		if(arr[i] <= sequence){
			if(count[arr[i]] == 0){
				unique++;
			}
			count[arr[i]]++;
		}
		pushAtLast(&head , i , int_size , &last);
		
	}
	window = MIN(window , getLast(last) - getFront(head) + 1);
	//printf("%d\n",window);
	//

	minimiseWindow(&head , arr , count , sequence);
	window = MIN(window , getLast(last) - getFront(head) + 1);
	//printf("%d\n", getLast(last) - getFront(head) + 1);
	for(j = i ; j < n ; j++){
		//printList(head);
		while(head != NULL && arr[j] == arr[getFront(head)]){
			deleteFirst(&head);
		}
		if(arr[j] <= sequence){
			count[arr[j]]++;
		}
		pushAtLast(&head , j , int_size , &last);
		minimiseWindow(&head , arr , count , sequence);
		//printList(head);
		
		//printf("%d\n", getLast(last) - getFront(head) + 1);
		//printList(head);
		//printf("%d\n",window);
		window = MIN(window , getLast(last) - getFront(head) + 1);
		//printf("%d\n", getLast(last) - getFront(head) + 1);
	}
		//printList(head);
	    return window;

}

int main(){
	int arr[] = {4, 5, 6, 7, 1, 2, 1 , 4, 5, 3, 6, 7, 10, 1, 2, 3, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 4 ;
	printf("%d",minSlidingWindow(arr , n , k));
	return 0;
}
