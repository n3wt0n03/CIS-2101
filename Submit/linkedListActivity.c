#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} *LIST, lType;

void initialize(LIST *L)
{
	*L = NULL;
}

void displayList(LIST L)
{
	// Create a variable that will traverse the List
	LIST trav;
	for (trav = L; trav != NULL; trav = trav->next)
	{
		printf("%d -> ", trav->data);
	}
	printf("\n");
}

void insertFirst(LIST *L, int elem)
{
	LIST temp;
	temp = (LIST)malloc(sizeof(struct node));

	if (temp != NULL)
	{
		temp->data = elem;
		temp->next = *L;
		*L = temp;
	}
}

void insertLast(LIST *L, int elem)
{
	LIST temp, trav;
	temp = (LIST)malloc(sizeof(struct node));

	temp->data = elem;
	temp->next = NULL;

	// if list is empty, new node becomes the head
	if (*L == NULL)
	{
		*L = temp;
	}
	else
	{
		// else, traverse to the end and insert new node
		for (trav = *L; trav->next != NULL; trav = trav->next)
		{
		}
		trav->next = temp;
	}
}

void insertSorted(LIST *L, int elem)
{
	LIST temp, trav, previous;
	temp = (LIST)malloc(sizeof(struct node));

	temp->data = elem;
	temp->next = NULL;

	// Insertion in an empty list or at the beginning
	if (*L == NULL || elem < (*L)->data)
	{
		temp->next = *L;
		*L = temp;
		return;
	}

	previous = NULL; // is used to compare the current traversed node

	for (trav = *L; trav != NULL && elem > trav->data; previous = trav, trav = trav->next)
	{
	}

	// Insertion in the middle or at the end
	temp->next = trav;
	previous->next = temp;
}

LIST retrieve(LIST L, int position)
{
	LIST trav, previous;
	int count = 0; // the positioning is like an array that starts at 0
	previous = NULL;
	for (trav = L; trav != NULL && count != position; trav = trav->next)
	{
		previous = trav;
		count++;
	}

	LIST result = trav == NULL ? previous : trav;
	printf("Retrieved data from position %d: %d\n", position, result->data);
	return result;
}

LIST deleteNode(LIST *L, int elem)
{
	LIST trav, previous;
	previous = NULL;

	if (*L == NULL)
	{
		printf("The list is empty. There is nothing to delete\n");
		return *L;
	}

	for (trav = *L; trav != NULL && elem != trav->data; trav = trav->next)
	{
		previous = trav;
	}

	if (trav == NULL)
	{
		printf("Element %d not found in the list\n", elem);
		return *L; // Return the list unchanged
	}

	printf("Deleting the data %d:\n", elem);
	previous->next = trav->next;
	free(trav);
	displayList(*L);

	return *L;
}

void main()
{
	LIST head;
	initialize(&head);

	insertFirst(&head, 5);
	insertFirst(&head, 10);
	insertFirst(&head, 15);
	insertFirst(&head, 20);

	displayList(head);

	insertLast(&head, 25);

	displayList(head);

	insertSorted(&head, 23);

	displayList(head);

	retrieve(head, 3);

	deleteNode(&head, 26);
}