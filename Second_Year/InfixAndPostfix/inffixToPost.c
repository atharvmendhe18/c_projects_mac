#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 50

char infix[SIZE];
char postfix[SIZE];
char my_stack[SIZE];
int front = -1;

// stack operations
void push(char to_push)
{
    my_stack[++front] = to_push;
}

char pop()
{
    char popped = my_stack[front--];
    return popped;
}

char top()
{
    return my_stack[front];
}

// end of stack operations

int get_priority(char in_sign)
{
    if (in_sign == '*' || in_sign == '/' || in_sign == '%')
    {
        return 2;
    }
    else if (in_sign == '+' || in_sign == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infix_to_postfix()
{
    printf("Started infix to post function\n");
    int i_infix = 0;
    int j_post = 0;
    char infix_char = infix[i_infix];

    while (infix_char != '\0')
    {
        printf("In the while loop\n");
        printf("Infix_char is %c\n", infix_char);
        // check if infix_char is a number or a operand
        if (isdigit(infix_char) == 1)
        {
            printf("Passed through the isdigit function\n");
            postfix[j_post++] = infix_char;
        }
        else if (infix_char == '(')
        {
            printf("Passed through the ( else if statement\n");
            push(infix_char);
        }
        else if (infix_char == ')')
        {
            printf("Passed through the ) else if statement\n");
            while (top() != '(')
            {
                postfix[j_post++] = pop();
            }
            pop();
        }
        else
        {
            printf("In the else condition\n");
            if (get_priority(infix_char) > get_priority(top()))
            {
                push(infix_char);
            }
            else if (get_priority(infix_char) < get_priority(top()) || get_priority(infix_char) == get_priority(top()))
            {
                while (get_priority(top()) >= get_priority(infix_char))
                {
                    postfix[j_post++] = pop();
                }
                push(infix_char);
            }
        }
        i_infix++;
        infix_char = infix[i_infix];
    }
    while (front != -1)
    {
        postfix[j_post++] = pop();
    }
}

void main()
{
    printf("Enter the infix string: ");
    scanf("%s", &infix);
    infix_to_postfix();
    printf("\n%s\n", postfix);
}