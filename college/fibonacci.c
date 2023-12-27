#include <stdio.h>

int fibonacciSearch(int arr[], int n, int x)
{
    int fibm2 = 0;
    int fibm1 = 1;
    int fibm = fibm1 + fibm2;

    while (fibm < n)
    {
        fibm2 = fibm1;
        fibm1 = fibm;
        fibm = fibm1 + fibm2;
    }

    int offset = -1;

    while (fibm > 1)
    {
        int i = (offset + fibm2 < n) ? offset + fibm2 : n - 1;

        if (arr[i] < x) // shift by 1
        {
            fibm = fibm1;
            fibm1 = fibm2;
            fibm2 = fibm - fibm1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fibm = fibm2;
            fibm1 = fibm1 - fibm2;
            fibm2 = fibm - fibm1;
        }
        else
        {
            return i;
        }
    }

    if (arr[offset + 1] == x)
    {
        return offset + 1;
    }

    return -1;
}

int main()
{

    int arr[] = {10, 22, 32, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x, result;
    printf("\nFibonacci Search : \n");
    printf("Enter the element to search: ");
    scanf("%d", &x);

    result = fibonacciSearch(arr, n, x);

    if (result != -1)
    {
        printf("Element %d is present at index %d.\n", x, result);
    }
    else
    {
        printf("Element %d is not present in the array.\n", x);
    }
    return 0;
}