#include <stdio.h>

int main(void)
{
    int mat1[3][3], mat2[3][3], rels[3][3];
    printf("Please enter matrix1\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%i", &mat1[i][j]);
        }
        printf("\n");
    }

    printf("Please enter matrix2\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%i", &mat2[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            rels[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                rels[i][j] = rels[i][j] + (mat1[i][k] * mat2[k][j]);
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i  ", rels[i][j]);
        }
        printf("\n");
    }
}
