#include <stdio.h>
#include <stdlib.h>

char my_stack[50];
char infix[50];
int top = -1;

void push(char to_push)
{
    my_stack[++top] = to_push;
}

char pop()
{
    return my_stack[top--];
}

char peek()
{
    return my_stack[top];
}

int main()
{
    int i = 0;
    char infix_i;
    int gadbad_hai_bc = 0;
    printf("Come on enter something dummy :) ");
    scanf("%s", &infix);
    while (infix[i] != '\0')
    {
        infix_i = infix[i];
        if (infix_i == '(' || infix_i == '[' || infix_i == '{')
        {
            push(infix_i);
            i++;
            continue;
        }
        else if (infix_i == ')' || infix_i == ']' || infix_i == '}')
        {
            char y = pop();
            if (y == ')' && infix_i != ')')
            {
                gadbad_hai_bc = 1;
            }
            else if (y == ']' && infix_i != '[')
            {
                gadbad_hai_bc = 1;
            }
            else if (y == '}' && infix_i != '{')
            {
                gadbad_hai_bc = 1;
            }
            i++;
        }
        i++;
    }

    if (top != -1 || gadbad_hai_bc == 1)
    {
        printf("BHAI kuch toh kaand kiya hai tune ek barr dekh le wapas\n");
    }
    else
    {
        printf("HEYYYYY atleast you did something right in your life!!!!");
    }
}
