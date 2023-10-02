#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/* List is a pointer to a structure with an array and count*/
typedef struct list
{
    int data[MAX];
    int count;
} *LIST;

LIST initializeList()
{
    LIST list = (LIST)malloc(sizeof(struct list));
    list->count = 0;
    return list;
}

void displayList(LIST list)
{
    for (int i = 0; i < list->count; i++)
    {
        printf("Index %d: %d\n", i, list->data[i]);
    }
    printf("\nCount: %d\n\n", list->count);
}

void insertList(LIST list, int pos, int data)
{
    if (data < 0 || pos < 0)
    {
        printf("\nInput only numbers greater than zero!\n");
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

void deleteList(LIST list, int pos)
{
    if (pos < 0)
    {
        printf("\nInput only numbers greater than zero!\n");
    }

    if (list->count < 0)
    {
        printf("\nList is already empty!\n");
    }

    // delete pos 2
    if (pos <= list->count)
    {
        for (int i = pos; i < list->count; i++)
        {
            list->data[i] = list->data[i + 1];
        }
        list->count--;
    }
    else
    {
        printf("\nPos not in range of the array!\n");
    }
}

void main()
{
    LIST listOne = initializeList();

    displayList(listOne);

    insertList(listOne, 0, 5);
    insertList(listOne, 1, 10);
    insertList(listOne, 2, 15);
    insertList(listOne, 3, 20);

    displayList(listOne);

    printf("\nAfter inserting new elements:\n");
    insertList(listOne, 0, 25);
    displayList(listOne);

    printf("\nAfter deleting the value of the desired position:\n");
    deleteList(listOne, 2);
    displayList(listOne);
}