// https://www.youtube.com/watch?v=dn01XST9-bI
/* Circular Array Implementation of Queues */
#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    // If front == rear, Queue is full
    if (((rear + 1) % N) == front)
    {
        printf("Queue is Full!");
    }
    else
    {
        // Front and rear is pointing at -1 means the array is empty
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[rear] = x;
        }
        else
        {
            // Queue is not full and not empty
            rear = (rear + 1) % N;
            queue[rear] = x;
        }
    }
}

void dequeue()
{
    int temp;
    // if queue is empty, don't deqeueue
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        // if there is only one element left
        if (front == rear)
        {
            temp = front; // it only stores the index, not the value
            printf("The last element to dequeue: %d\n", queue[temp]);
            front = rear = -1;
        }
        else
        {
            temp = front;
            printf("Element to dequeue: %d\n", queue[temp]);
            front = (front + 1) % N;
        }
    }
}

void display()
{
    /* it still works but not efficient for you do not know your front value */
    // for (int i = 0; i <= rear; i++)
    // {
    //     printf("%d -> ", queue[i]);
    // }

    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty!\n");
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1) % N)
        {
            printf("%d -> ", queue[i]);
        }
        printf("%d\n", queue[rear]);

        // int i = front;
        // while (i != rear)
        // {
        //     printf("%d -> ", queue[i]);
        //     i = (i + 1) % N;
        // }
        // printf("%d\n", queue[rear]);
    }
}

void main()
{
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();

    dequeue();
    display();

    dequeue();
    display();

    dequeue();
    display();

    dequeue();
    display();

    dequeue();
    display();

    enqueue(15);
    display();

    enqueue(117);
    display();
}

/* Review the circular array format and code it again and visualize to understand fully */