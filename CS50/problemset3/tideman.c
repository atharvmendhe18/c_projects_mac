#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    int difference;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }
    printf("vote and record prefrences complete\n");

    add_pairs();
    printf("add pair complete\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("winner = %i, loser = %i\n", pairs[i].winner, pairs[i].loser);
    }
    sort_pairs();
    printf("sort pairs complete\n");
    lock_pairs();
    printf("lock pairs complete\n");
    print_winner();
    printf("winner complete\n");
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            printf("%s\n", candidates[i]);
            ranks[rank] = i;
            return true;
            break;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = candidate_count - 1; j > i; j--)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = candidate_count - 1; j > i; j--)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pairs[pair_count].difference = preferences[i][j] - preferences[j][i];
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pairs[pair_count].difference = preferences[j][i] - preferences[i][j];
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    printf("Started sort pairs\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("started 1st for loop for %i time\n", i);
        for (int j = i + 1; j < candidate_count; j++)
        {
            printf("started 2nd for loop %i time\n", j);
            if (pairs[i].difference < pairs[j].difference)
            {
                printf("going through if\n");
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        locked[i][i] = false;
        locked[pairs[i].loser][pairs[i].winner] = false;
        locked[pairs[i].winner][pairs[i].loser] = true;
    }
}

// Print the winner of the election
void print_winner(void)
{
    int f[candidate_count];
    int t[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        int fal = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (!locked[j][i])
            {
                fal++;
            }
            else if (locked[j][i])
            {
                fal--;
            }
        }
        f[i] = fal;
    }

    int max = 0;
    string winner;
    for (int i = 0; i < candidate_count; i++)
    {
        if (f[i] > max)
        {
            winner = candidates[i];
        }
    }
    printf("winner - %s\n", winner);
}
