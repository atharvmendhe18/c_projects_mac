#include <stdio.h>

int main(void)
{
    int year;
    printf("Please enter a year: ");
    scanf("%i", &year);
    printf("\n");

    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                printf("Leap Year\n");
            }
            else
            {
                printf("Not a leap year\n");
            }
        }
        else
        {
            printf("Leap Year\n");
        }
    }
    else
    {
        printf("Not a leap year\n");
    }
    return 0;
}