#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO

    // get rezults from each voter

    for (int c = 0; c < candidate_count; c++) // Recall that candidate_count stores the number of candidates in the election.
    {
        if (strcmp(candidates[c].name, name) == 0) // Recall that you can use strcmp to compare two strings.
        {
            preferences[voter][rank] = c; // Recall that preferences[i][j] stores the index of the candidate who is the jth ranked
                                          // preference for the ith voter.
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    for (int v = 0; v < voter_count; v++)
    {
        for (int c = 0; c < candidate_count; c++)
        {
            if (!candidates[preferences[v][c]].eliminated == true)

            {
                candidates[preferences[v][c]].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO

    // If any candidate has more than half of the vote, their name should be printed and the function should return true.
    for (int c = 0; c < candidate_count; c++)
    {
        if (voter_count / 2 < candidates[c].votes)
        {
            printf("%s\n", candidates[c].name);
            return true;
        }
    }

    // If nobody has won the election yet, the function should return false.
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO

    // Return the minimum vote total for any candidate who is still in the election.

    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].eliminated == false && voter_count > candidates[c].votes)
        {
            voter_count = candidates[c].votes;
        }
    }

    return voter_count;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO

    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].votes == min)
        {
            return true;
        }
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].votes == min)
        {
            candidates[c].eliminated = true;
        }
    }
    return;
}