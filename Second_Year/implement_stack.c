#include <stdio.h>
#include <stdlib.h>
int my_array[5];
int top = -1;

void push()
{
    int item_to_push;
    printf("To push: ");
    scanf("%i", &item_to_push);
    if (top >= 4)
    {
        printf("Stack already full\n");
    }
    else
    {
        top++;
        my_array[top] = item_to_push;
    }
}

void pop()
{
    int item_to_pop;
    printf("Poping\n");
    if (top == -1)
    {
        printf("Empty Stack\n");
    }
    else
    {
        top--;
    }
}

void peek()
{
    if (top != -1)
    {
        printf("%i\n", my_array[top]);
    }
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%i\n", my_array[i]);
    }
}

int main(void)
{
    printf("1.Push \n2.Pop \n3.Peek \n4.Display\n");
    int j = 0;
    while (j == 0)
    {
        int input;
        scanf("%i", &input);
        switch (input)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exit Succesful\n");
            j = 1;
            break;
        default:
            break;
        }
    }
    return 0;
}