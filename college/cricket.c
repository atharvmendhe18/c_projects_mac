// Define a structure called cricket that will describe the following information – player’s name,
// country name, best score, and batting average. Develop a program that will store information
// of 10 cricket players around the world using structure. Also, display names of these cricketers
// in descending order with respect to their batting average

#include <stdio.h>

struct player
{
    char name[15];
    char country[15];
    int best_score;
    int batting_average;
};

int main(void)
{
    struct player player[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the name of player %i: ", i + 1);
        scanf("%s", player[i].name);
        printf("\nEnter the players batting averege: ");
        scanf("%i", &player[i].batting_average);
    }

    // perform bubble sort on batting average
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < (9 - i); j++)
        {
            struct player temp;
            if (player[j].batting_average > player[j + 1].batting_average)
            {
                temp = player[j];
                player[j] = player[j + 1];
                player[j + 1] = temp;
            }
        }
    }

    for (int i = 9; i >= 0; i--)
    {
        printf(" Player name - %s   Batting Average - %i\n", player[i].name, player[i].batting_average);
    }
}