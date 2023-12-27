#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 50
char str[50];
char revstr[50];
char infix[SIZE];
char postfix[SIZE];
char prefix[SIZE];
char my_stack[50];
int front = -1;

void push(char to_push)
{
    my_stack[++front] = to_push;
}

char pop()
{
    char popped = my_stack[front--];
    return popped;
}

char peek()
{
    return my_stack[front];
}

void strrev()
{
    int i = 0;
    while (str[i] != '\0')
    {
        push(str[i++]);
    }

    i = 0;
    while (front != -1)
    {
        revstr[i++] = pop();
    }
}

void strrev_post()
{
    int i = 0;
    while (postfix[i] != '\0')
    {
        push(postfix[i++]);
    }

    i = 0;
    while (front != -1)
    {
        prefix[i++] = pop();
    }
}

void invert_brackets()
{
    int i = 0;
    while (revstr[i] != '\0')
    {
        if (revstr[i] == '(')
        {
            revstr[i] = ')';
            i++;
            continue;
        }
        else if (revstr[i] == ')')
        {
            revstr[i] = '(';
            i++;
            continue;
        }
        i++;
    }
}

int get_priority(char sign)
{
    if (sign == '/' || sign == '*' || sign == '%')
    {
        return 3;
    }
    else if (sign == '-' || sign == '+')
    {
        return 2;
    }
    return 0;
}

void infix_to_post()
{
    int i_infix = 0;
    int j_post = 0;
    char infix_char = infix[i_infix];
    while (infix_char != '\0')
    {
        if (isdigit(infix_char) == 1)
        {
            postfix[j_post++] = infix_char;
        }
        else
        {
            if (front == -1)
            {
                push(infix_char);
            }
            else
            {
                int priority = get_priority(infix_char);
                if (infix_char == '(')
                {
                    push(infix_char);
                }
                else if (priority < get_priority(peek() && priority != 0))
                {
                    while (front != -1)
                    {
                        char to_push = pop();
                        if (to_push != '(' && to_push != ')')
                        {
                            postfix[j_post++] = to_push;
                        }
                    }
                    push(infix_char);
                }
                else if (infix_char == ')')
                {
                    while (front != -1 && peek() == '(')
                    {
                        char to_push = pop();
                        if (to_push != '(' && to_push != ')')
                        {
                            postfix[j_post++] = to_push;
                        }
                    }
                }
                else if (priority >= get_priority(peek()))
                {
                    push(infix_char);
                }
            }
        }
        infix_char = infix[++i_infix];
    }
    while (front != -1)
    {
        char to_push = pop();
        if (to_push != '(' && to_push != ')')
        {
            postfix[j_post++] = to_push;
        }
    }
}
int main()
{
    printf("Enter the str to rev: ");
    scanf("%s", &str);
    strrev();
    invert_brackets();
    for (int i = 0; revstr[i] != '\0'; i++)
    {
        infix[i] = revstr[i];
    }
    infix_to_post();
    strrev_post();
    printf("%s\n", prefix);
}