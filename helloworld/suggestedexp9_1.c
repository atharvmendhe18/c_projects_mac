#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string alphabetsCap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int height = get_int("Height: ");

    for (int i = 0; i < height; i++)
    {
        for (int k = i; k < height; k++)
        {
            printf(" ");
        }

        for (int j = i; j >= 1; j--)
        {
            printf("%c", alphabetsCap[i - j]);
        }

        printf("%c", alphabetsCap[i]);

        for (int j = 1; j < i + 1; j++)
        {
            printf("%c", alphabetsCap[i - j]);
        }

        printf("\n");
    }
}