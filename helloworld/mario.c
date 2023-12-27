#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h = get_int("Heigth: ");

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf(" ");
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        for (int j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}