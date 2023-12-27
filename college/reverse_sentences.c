// reverse sentenses but not words

#include <stdio.h>
#include <string.h>

int main(void)
{
    char sentence[] = {"hello this is a test of program"};
    char words[20][10];

    int no_words = 0;
    int i = 0;
    int k = 0;

    for (int j = 0; j < strlen(sentence); j++)
    {
        if (sentence[j] == ' ')
        {
            i++;
            k = 0;
            no_words++;
        }
        else
        {
            words[i][k] = sentence[j];
            k++;
        }
    }

    printf("no of words = %i", no_words + 1);

    printf("\n");

    for (int i = no_words + 1; i >= 0; i--)
    {
        for (int j = 0; j < strlen(words[i]); j++)
        {
            printf("%c", words[i][j]);
        }
        printf(" ");
    }
    printf("\n");
    return 0;
}
