#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char givenString[50] = "This is ora juice";
    char toCheckString[50] = "orange";

    for (int i = 0; i < strlen(givenString); i++)
    {
        givenString[i] = tolower(givenString[i]);
    }

    // to check the outpot of strstr() function
    printf("%s\n", strstr(givenString, toCheckString));

    if (strstr(givenString, toCheckString) != NULL)
    {
        printf("The word orange is present in the string");
        return 0;
    }
    printf("Orange not present in the given string");
    return 1;
}