#include <stdio.h>
#include <stdlib.h>
//insertLast and deleteFirst 

typedef struct node{
	int elem;
	struct node *next;
}*LIST, lType;

void initialize(LIST *h){
	*h = NULL;	
}

void displayList(LIST L){
	LIST trav;
	for(trav = L; trav != NULL; trav = trav->next){
		printf("%d -> ", trav->elem);
	}
}

int searchList(LIST L, int data){
	LIST trav;
	int retVal = -1;
	
//	for(trav = L; trav != NULL; trav = trav->next){
//		if(data == trav->elem){
//			printf(" 0");
//		} else {
//			printf(" -1");
//		}
//	} //print 0 if the data is there, else print -1

//	for(trav = L; trav != NULL; trav = trav->next){
//		if(trav->elem == data){
//			retVal = trav->elem;
//			printf("%d", retVal);
//			return retVal;
//		}
//	} //search if this way of returning is efficient

    for(trav = L; trav != NULL && trav->elem != data; trav = trav->next){}
    return trav != NULL ? trav->elem : -1;
}

void insertFirst(LIST *head, int data){
	LIST temp;
	temp = (LIST) malloc (sizeof(struct node)); //1
	if(temp !=  NULL){ //checking
		temp->elem = data; //2
		temp->next = *head; //3
		*head=temp; //4
	}
}

void main(){
	LIST head;
	initialize(&head);
	
	insertFirst(&head, 2);
	insertFirst(&head, 12);
	insertFirst(&head, 10);
	insertFirst(&head, 5);
	 
//	displayList(head);
	
	searchList(head, 10);
	
	int ret = searchList(head, 10);
	printf("%d", ret);
}

