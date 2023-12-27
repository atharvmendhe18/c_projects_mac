#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int userNo = get_int("Number: ");
    for (int i = 1; i <= userNo; i++)
    {
        int count = i;
        for (int j = 1; j <= i; j++)
        {
            printf("%i ", count);
            count--;
        }
        printf("\n");
    }
}
