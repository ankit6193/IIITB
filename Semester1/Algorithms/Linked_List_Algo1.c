/* Generic Singly Linked List in c 
	Singly-Linked List -> Access->O(n) Search->O(n) Insertion->O(1) Deletion->O(1)	
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
		void *data;
		struct node *next;   //self referential structure
		
} Node;

// ADDING in first position

void pushAtFirst(Node** head , void *new_data , size_t data_size){ 	//size_t --> size of any object retured by sizeof operator --> to force no negative number i.e. unsigned int

	Node* new_node = (Node*)malloc(sizeof(Node));

	new_node -> data = malloc(data_size);
	new_node -> next = (*head);

	new_node -> data = new_data ;

	(*head) = new_node ;
}

void pushAtLast(Node *node , void *new_data , size_t data_size){

	Node* new_node = (Node*)malloc(sizeof(Node));

	new_node -> data = malloc(data_size);
	new_node -> next = NULL;



	while(node -> next != NULL){
		node = node -> next ;
	}
	

	node -> next = new_node;
	new_node -> data = new_data;

	//new_node -> next = NULL;

}

void pushAtMid(Node *node , void *new_data , size_t data_size , char d){
	Node* new_node = (Node *)malloc(sizeof(Node));

	new_node -> data = malloc(data_size);
	new_node -> next = NULL;
	//printf("Hello1\n");
	//printf("%c\n",d );
	while(*(char *)node -> data != d){
		node = node -> next;
	}

	new_node -> next = node -> next;
	node -> next = new_node;

	new_node -> data = new_data;
	//printf("Bye!!\n");
}

void delete(Node** head , char d){

	if((*head) == NULL){
		printf("cannot Delete");
	}else if(*(char *)(*head) -> data == d){
		(*head) = (*head) -> next;
		return;
	}

	Node* cur = (*head);
	Node* prev = NULL;

	while(cur != NULL && *(char *)cur -> data != d){
		prev = cur;
		cur = cur -> next;
	}

	if(cur == NULL)
		printf("Cannot Delete\n");

	prev -> next = cur -> next; 
}

void printList(Node* node , void (*fptr)(void *)){
	while(node != NULL){
		(*fptr)(node -> data) ;//xalling print function
		node = node -> next;
	}
}

void printInt(void *n){
	printf(" %d", *(int *)n );
}

void printChar(void *c){
	printf(" %c", *(char *) c );
}

int main(int argc, char const *argv[])
{
	Node *head = NULL ;

	unsigned char_size = sizeof(char);
	head = NULL;
	
	// Inserting in first
	char arr[] = {'a' , 'b' , 'c' , 'd' ,'e' , 'f'};
	for(int i = 5 ; i >= 0 ; i--)
		pushAtFirst(&head , &arr[i] , char_size);
	printList(head , printChar);


	printf("\n");

	//Inserting in last
	char arr2[] = {'g' , 'h'};
	for (int i = 0; i <= 1; i++)
		pushAtLast(head , &arr2[i] ,char_size);

	printList(head , printChar);

	printf("\n");

	//Inserting in Mid

	char arr3[] = {'1'} ;
	char d = 'c' ;

	pushAtMid(head , &arr3[0] , char_size , d);

	printList(head , printChar);

	printf("\n");

	//Deleting Node

	d = '1';

	delete(&head , d);

	printList(head , printChar);

	return 0;
}