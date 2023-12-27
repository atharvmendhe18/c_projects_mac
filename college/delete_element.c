// delete an element from an array

#include <stdio.h>

int main(void)
{
    int array[30], elements, posotion;

    printf("Please enter the no of elements in the array: ");
    scanf("%i", &elements);

    for (int i = 0; i < elements; i++)
    {
        printf("\nPlease enter element no %i: ", i + 1);
        scanf("%i", &array[i]);
    }
    printf("\nPlease enter the posotion of element you want to delete: ");
    scanf("%i", &posotion);
    if (posotion > elements)
    {
        printf("\nLocation dosnet exist");
        return 1;
    }

    for (int i = posotion - 1; i < elements; i++)
    {
        array[i] = array[i + 1];
    }
    elements--;
    printf("\n");
    for (int i = 0; i < elements; i++)
    {
        printf("%i ", array[i]);
    }
    return 0;
}