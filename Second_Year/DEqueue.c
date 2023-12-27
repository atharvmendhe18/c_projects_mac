#include <stdio.h>
#include <ctype.h>

int queue[10];
int front = -1;
int rear = -1;

void enqueue(int var)
{
    if (rear == 9)
    {
        printf("Queue full");
    }

    else
    {
        rear++;
        queue[rear] = var;
    }
}

void enqueue_from_rear(int var)
{
    if (front == -1)
    {
        front++;
        rear++;
        queue[rear] = var;
    }

    else
    {
        queue[front] = var;
        front--;
    }
}

int deqeue()
{
    if (front == rear)
    {

        printf("Queue Empty");
        return 0;
    }
    else
    {
        int var = queue[front + 1];
        front++;
        printf("Dequed no = %i\n", var);
        return var;
    }
}

void dequeue_from_rear()
{
    if (front == rear)
    {

        printf("Queue Empty");
    }
    else
    {
        int var = queue[rear];
        rear--;
        printf("Dequed no = %i\n", var);
    }
}

void display()
{
    for (int i = rear; i > front; i--)
    {
        printf("%i", queue[i]);
    }
    printf("\n");
}

int main()
{
    printf("1. Input Restrected DEqueue\n 2. Output Restrected DEqueue\n");
    int j = 0;

    int input;
    scanf("%i", &input);
    if (input == 1)
    {
        while (j == 0)
        {
            printf("1.Enque\n 2. Deque from front\n 3.Deque from rear\n");
            int input_inr;
            scanf("%i", &input_inr);
            switch (input_inr)
            {
            case 1:
                printf("Enter item to enque: ");
                int var;
                scanf("%i", &var);
                enqueue(var);
                break;
            case 2:
                deqeue();
                break;
            case 3:
                dequeue_from_rear();
                break;
            case 4:
                display();
                break;
            }
        }
    }
    else
    {
        while (j == 0)
        {
            printf("1.Enque from front\n 2. Eneque from rear\n 3.Deque\n");
            int input_inr;
            scanf("%i", &input_inr);
            switch (input_inr)
            {
            case 1:
                printf("Enter item to enque: ");
                int var;
                scanf("%i", &var);
                enqueue(var);
                break;
            case 2:
                printf("Enter item to enque: ");
                int varr;
                scanf("%i", &varr);
                enqueue_from_rear(varr);
                break;
            case 3:
                deqeue();
                break;
            case 4:
                display();
                break;
            }
        }
    }
}