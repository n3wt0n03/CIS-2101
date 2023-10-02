/* Array Implementation of Stack with struct containing the array and top (can use pointers) */
#include <stdio.h>
#include <stdlib.h>
#define MAX 6

// You cannot initialize inside a struct
// Initialization is done separately
typedef struct
{
    int stack_arr[MAX];
    int top;
} Stack;

void createStack(Stack *S)
{
    S->top = -1;
}

void displayArr(Stack *S)
{
    // print first the latest top up to the first top
    for (int i = S->top; i >= 0; i--)
    {
        printf("Top %d: %d\n", i, S->stack_arr[i]);
    }

    printf("\nCurrent value of Top: %d\n\n", S->top);
}

int isFull(Stack *S)
{
    int retVal = S->top >= MAX - 1 ? 1 : 0;
    return retVal;
}

int isEmpty(Stack *S)
{
    int retVal = S->top == -1 ? 1 : 0;
    return retVal;
}

void push(Stack *S, int data)
{
    if (isFull(S))
    {
        printf("\nCan't be pushed, stack will overflow\n");
        return;
    }
    S->top++;
    S->stack_arr[S->top] = data;
}

void pop(Stack *S)
{
    if (isEmpty(S))
    {
        printf("\nStack underflow. Generate a new stack.\n");
        return;
    }

    int temp;
    temp = S->stack_arr[S->top]; // store the last top value before decrementing

    S->stack_arr[S->top] = 0; // make the current top value to 0 before decrementing

    S->top--;
    S->stack_arr[S->top];
}

void main()
{
    Stack s1;
    createStack(&s1);

    printf("Adding elements unto an Array by Pushing\n");

    push(&s1, 1);
    push(&s1, 5);
    push(&s1, 3);
    push(&s1, 6);
    push(&s1, 10);
    push(&s1, 11);

    displayArr(&s1);

    push(&s1, 12); // Generates an overflow and can't be pushed
    displayArr(&s1);

    printf("Deleting Elements unto an Array by Popping\n");
    pop(&s1); // the value of top is being deleted and top is decremented

    displayArr(&s1);
}

/* Next target to be perfomed in stackArrayUpdated: Update the stackArray with struct and interactive terminal */