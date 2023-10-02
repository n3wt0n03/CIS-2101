// https://www.youtube.com/playlist?list=PLBlnK6fEyqRgWh1emltdMOz8O2m5X3YYn

/* Overall Static Array Implementation where it understands the basics of Stack */

#include <stdio.h>
#define MAX 6

int stack_arr[MAX]; // Best practice to declare it globally

// tracks the last inserted element
int top = -1; // put -1 as index to indicate stack is empty

void displayArr()
{
    // print first the latest top up to the first top
    for (int i = top; i >= 0; i--)
    {
        printf("Top %d: %d\n", i, stack_arr[i]);
    }

    printf("\nCurrent value of Top: %d\n\n", top);
}

// Make a separate function for checking errors
int isFull()
{
    int retVal = top >= MAX - 1 ? 1 : 0;
    return retVal;
}

int isEmpty()
{
    int retVal = top == -1 ? 1 : 0;

    return retVal;
}

void push(int data)
{
    if (isFull())
    {
        printf("\nCan't be pushed, stack will overflow\n");
        return;
    }
    ++top;
    stack_arr[top] = data;
}

void pop()
{
    if (isEmpty())
    {
        printf("\nStack underflow. Generate a new stack.\n");
        return;
    }

    int temp;
    temp = stack_arr[top]; // store the last top value before decrementing

    stack_arr[top] = 0; // make the current top value to 0 before decrementing

    --top;
    stack_arr[top];
}

void main()
{
    printf("Adding elements unto an Array by Pushing\n");
    push(1);
    push(5);
    push(3);
    push(6);
    push(10);
    push(11);

    displayArr();

    push(12); // Generates an overflow and can't be pushed
    displayArr();

    printf("Deleting Elements unto an Array by Popping\n");
    pop(); // the value of top is being deleted and top is decremented

    displayArr();
}

/* Next target to be perfomed in stackArrayTwo: Make a struct and initialize empty stack */