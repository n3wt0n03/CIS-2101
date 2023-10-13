// With header files, you can store all your function prototypes and struct here
#ifndef ARRAY_V3
#define ARRAY_V3
#define MAX 5

// List is a structure with a pointer to a dynamic array and count
typedef struct list
{
    int *data;
    int count;
} LIST, *ListPtr;

void initializeList(ListPtr list); // Use malloc to dynamically initialize an array
void displayList(LIST list);
int insertList(ListPtr list, int pos, int data);
int deleteList(ListPtr list, int pos);

// include all the functions here
#include "arrayV3.c"

#endif