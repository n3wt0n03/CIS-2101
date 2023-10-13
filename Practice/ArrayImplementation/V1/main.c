#include <stdio.h>
#include "arrayV1.h"

void main()
{
    LIST listOne;
    initializeList(&listOne);

    insertList(&listOne, 0, 5);
    insertList(&listOne, 1, 7);
    insertList(&listOne, 2, 17);
    insertList(&listOne, 3, 15);

    displayList(listOne);

    printf("\nAfter inserting new elements:\n");
    insertList(&listOne, 1, 12);
    displayList(listOne);

    insertList(&listOne, 1, 13); // will prompt list is full

    printf("\nAfter deleting the value of the desired position:\n");
    deleteList(&listOne, 3);
    displayList(listOne);
}
