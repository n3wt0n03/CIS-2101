// With header files, you can store all your function prototypes and struct here
#ifndef ARRAY_V1
#define ARRAY_V1
#define MAX 5

// LIST is a structure
typedef struct
{
    int data[MAX];
    int count;
} LIST, *LISTPtr;

void initializeList(LISTPtr list);                // initializes the list
void displayList(LIST list);                      // displays all the lists
int insertList(LISTPtr list, int pos, int value); // inserts a value at a given pos
int deleteList(LISTPtr list, int pos);            // deletes a value from the given pos

//include all the functions here
#include "arrayV1.c"

#endif
