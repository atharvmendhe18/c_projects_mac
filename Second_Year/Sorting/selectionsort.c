#include <stdio.h>
#include <stdlib.h>

int myarray[10];

void selection_sort(int len_array) // will take user input on array length
{
    int temp;
    int sorted_till = 0;
    int min_no_index;
    int j;

    for (int i = sorted_till; i < len_array - 1; i++)
    {
        j = sorted_till;
        while (j < len_array)
        {
            if (myarray[j] < myarray[sorted_till])
            {
                min_no_index = j;
                temp = myarray[sorted_till];
                myarray[sorted_till] = myarray[min_no_index];
                myarray[min_no_index] = temp;
            }
            j++;
        }
        sorted_till++;
    }
}

void main()
{
    int array_lenght;
    printf("Enter the length of the array: ");
    scanf("%i", &array_lenght);
    printf("\nEnter the numbers in the array.");
    for (int i = 0; i < array_lenght; i++)
    {
        scanf("%i", &myarray[i]);
    }

    selection_sort(array_lenght);

    for (int i = 0; i < array_lenght; i++)
    {
        printf("%i\n", myarray[i]);
    }
}