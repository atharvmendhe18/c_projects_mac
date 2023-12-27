#include <stdio.h>

int main(void)
{
    int side;
    printf("Please enter the length of the side od the square ");
    scanf("%i", &side);
    printf("\n");

    for (int i = 0; i < side; i++)
    {
        if (i == 0 || i == (side - 1))
        {
            for (int j = 0; j < side; j++)
            {
                printf("*");
            }
        }
        else
        {
            printf("*");
            for (int j = 0; j < side - 2; j++)
            {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
}