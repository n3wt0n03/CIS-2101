#include <stdio.h>
#define MAX 5

typedef struct
{
    int data[MAX];
    int count;
} LIST;

void initializeList(LIST *list)
{
    list->count = 0;
}

void displayList(LIST *list)
{
    for (int i = 0; i < list->count; i++)
    {
        printf("Index %d: %d\n", i, list->data[i]);
    }
    printf("\nCount: %d\n", list->count);
}

void insertList(LIST *list, int pos, int value)
{
    if (value < 0 || pos < 0)
    {
        printf("\nInput only numbers greater than zero!\n");
    }

    if (list->count >= MAX)
    {
        printf("List is already full!\n");
    }

    if (pos <= list->count)
    {
        for (int i = list->count - 1; i >= pos; i--)
        {
            list->data[i + 1] = list->data[i];
        }
        list->data[pos] = value;
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
        printf("\nInput only numbers greater than zero!\n");
    }

    if (list->count < 0)
    {
        printf("\nList is already empty!\n");
    }

    // delete pos 3
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
    LIST listOne;
    initializeList(&listOne);

    insertList(&listOne, 0, 5);
    insertList(&listOne, 1, 7);
    insertList(&listOne, 2, 17);
    insertList(&listOne, 3, 15);

    displayList(&listOne);

    printf("\nAfter inserting new elements:\n");
    insertList(&listOne, 1, 12);
    displayList(&listOne);

    printf("\nAfter deleting the value of the desired position:\n");
    deleteList(&listOne, 3);
    displayList(&listOne);
}