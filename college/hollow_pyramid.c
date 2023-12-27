#include <stdio.h>

int main(void)
{
    int height;
    printf("Enter heigth of the pyramid: ");
    scanf("%i", &height);
    printf("\n");

    for (int i = 1; i <= height; i++)
    {
        for (int j = (height - i + 1); j > 0; j--)
        {
            printf(" ");
        }

        printf("*");

        for (int j = 2; j < (i * 2) - 1; j++)
        {
            printf(" ");
        }

        if (i != 1)
        {
            printf("*");
        }

        printf("\n");
    }
    for (int i = 1; i <= height + 1; i++)
    {
        printf("* ");
    }
}