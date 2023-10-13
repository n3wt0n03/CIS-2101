// With header files, you can store all your function prototypes and struct here
#ifndef ARRAY_V2
#define ARRAY_V2
#define MAX 5

// LIST points to a "LIST"
typedef struct list
{
    int data[MAX];
    int count;
} *LIST;

LIST initializeList();
void displayList(LIST list);
int insertList(LIST list, int pos, int data);
int deleteList(LIST list, int pos);

// include all the functions here
#include "arrayV2.c"

#endif