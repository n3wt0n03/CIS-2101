// With header files, you can store all your function prototypes and struct here
#ifndef SLL
#define SLL

typedef struct node
{
    int data;
    struct node *next;
} LIST, *LISTPtr;

void initializeList(LISTPtr *L); // Initialize head to NULL
LISTPtr initializeNode();        // Initialize node
void displayList(LISTPtr L);
void insertFirst(LISTPtr *L, int elem);
void insertLast(LISTPtr *L, int elem);
void insertSorted(LISTPtr *L, int elem);
LISTPtr retrieve(LISTPtr L, int position);
LISTPtr deleteNode(LISTPtr *L, int elem);

// include all the functions here
#include "sll.c"

#endif