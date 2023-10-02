#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/* List is a structure with a pointer to a dynamic array and count*/
typedef struct list
{
    int *data;
    int count;
} LIST, *ListPtr;

/* Use malloc to dynamically initialize an array*/
void initializeList(LIST *list)
{
    list->data = (int *)malloc(sizeof(int) * MAX);
    list->count = 0;
}

void displayList(LIST list)
{
    for (int i = 0; i < list.count; i++)
    {
        printf("Index %d: %d\n", i, list.data[i]);
    }
    printf("\nCount: %d\n\n", list.count);
}

void insertList(LIST *list, int pos, int data)
{
    if (pos < 0 || data < 0)
    {
        printf("\nInputted numbers must be greater than zero!\n");
    }

    if (list->count >= MAX)
    {
        printf("\nList is already full!\n");
    }

    if (pos <= list->count)
    {
        for (int i = list->count; i > pos; i--)
        {
            list->data[i] = list->data[i - 1];
        }
        list->data[pos] = data;
        list->count++;
    }
    else
    {
        printf("\nPos not in range of the array!\n");
    }
}

void deleteList(LIST *list, int pos)
{
    if (pos < 0)
    {
        printf("\nInputted numbers must be greater than zero!\n");
    }

    if (list->count < 0)
    {
        printf("\nList is already empty!\n");
    }

    // delete pos 2
    if (pos <= list->count)
    {
        for (int i = pos; i <= list->count; i++)
        {
            list->data[i] = list->data[i + 1];
        }
        list->count--;
    }
}

void main()
{
    LIST listOne;
    initializeList(&listOne);

    insertList(&listOne, 0, 5);
    insertList(&listOne, 1, 10);
    insertList(&listOne, 2, 15);
    insertList(&listOne, 3, 20);

    displayList(listOne);

    printf("\nAfter inserting new elements:\n");
    insertList(&listOne, 0, 25);
    displayList(listOne);

    printf("\nAfter deleting the value of the desired position:\n");
    deleteList(&listOne, 2);
    displayList(listOne);
}
