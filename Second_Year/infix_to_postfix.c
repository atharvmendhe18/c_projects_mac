#include <stdio.h>
#include <ctype.h>
#define SIZE 50
char stack[SIZE];
int top = -1;

void push(char val)
{
    if (top == SIZE - 1)
    {
        printf("\nStack overflow!\n");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

char pop()
{
    char x = -1;
    if (top == -1)
    {
        printf("\nStack underflow\n");
    }
    else
    {
        x = stack[top];
        top--;
    }
    return x;
}

char peek()
{
    int x = -1;
    if (top == -1)
    {
        printf("\nStack underflow\n");
    }
    else
    {
        x = stack[top];
    }
    return x;
}

void main()
{
    printf("1.Push \n2.Pop \n3.Peek \n4. Exit\n");
    int j = 0;
    while (j == 0)
    {
        int input;
        scanf("%i", &input);
        switch (input)
        {
        case 1:
            char item_to_push;
            printf("To push: ");
            scanf("%c", &item_to_push);
            push(item_to_push);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            printf("Exit Succesful\n");
            j = 1;
            break;
        default:
            break;
        }
    }
}
