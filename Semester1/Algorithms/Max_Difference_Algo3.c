#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX( a, b ) ( ( a > b) ? a : b )


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
int main(int argc, char const *argv[])
{
	int arr[] = { 1  , 55 , 203 , 3 , 405 , 550 , 100 , 600} ;
	int size = sizeof(arr) / sizeof(arr[0]);
	int window = 5;
	printf("%d",minSlidingWindow(arr , size , window));

	return 0;
}

int minSlidingWindow(int arr[] , int n , int window ){
	Node *head = NULL ;
	Node *last = NULL ;

	unsigned int_size = sizeof(int);
	head = NULL;
	
	int c_max = INT_MIN;

	for (int i = 0; i < window ; i++){
		while(head != NULL && arr[i] < arr[getLast(last)]){
			deleteLast(&head , &last);
		}
		pushAtLast(&head , i , int_size , &last);
		c_max = MAX(c_max , arr[i] - arr[getFront(head)]);
		//printf("%d\n",*(int *) (head) -> data );
	}
	//printList(head);

	for (int i = window; i < n; ++i)
	{
	    while(head != NULL && arr[i] < arr[getLast(last)]){
	    	deleteLast(&head , &last);
	    }
	    if(head != NULL && getFront(head) <= i - window)
	    	deleteFirst(&head);

	    pushAtLast(&head , i , int_size , &last);
	    c_max = MAX(c_max , arr[i] - arr[getFront(head)]);
	}

	//printList(head);
	return c_max;
}