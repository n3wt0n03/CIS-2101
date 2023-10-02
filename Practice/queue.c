//Single Linked-List Queue
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char elem;
	struct node *next;
}*nodePtr;

typedef struct{
	nodePtr front;
	nodePtr rear;
}Queue;

void initQueue (Queue *Q){
	Q->front = Q->rear = NULL;
}

nodePtr initNode(){
	nodePtr temp;
	temp = (nodePtr) malloc (sizeof(struct node)); 
	
	return temp;
}

void displayQueue(Queue Q){
	nodePtr trav;
	for(trav = Q.front; trav != NULL; trav = trav->next){
		printf("%c -> ", trav->elem);
	}
}

void enqueue(Queue *Q, char elem){
	nodePtr temp = initNode();
	
	if(temp != NULL){ // NOTE: Always create the node before enqueueing
		temp->elem = elem; 
		temp->next = NULL; 
	}

	if(Q->front == NULL){ // NOTE: Always point to temp, not next
		Q->front = temp;
		Q->rear = temp;
		printf("\nQueueing is done with front and rear in first node\n");
	} else { // NOTE: Always use rear when pointing node to new node
		Q->rear->next = temp;
		Q->rear = temp;
		printf("\nQueueing is done with front and rear in the next node\n");
	}
	
}

//create temp to store the value that will drop: temp = Q->front
//Q->front = Q->front->next
//if Q==NULL, Q->rear = NULL;

void dequeue(Queue *Q){
	nodePtr temp;
	
	if(Q->front != NULL){
		printf("Proceed to Dequeue\n");
		temp = Q->front;
		Q->front = Q->front->next;
	
		if (Q->front == NULL) {
			printf("No more to dequeue.");
			Q->rear = NULL;
		}		
		printf("\nElement to Dequeue: %c\n", temp->elem);
		free(temp);
		
	}	
}

void main(){
	Queue Q;
	initQueue(&Q);
	
	enqueue(&Q, 'm');
	displayQueue(Q);
	
	enqueue(&Q, 'c');
	displayQueue(Q);
	
	enqueue(&Q, 'd');
	
	displayQueue(Q);
	
	dequeue(&Q);
	displayQueue(Q);
	
	dequeue(&Q);
	displayQueue(Q);
	
	dequeue(&Q);
	
	displayQueue(Q);
}

//study Circular Array Implementation of Queues
