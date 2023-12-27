#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char alphabets[26];
    int alphaCount[26];
    char string[50] = "Hello this is a test of my programmmmmmmmmm";

    // for loop to put alphabets in alphabets array instead of manually putting them and set each value of aplhacount to 0
    for (int i = 97; i <= 122; i++)
    {
        int j = i - 97;
        alphabets[j] = toascii(i);
        alphaCount[j] = 0;
    }

    // comparing and incrementing value of alphacount
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = tolower(string[i]);

        for (int j = 0; j < 26; j++)
        {
            if (string[i] == alphabets[j])
            {
                alphaCount[j]++;
            }
        }
    }

    int mostOccourence = 0;
    char mostOccouredAlpha;
    for (int i = 0; i < 26; i++)
    {
        if (alphaCount[i] > mostOccourence)
        {
            mostOccourence = alphaCount[i];
            mostOccouredAlpha = alphabets[i];
        }
    }

    printf("Most occoured alphabet is %c and it occoured %i times", mostOccouredAlpha, mostOccourence);

    return 0;
}