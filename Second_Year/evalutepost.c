#include <stdio.h>
#include <ctype.h>
#define SIZE 50
int stack[SIZE];
int top = -1;
char postfix[SIZE];

void push(int val)
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

int pop()
{
	int x = -1;
	if (top == -1)
	{
		printf("\nStack empty\n");
	}
	else
	{
		x = stack[top];
		top--;
	}
	return x;
}

int peek()
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

int main()
{
	int i = 0, op1, op2, result;
	int x;
	printf("Enter the postfix string: ");
	scanf("%s", postfix);
	while (postfix[i] != '\0')
	{
		x = postfix[i];
		if (isalnum(x))
		{
			push(x - '0');
		}

		else if (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
		{
			op2 = pop();
			op1 = pop();
			switch (x)
			{

			case '+':
				result = op1 + op2;
				break;

			case '-':
				result = op1 - op2;
				break;

			case '*':
				result = op1 * op2;
				break;

			case '/':
				result = op1 / op2;
				break;

			case '%':
				result = op1 % op2;
				break;
			}
			push(result);
		}
		i++;
	}
	printf("The result : %d", pop());
	return 0;
}
