#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1
#define DELETED -99
#define SIZE 8

typedef struct
{
    int idNumber;
    char FN[20];
    char LN[20];
    char MI;
    int yearLevel;
} studType; // structure of studTypes

typedef studType Dictionary[SIZE]; // buckets for studTypes
int elemCount = 0;                 // tracks the num of elems in the dictionary

// initializing Dictionary - EMPTY = -1
void initDictionary(Dictionary d)
{
    if (d != NULL)
    {
        for (int i = 0; i < SIZE; i++)
        {
            d[i].idNumber = EMPTY;
        }
        printf("Initialized Successfully\n");
    }
    else
    {
        printf("Initialized Unsuccessful\n  ");
    }
}

// hash the idNumber
int hash(int idNumber)
{
    return idNumber % SIZE;
}

// check if there is already a value in that hash
int isMember(Dictionary d, int idNumber)
{
    int index = hash(idNumber);

    // Search the entire array before concluding
    for (int i = index; d[i].idNumber != EMPTY; i = (i + 1) % SIZE)
    {
        // If the idNumber in the bucket matches the given idNumber and it's not deleted
        if (d[i].idNumber == idNumber && d[i].idNumber != DELETED)
        {
            return 1; // Found
        }
    }
    return 0; // Not found
}

int insert(Dictionary d, studType std)
{
    if (elemCount >= SIZE)
    {
        printf("Dictionary is already full!\n");
        return 0; // Dictionary is already full
    }

    if (isMember(d, std.idNumber))
    {
        printf("Key value already exists in the bucket!\n");
        return 0; // Key already exists in that bucket
    }

    int index = hash(std.idNumber);

    for (int i = index; i != EMPTY; i = (i + 1) % SIZE)
    {
        if (d[i].idNumber == DELETED || d[i].idNumber == EMPTY)
        {
            d[i] = std;
            elemCount++;
            printf("Insert Successful!\n");
            return 1;
        }
    }

    printf("Insert Unsuccessful!\n");
    return 0;
}

void printDictionary(Dictionary d)
{
    printf("\nIndex \t | Hash Value \t| ID Number \t| First Name \t| Last Name \t| Middle Name \t| Year Level\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (d[i].idNumber != EMPTY && d[i].idNumber != DELETED)
        {
            int hashVal = hash(d[i].idNumber);
            printf(" %-7d | %-12d | %-13d | %-13s | %-13s | %-13c | %d\n", i, hashVal, d[i].idNumber, d[i].FN, d[i].LN, d[i].MI, d[i].yearLevel);
        }
    }
    printf("Number of elements present in the dictionary: %d\n", elemCount);
    printf("\n");
}

int main()
{
    Dictionary d;
    initDictionary(d);

    studType student1 = {12345, "John", "Doe", 'M', 1}; // Hash Value 1
    insert(d, student1);

    studType student2 = {67890, "Jane", "Smith", 'A', 2}; // Hash Value 2
    insert(d, student2);

    studType student3 = {123455, "Nicole", "Ochavo", 'B', 3}; // Hash Value 7
    insert(d, student3);

    printDictionary(d);

    // prints "true"
    if (isMember(d, 12345))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    // prints "false"
    if (isMember(d, 123456))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    studType student4 = {12345, "Sakura", "Miyawaki", 'S', 4}; // Hash Value 1
    insert(d, student4);                                       // this shouldn't be inserted because of same ID

    studType student5 = {12345321, "Eun-chae", "Hong", 'E', 1}; // Hash Value 1
    insert(d, student5);                                        // this should be inserted in the next available index

    printDictionary(d);

    // print students till it is full
    studType student6 = {63452, "Yun-jin", "Huh", 'Y', 3};     // hash Value 4
    studType student7 = {76598, "Kazuha", "Nakamura", 'K', 3}; // hash Value 6
    studType student8 = {897601, "Chae-won", "Kim", 'C', 2};   // hash Value 1
    studType student9 = {89760, "Newton", "Ochavo", 'B', 2};   // hash Value 0
    insert(d, student6);
    insert(d, student7);
    insert(d, student8);
    insert(d, student9);

    printDictionary(d);

    studType student10 = {89765, "Lily", "Morrow", 'J', 2}; // hash Value 5
    insert(d, student10);                                   // can't insert because array is full

    printDictionary(d);

    return 0;
}
