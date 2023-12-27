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

int deqeue()
{
    if (front == rear)
    {

        printf("Queue Empty");
        return 0;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
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

void display()
{

    for (int i = rear; i > front; i--)
    {
        printf("%i", queue[i]);
    }
}

int main()
{
    printf("1.Enque \n2.Deque \n3.Display \n4.Exit\n");
    int j = 0;
    while (j == 0)
    {
        int input;
        scanf("%i", &input);
        switch (input)
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
            display();
            break;

        case 4:
            printf("Exit Succesful\n");
            j = 1;
            break;
        default:
            break;
        }
    }
    return 0;
}