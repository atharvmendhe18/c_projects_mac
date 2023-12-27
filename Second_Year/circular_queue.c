#include <stdio.h>
#include <stdlib.h>

int SIZE = 5;

int queue[5];
int front = -1;
int rear = -1;

int is_empty();

int is_full()
{
    if ((rear + 1) % SIZE == front)
    {
        return 1;
    }
    else if (front == -1 && (rear + 1) % SIZE == 0 && is_empty() == 0)
    {
        return 1;
    }
    return 0;
}

int is_empty()
{
    if (front == rear)
    {
        return 1;
    }
    return 0;
}
void enqueue(int to_enqueue)
{
    if (is_full() == 1)
    {
        printf("fornt = %i rear = %i\n", front, rear);
        printf("Queue is Full\n");
    }
    else
    {

        rear = (rear + 1) % SIZE;
        printf("fornt = %i rear = %i\n", front, rear);
        queue[rear] = to_enqueue;
    }
}

void dequeue()
{
    if (is_empty() == 1)
    {
        printf("fornt = %i rear = %i\n", front, rear);
        printf("Queue is Empty\n");
    }
    else
    {
        front = (front + 1) % SIZE;
        printf("fornt = %i rear = %i\n", front, rear);
    }
}

int display()
{
    int i = front;
    if (is_empty() == 1)
    {
        printf("Queue Empty");
        return 1;
    }
    while (i != rear)
    {
        printf("%i\n", queue[i + 1]);
        i = (i + 1) % SIZE;
    }
    return 0;
}

int main()
{
    int user_in;
    int to_enqueue;
    int j = 0;
    printf("\n\nWelcome to the absurdity called Circular Queue using Array :)\n");
    printf("Please Select one of the following options though all of them might not have been implemented\n\n");
    while (j == 0)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Dispaly\n");
        scanf("%i", &user_in);
        switch (user_in)
        {
        case 1:
            printf("Please enter the number to enqueue: ");
            scanf("%i", &to_enqueue);
            enqueue(to_enqueue);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
        }
    }
}