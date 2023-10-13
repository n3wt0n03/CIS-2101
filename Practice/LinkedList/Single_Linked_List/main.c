#include <stdio.h>
#include "sll.h"

void main()
{
    LISTPtr head;
    initializeList(&head);

    insertFirst(&head, 5);
    insertFirst(&head, 10);
    insertLast(&head, 15);
    insertLast(&head, 20);

    displayList(head);

    printf("\nFirst data: %d\n", head->data);

    insertSorted(&head, 11);

    displayList(head);

    retrieve(head, 3); // value of 11

    deleteNode(&head, 26); //Element not found

    deleteNode(&head, 10);
    
}
