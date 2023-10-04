#include <stdio.h>

typedef unsigned char SET;

// Initializes the SET to 0
SET initSet()
{
    return 0;
}

// Displays the SET
void displaySet(SET set)
{
    int numBits = sizeof(SET) * 8;

    printf("Set Elements: \n");
    for (int i = 0; i < numBits; i++)
    {
        if (set & (1 << i)) // Extract the i-th bit by shifting left
        {
            printf("1 -> 2^%d\n", i);
        }
        else
        {
            printf("0 -> 2^%d\n", i);
        }
    }

    printf("\nPrinting in Computer Word Representation: ");
    for (int i = 0; i < numBits; i++)
    {
        int bit = ((set >> i) & 1); // Extract the i-th bit by shifting right
        printf("%d", bit);
    }

    printf("\n\n");
}

// Function to insert an element into the set
SET insert(SET *set, int element)
{
    return *set | (1 << element);
}

// Function to check if an element is a member of the set
int member(SET set, int element)
{
    int isMember = (set & (1 << element)) != 0;
    if (isMember)
    {
        printf("%d is a member of the set.\n", element);
    }
    else
    {
        printf("%d is not a member of the set.\n", element);
    }
    return isMember;
}

// Function to delete an element from the set
SET delete(SET *set, int element)
{
    int wasDeleted = (*set & (1 << element)) != 0;
    if (wasDeleted)
    {
        printf("%d was deleted from the set.\n", element);
        *set &= ~(1 << element); // Clear the bit for the specified element
    }
    else
    {
        printf("%d was not found in the set and cannot be deleted.\n", element);
    }
    return *set; // return as a set so that it will be reflected automatically
}

// Function to compute the union of two sets
SET unionSet(SET set1, SET set2)
{
    return set1 | set2;
}

// Function to compute the intersection of two sets
SET intersection(SET set1, SET set2)
{
    return set1 & set2;
}

// Function to compute the set difference (set1 - set2)/ (set2 - set1)
SET difference(SET set1, SET set2)
{
    return set1 & ~set2;
}

void main()
{
    SET setA, setB;

    // Initialize sets
    setA = initSet();
    setB = initSet();

    // Insert elements into set A
    setA = insert(&setA, 7);
    setA = insert(&setA, 0);
    setA = insert(&setA, 4);
    setA = insert(&setA, 2);

    // Display sets
    printf("Set A: \n");
    displaySet(setA);

    // Insert elements into set B
    setB = insert(&setB, 1);
    setB = insert(&setB, 5);
    setB = insert(&setB, 3);
    setB = insert(&setB, 2);

    // Display sets
    printf("\nSet B: \n");
    displaySet(setB);

    // Perform set operations
    SET unionResult = unionSet(setA, setB);
    SET intersectionResult = intersection(setA, setB);
    SET differenceResult = difference(setA, setB);  // A - B = 4, 0 ,7
    SET differenceResult2 = difference(setB, setA); // B - A = 1, 3, 5

    printf("\nUnion: \n");
    displaySet(unionResult);

    printf("\nIntersection: \n");
    displaySet(intersectionResult);

    printf("\nDifference of A - B: \n");
    displaySet(differenceResult);

    printf("\nDifference of B - A: \n");
    displaySet(differenceResult2);

    // Check if it is there
    member(setA, 4);

    // check if it isn't there
    member(setA, 5);

    // Check if it is deleted
    delete (&setB, 5);

    // check if it isn't deleted
    delete (&setB, 4);

    // Display the set with the deleted value
    printf("\nSet B: \n");
    displaySet(setB);
}