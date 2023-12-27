#include <stdio.h>
#include <stdlib.h>

int partion(int A[], int low, int high);

void quick_sort(int A[], int low, int high)
{
    int partion_index;
    if (low < high)
    {
        partion_index = partion(A, low, high);
        quick_sort(A, low, partion_index - 1);
        quick_sort(A, partion_index + 1, high);
    }
}

int partion(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

int main()
{
    int A[] = {5, 1, 4, 9, 10, 7};
    int n = 6;
    for (int i = 0; i < n; i++)
    {
        printf("%i ", A[i]);
    }
    quick_sort(A, 0, n - 1);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", A[i]);
    }
    return 0;
}