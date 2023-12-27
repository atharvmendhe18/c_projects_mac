#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int calcuLetters(string userInput);
int calculateWhitespace(string userInput);
int calculateSentences(string userInput);
int calculateIndex(int L, int S);

int main(void)
{
    string userIn = get_string("Input: ");

    float letters = calcuLetters(userIn) - calculateWhitespace(userIn);
    printf("letters = %f\n", letters);

    float words = calculateWhitespace(userIn) + 1;
    printf("words = %f\n", words);

    float sentences = calculateSentences(userIn);
    printf("sentences = %f\n", sentences);

    float avgletters = ((letters / words) * 100.00);
    printf("Average Letters = %f\n", avgletters);

    float avgSentences = (sentences / words) * 100.00;
    printf("average sentences = %f\n", avgSentences);

    if (calculateIndex(avgletters, avgSentences) < 1)
    {
        printf("Below 1\n");
    }
    else if (calculateIndex(avgletters, avgSentences) > 16)
    {
        printf("Greater than 16\n");
    }
    else
    {
        printf("Index: %i\n", calculateIndex(avgletters, avgSentences));
    }
}

int calcuLetters(string userInput)
{
    return strlen(userInput);
}

int calculateWhitespace(string userInput)
{
    int whitespace = 0;
    for (int i = 0; i < calcuLetters(userInput) + 1; i++)
    {
        if (isspace(userInput[i]))
        {
            whitespace++;
        }
    }
    return whitespace;
}

int calculateSentences(string userInput)
{
    int sentences = 0;
    for (int i = 0; i < calcuLetters(userInput) + 1; i++)
    { // the code below can be consolidated into one if condition
        if (userInput[i] == '.')
        {
            sentences++;
        }
        else if (userInput[i] == '?')
        {
            sentences++;
        }
        else if (userInput[i] == '!')
        {
            sentences++;
        }
        else
        {
            sentences = sentences + 0;
        }
    }
    return sentences;
}

int calculateIndex(int L, int S)
{
    return 0.0588 * L - 0.296 * S - 15.8;
}
