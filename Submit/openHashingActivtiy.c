#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Structure to hold the key-value pairs (node)
typedef struct node
{
    int idNumber;
    int data;
    struct node *next;
} Node, *NodePtr;

// Structure of the dictionary
typedef struct
{
    NodePtr data[SIZE]; // An array of pointers to nodes
} Dictionary, *DictionaryPtr;

// Function to initialize the dictionary
void initDictionary(DictionaryPtr d)
{
    for (int i = 0; i < SIZE; i++)
    {
        d->data[i] = NULL;
    }
}

// function to initialize and create node
NodePtr createNode(int idNumber, int data)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->idNumber = idNumber;
        newNode->data = data;
        newNode->next = NULL;
    }
    else
    {
        printf("\nNode created unsuccessful!\n");
        return NULL;
    }

    return newNode;
}

// Hash function
int hash(int idNumber)
{
    if (idNumber < 0)
    {
        printf("\nInvalid ID Number!\n");
        return 0;
    }

    int sum = 0;
    while (idNumber > 0)
    {
        sum += idNumber % 10; // Extract and add the last digit
        idNumber /= 10;       // remove the last digit
    }
    return sum % SIZE;
}

// Function to search for a key and return its data
int search(DictionaryPtr d, int idNumber)
{
    int index = hash(idNumber);
    NodePtr current = d->data[index];
    for (NodePtr i = current; i != NULL; i = i->next)
    {
        if (i->idNumber == idNumber)
        {
            return i->data;
        }
    }
    return -1; // if not found
}

// Function to insert a key-value from the dictionary
void insert(DictionaryPtr d, int idNumber, int data)
{
    int index = hash(idNumber);
    NodePtr newNode = createNode(idNumber, data);

    newNode->next = d->data[index]; // insert at the beginning
    d->data[index] = newNode;       // points to the newly created node
}

// Function to delete a key-value from the dictionary
void delete(DictionaryPtr d, int idNumber)
{
    int index = hash(idNumber);
    NodePtr current = d->data[index];
    NodePtr previous = NULL;

    for (NodePtr i = current; i != NULL; i = i->next)
    {
        if (i->idNumber == idNumber)
        {
            if (previous == NULL)
            {
                d->data[index] = i->next;
            }
            else
            {
                previous->next = i->next;
            }
            free(i);
            return;
        }
        previous = i;
    }
}

// 1 - true, 2 - false, Function if key exists or not
int isMember(DictionaryPtr d, int idNumber)
{
    int index = hash(idNumber);
    NodePtr current = d->data[index];

    for (NodePtr i = current; i != NULL; i = i->next)
    {
        if (i->idNumber == idNumber)
        {
            printf("\n%d is a member of index %d\n", idNumber, index);
            return 1; // true
        }
    }
    printf("\n%d is not a member of index %d\n", idNumber, index);
    return 0; // false
}

int main()
{
    Dictionary d1;
    initDictionary(&d1);

    insert(&d1, 12345, 15);
    insert(&d1, 1234555, 16);
    insert(&d1, 2345, 22);
    insert(&d1, 67890, 20);
    insert(&d1, 12346, 11);

    delete (&d1, 12345);
    int deletedKey = search(&d1, 12345);
    printf("After deleting key 1234556: %d\n", deletedKey); // -1  meaning it is deleted

    isMember(&d1, 12345);
    isMember(&d1, 1234555);

    return 0;
}

// Ask sir about the other constraints