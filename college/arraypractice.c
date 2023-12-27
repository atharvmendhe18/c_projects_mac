// shift the elements in an one diomentional array inright directon

#include <stdio.h>

void shift_elements_right(int array1[5]);

int main(void)
{
    int my_array[5] = {1, 2, 3, 4, 5};
    shift_elements_right(my_array);
    for (int i = 0; i < 5; i++)
    {
        printf("%i", my_array[i]);
    }
}

void shift_elements_right(int array1[5])
{
    int last_element = array1[4];
    int temp2 = array1[0];
    for (int i = 0; i < 5; i++)
    {
        int temp1 = array1[i + 1];
        array1[i + 1] = temp2;
        temp2 = temp1;
    }
    array1[0] = last_element;
}