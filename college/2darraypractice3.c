#include <stdio.h>

void printUpperTriangularMatrix(int array[3][3]);

int main(void)
{
    int array[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%i", &array[i][j]);
        }
        printf("\n");
    }

    printUpperTriangularMatrix(array);
    return 0;
}

void printUpperTriangularMatrix(int array[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("  ");
        }
        for (int j = i + 1; j < 3; j++)
        {
            printf("%i", array[i][j]);
            printf("  ");
        }
        printf("\n");
    }
}