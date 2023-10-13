// All Function Prototypes will be added here
// All functions will be performed here
#include <stdio.h>
#include "arrayV1.h"

void initializeList(LISTPtr list)
{
    list->count = 0;
}

void displayList(LIST list)
{
    int i;
    for (i = 0; i < list.count; i++)
    {
        printf("Index %d: %d\n", i, list.data[i]);
    }
    printf("Count: %d\n", list.count);
}

int insertList(LISTPtr list, int pos, int value)
{
    if (value < 0 || pos < 0)
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
        // shifting of elements to the right
        int i;
        for (i = list->count - 1; i >= pos; i--)
        {
            list->data[i + 1] = list->data[i];
        }
        list->data[pos] = value;
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

int deleteList(LISTPtr list, int pos)
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
        int i;
        for (i = pos; i < list->count - 1; i++)
        {
            list->data[i] = list->data[i + 1];
        }
        printf("Deletion Successful!\n", pos);
        list->count--;
        return 1; // Success
    }
    else
    {
        printf("Position %d is not in range in the array!\n", pos);
    }

    printf("Deletion Unsuccessful!\n", pos);
    return 0; // Not Success
}
