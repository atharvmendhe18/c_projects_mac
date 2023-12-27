#include <stdio.h>

int main(void)
{
    int num = 4;
    for (int i = 0; i < num; i++)
    {
        for (int j = num - 1; j > i; j--)
        {
            printf("[%i][%i]\n", i, j);
        }
    }
}
