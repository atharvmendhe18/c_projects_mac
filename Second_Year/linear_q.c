#include <stdio.h>
#include <ctype.h>
#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int a)
{
    if (front == SIZE - 1)
    {
        printf("Not able to insert cuz...\n");
    }
    else
    {
        queue[front + 1] = a;
        front++;
    }
}

int dequeue()
{
    if (rear == SIZE - 1)
    {
        printf("....\n");
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
        int to_return = queue[rear + 1];
        rear++;
        printf("%i\n", to_return);
        return to_return;
    }
}

void display()
{
    for (int i = rear + 1; i <= front; i++)
    {
        printf("%i \n", queue[i]);
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
            dequeue();
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
