#include <stdio.h>
#include <string.h>

int main(void)
{
    char user_no[20];
    char numbers[2][20];

    printf("Please enter a decimal number: ");
    scanf("%s", user_no);

    int counter = 0;
    int j = 0, k = 0;

    for (int i = 0; i < strlen(user_no); i++)
    {
        if (user_no[i] == '.')
        {
            numbers[j][k] = '\0';
            j++;
            k = 0;
        }
        else
        {
            numbers[j][k] = user_no[i];
            k++;
        }
    }

    numbers[1][k] = '\0';

    printf("\nNo. of digits before decimal %lu and after decimal %lu \n", strlen(numbers[0]), strlen(numbers[1]));
}