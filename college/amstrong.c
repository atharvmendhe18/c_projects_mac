#include <stdio.h>

int raise_to_power(int power, int number);
int count_digits(int number);

int main(void)
{
    int input_no;
    int input_no_copy;
    int no_of_digits;
    int add = 0;
    printf("Please enter a no to check if it is an amstrong number: ");
    scanf("%i", &input_no);
    input_no_copy = input_no;
    printf("\n");

    no_of_digits = count_digits(input_no);
    while (input_no > 0)
    {
        int number = input_no % 10;
        add = add + raise_to_power(no_of_digits, number);
        input_no = input_no / 10;
    }

    if (input_no_copy == add)
    {
        printf("It is a amstrong number\n");
    }
    else
    {
        printf("No\n");
    }
}

int raise_to_power(int power, int number)
{
    int powered_number = 1;
    for (int i = 0; i < power; i++)
    {
        powered_number = powered_number * number;
    }
    return powered_number;
}

int count_digits(int number)
{
    int count = 0;
    while (number > 0)
    {
        number = number / 10;
        count++;
    }
    return count;
}
