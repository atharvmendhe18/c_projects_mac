#include <stdio.h>
#include <ctype.h>

int array[30];
int length_of_array;

void selection_sort()
{
    int test, j;
    for (int i = 1; i < length_of_array; i++)
    {
        test = array[i];
        j = i - 1;
        while (j >= 0 && test < array[j])
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = test;
    }
}

int main(void)
{
    int to_insert;
    printf("Quick Sort\n");
    printf("Enter the no of elements in the array: ");
    scanf("%i", &length_of_array);
    for (int i = 0; i < length_of_array; i++)
    {
        scanf("%i", &to_insert);
        array[i] = to_insert;
    }
    selection_sort();
    for (int i = 0; i < length_of_array; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
    return 0;
}
