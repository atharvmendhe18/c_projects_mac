#include <stdio.h>

int main()
{
    int a;
    int *b;
    long c;
    b = &a;

    printf("Value of b is %p and its size is %lu and size od long is %lu\n", b, sizeof(b), sizeof(c));

    return 0;
}