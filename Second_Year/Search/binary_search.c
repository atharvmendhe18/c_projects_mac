#include <stdio.h>
#include <ctype.h>

int array[30];

int binary_search(int to_search)
{
    int high = -1;
    int low = 0;
    int mid;

    // find the length of the array
    int i = 0;
    while (array[i] != NULL)
    {
        i++;
    }
    high = i;
    mid = (high - low) / 2;
    // printf("high = %i, mid = %i\n", high, mid);

    while (array[mid] != to_search)
    {
        if (array[mid] > to_search)
        {
            high = mid;
            mid = (high + low) / 2;
        }
        else
        {
            low = mid;
            mid = (high + low) / 2;
        }
        if ((high - low) == 1 || (mid - low) == 1)
        {
            printf("Element not in the array\n");
            break;
        }
    }

    return mid;
}

int main(void)
{
    int no_of_elements;
    int to_insert;
    printf("Fibonacci Search\n");
    printf("Enter the no of elements in the array: ");
    scanf("%i", &no_of_elements);
    for (int i = 0; i < no_of_elements; i++)
    {
        scanf("%i", &to_insert);
        array[i] = to_insert;
    }
    printf("Element found = %i found at %i\n", array[binary_search(10)], binary_search(10));
    return 0;
}
