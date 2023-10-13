// All Function Prototypes will be added here
// All functions will be performed here
#include <stdio.h>
#include <stdlib.h>
#include "arrayV3.h"

void initializeList(ListPtr list)
{
    list->data = (int *)malloc(sizeof(int) * MAX); // dynamic array initialization
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

int insertList(ListPtr list, int pos, int data)
{
    if (data < 0 || pos < 0)
    {
        printf("The inputted number must not be lesser than zero!\n");
        return 0;
    }

    if (list->count >= MAX)
    {
        printf("List is already full!\n");
        return 0;
    }

    if (pos <= list->count)
    {
        // shift to the right
        for (int i = list->count - 1; i >= pos; i--)
        {
            list->data[i + 1] = list->data[i];
        }

        list->data[pos] = data;
        list->count++;
        printf("Insertion Successful!\n", pos);
        return 1; // Success
    }
    else
    {
        printf("Position %d is not in range in the array!\n", pos);
    }

    printf("Insertion Unsuccessful!\n");
    return 0; // Not Success
}

int deleteList(ListPtr list, int pos)
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
        // shift to the left
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