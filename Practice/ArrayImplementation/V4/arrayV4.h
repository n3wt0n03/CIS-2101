// With header files, you can store all your function prototypes and struct here
#ifndef ARRAY_V4
#define ARRAY_V4
#define MAX 5

// List is a pointer to a structure with a pointer to a dynamic array and count
typedef struct list
{
    int *data;
    int count;
} LIST, *ListPtr;

ListPtr initializeList(ListPtr *L); // Use malloc to dynamically initialize an array and list
void displayList(ListPtr list);
int insertList(ListPtr list, int pos, int data);
int deleteList(ListPtr list, int pos);

// include all the functions here
#include "arrayV4.c"

#endif