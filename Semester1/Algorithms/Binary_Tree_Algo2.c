#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *right,*left;
}Node;

typedef struct queue
{
    int front,rear;
    int size;
    struct node** array;
}Queue;

Node* newNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> left = temp -> right = NULL;
    temp -> data = data;
    return temp;
}

Queue* newQueue(int size){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue -> front = queue -> rear = -1;
    queue -> size = size;

    queue -> array = (Node**)malloc(queue -> size * sizeof(Node));

    int i;
    for (int i = 0; i < size; ++i)
    {
        queue -> array[i] = NULL;
    }

    return queue;
}   

int isEmpty(Queue* queue){
    return queue -> front == -1;
}

int isFull(Queue* queue){
    return queue -> rear == 49;
}

void enqueue(Node* root , Queue* queue){
    if(isFull(queue))
        return;

    queue -> array[++queue -> rear] = root;

    if(isEmpty(queue)){
        ++queue -> front;
    }
}

Node* dequeue(Queue* queue){
    if(isEmpty(queue))
        return NULL;    

    Node* temp = queue -> array[queue -> front];

    if(queue -> front == queue -> rear)
        queue -> front = queue -> rear = -1;
    else
        ++queue -> front;

    return temp;
}

Node* getFront(Queue* queue){
    return queue -> array[queue -> front];
}

void insert(Node** root , Queue* queue , int data){
    Node* temp = newNode(data);

    if(!*root)
        *root = temp;
    else{
        Node* front = getFront(queue);

        if(!front -> left)
            front -> left = temp;
        else if(!front -> right){
            front -> right = temp;
            dequeue(queue);
        }
    }

    enqueue(temp , queue);
}

void inOrder(Node* root){
   if(root == NULL){
        return;
   }  

   inOrder(root -> left);

   printf("%d\n", root -> data);

   inOrder(root -> right);
}

int main(int argc, char const *argv[])
{
    Node* root = NULL;
    Queue* queue = newQueue(50);
    int i;
    for (int i = 0; i < 10; ++i)
    {
        insert(&root,queue,i);
    }

    inOrder(root);
    return 0;
}