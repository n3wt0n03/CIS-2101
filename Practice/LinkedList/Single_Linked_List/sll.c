// All Function Prototypes will be added here
// All functions will be performed here
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

void initializeList(LISTPtr *L)
{
    *L = NULL;
}

LISTPtr initializeNode()
{
    LISTPtr newNode = (LISTPtr)malloc(sizeof(struct node));
    if (newNode != NULL)
    {
        return newNode; // successful
    }
    return NULL; // not successful
}

void displayList(LISTPtr L)
{
    if (L == NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        LISTPtr trav;
        for (trav = L; trav != NULL; trav = trav->next)
        {
            printf("%d -> ", trav->data);
        }
        printf("\n\n");
    }
}

void insertFirst(LISTPtr *L, int elem)
{
    LISTPtr temp = initializeNode();
    temp->data = elem;
    temp->next = *L; // make the value of next point to the current head
    *L = temp;       // update the head to the new node
}

void insertLast(LISTPtr *L, int elem)
{
    LISTPtr temp = initializeNode();

    temp->data = elem;
    temp->next = NULL;

    // if empty, then make it as the new head
    if (*L == NULL)
    {
        *L = temp;
    }
    else // traverse the whole list and if the next is EMPTY, point next to temp
    {
        LISTPtr trav;
        for (trav = *L; trav->next != NULL; trav = trav->next)
        {
        }
        trav->next = temp;
    }
}

// ASC: lowest < greatest
void insertSorted(LISTPtr *L, int elem)
{
    LISTPtr temp = initializeNode();

    temp->data = elem;
    temp->next = NULL;

    // if empty, then make it as the new head OR if elem < L->data
    if (*L == NULL || temp->data < (*L)->data)
    {
        temp->next = *L;
        *L = temp;
    }
    else // traverse the whole list and trav elem < temp elem
    {
        LISTPtr trav, previous;
        previous = NULL; // is used to compare the current traversed node
        for (trav = *L; trav != NULL && temp->data > trav->data; trav = trav->next)
        {
            previous = trav;
        }
        // Insertion
        temp->next = trav;
        previous->next = temp;
    }
}

LISTPtr retrieve(LISTPtr L, int position)
{
    LISTPtr trav, previous;
    previous = NULL;
    int count = 1; // we retrieve the data based on the number of loops

    for (trav = L; trav != NULL && count != position; trav = trav->next)
    {
        previous = trav;
        count++;
    }

    LISTPtr result = trav == NULL ? NULL : trav;
    printf("Retrieved data from position %d: %d\n", position, result->data);
    return result;
}

LISTPtr deleteNode(LISTPtr *L, int elem)
{
    LISTPtr trav, previous;
    previous = NULL;

    if (*L == NULL)
    {
        printf("The list is empty. There is nothing to delete\n");
        return *L;
    }

    // if the element to be deleted is in the first node
    if ((*L)->data == elem)
    {
        LISTPtr temp = *L;
        *L = (*L)->next; // becomes the new head
        free(temp);

        printf("Deleted the data %d\n", elem);
        displayList(*L);
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

    // Update the 'next' pointer of the previous node to bypass the target node
    previous->next = trav->next;
    free(trav);
    displayList(*L);

    return *L;
}
