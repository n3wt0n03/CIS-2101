// All Function Prototypes will be added here
// All functions will be performed here
#include <stdio.h>
#include <stdlib.h>
#include "arrayV2.h"

LIST initializeList()
{
    LIST list = (LIST)malloc(sizeof(struct list));
    list->count = 0;

    if (list != NULL)
    {
        printf("Initialized Successfully!");
        return list;
    }
    else
    {
        printf("Initialized Unsuccessful!");
    }

    return NULL;
}

void displayList(LIST list)
{
    for (int i = 0; i < list->count; i++)
    {
        printf("Index %d: %d\n", i, list->data[i]);
    }
    printf("Count: %d\n", list->count);
}

int insertList(LIST list, int pos, int data)
{
    if (data < 0 || pos < 0)
    {
        printf("\nInput only numbers greater than zero!\n");
        return 0;
    }

    if (list->count >= MAX)
    {
        printf("\nList is already full!\n");
        return 0;
    }

    if (pos <= list->count)
    {
        // shift elements to the right
        for (int i = list->count - 1; i >= pos; i--)
        {
            list->data[i + 1] = list->data[i];
        }
        list->data[pos] = data;
        list->count++;
        printf("Insertion Succesfull!\n");
        return 1;
    }
    else
    {
        printf("Position %d is not in range in the array!\n", pos);
    }

    printf("Insertion Unsuccessful!\n");
    return 0; // Not Success
}

int deleteList(LIST list, int pos)
{
    if (pos < 0)
    {
        printf("The inputted number must not be lesser than zero!\n");
        return 0;
    }

    if (list->count < 0)
    {
        printf("List is already empty!\n");
        return 0;
    }

    if (pos <= list->count)
    {
        // shift elements to the left
        for (int i = pos; i < list->count - 1; i++)
        {
            list->data[i] = list->data[i + 1];
        }

        list->count--;
        printf("Deletion Successful!\n", pos);
        return 1;
    }
    else
    {
        printf("Position %d is not in range in the array!\n", pos);
    }

    printf("Deletion Unsuccessful!\n", pos);
    return 0; // Not Success
}