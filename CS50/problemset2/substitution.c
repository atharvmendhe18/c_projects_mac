// Include a key as a command line argument
// This progam does ciphertext

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int validateIn(int argc, string argv);

int main(int argc, string argv[])
{
    string alphabetsLow = "abcdefghijklmnopqrstuvwxyz";
    string alphabetsCap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char argvLow[26];
    char argvCap[26];
    for (int i = 0; i < 26; i++)
    {
        argvLow[i] = tolower(argv[1][i]);
        argvCap[i] = toupper(argv[1][i]);
    }

    if (validateIn(argc, argv[1]) == 0)
    {
        string userIn = get_string("Plaintext: ");
        int lenString = strlen(userIn);
        char alpha[lenString];

        for (int i = 0; i < lenString; i++)
        {
            alpha[i] = userIn[i];
        }

        for (int i = 0; i < lenString; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (alpha[i] == alphabetsLow[j])
                {
                    alpha[i] = argvLow[j];
                    break;
                }
                else if (alpha[i] == alphabetsCap[j])
                {
                    alpha[i] = argvCap[j];
                    break;
                }
            }
        }
        printf("Ciphertext: ");
        for (int i = 0; i < lenString; i++)
        {
            printf("%c", alpha[i]);
        }
        printf("\n");
    }
}

int validateIn(int argc, string argv)
{
    char userIn[26];
    if (argc != 2)
    {
        printf("Please enter a key");
        return 1;
    }
    else
    {
        if (strlen(argv) != 26)
        {
            printf("A key must have 26 different characters");
            return 1;
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                if (isdigit(argv[i]) == 1)
                {
                    printf("Numbers cannot be in the key");
                    return 1;
                }
            }
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (argv[i] == userIn[j])
                    {
                        printf("characters cannot be repeated in the key");
                        return 1;
                    }
                    else
                    {
                        userIn[j] = argv[i];
                    }
                }
            }
        }
        return 0;
    }
}
