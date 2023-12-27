// add sum of list by passing an array to a function

#include <stdio.h>

int main(void)
{
}

void sum_of_elements(int my_array[30], int array_len)
{
    int sum = 0;
    for (int i = 0; i < array_len; i++)
    {
        sum = (sum + my_array[i]);
    }
}