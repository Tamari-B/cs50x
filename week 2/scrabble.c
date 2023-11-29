#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)

    {
        printf("Player 2 wins!\n");
    }
    else
    {

        printf("Tie!\n");
    }
}

// Compute score

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int points_indx, score = 0, word_length;

    word_length = strlen(word); 

    for (int i = 0; i < word_length; i++)
    {

        // Find the index in the points array:
        //  step 1: Convert to uppercase each character of the word.
        //  step 2: Then subtract 65 -> the ASCII value of 'A'.

        points_indx = toupper(word[i]) - 65;

        // Check if the index is valid and then calculate the score.

        if (points_indx >= 0 && points_indx < 26)
        {
            score += POINTS[points_indx];
        }
    }

    return score;
}
