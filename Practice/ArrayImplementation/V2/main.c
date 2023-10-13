#include <stdio.h>
#include "arrayV2.h"

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

    insertList(listOne, 0, 25); // will prompt list is full

    printf("\nAfter deleting the value of the desired position:\n");
    deleteList(listOne, 2);
    displayList(listOne);
}