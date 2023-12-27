#include <stdio.h>

int swap_by_refrence(int *a, int *b);

int main(void)
{
    int a = 3, b = 4;
    swap_by_refrence(&a, &b);
    printf("Values after swapping are a = %i and b = %i", a, b);
}

int swap_by_refrence(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}