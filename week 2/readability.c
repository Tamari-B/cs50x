#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters, sentences, words = 1, index; // global variables

// 1) Get text from a user
// 2) Count numbers of the letters, sentences, and words.

int collectData(void)
{
    string text = get_string("Text: "); // get text

    // Counts
    for (int c = 0; c < strlen(text); c++)
    {
        int find_sentences = text[c] == '.' || text[c] == '!' || text[c] == '?'; // search pattern for sentences

        if (isalpha(text[c]))
        {
            letters++;
        }
        else if (find_sentences)
        {
            sentences++;
        }
        else if (text[c] == ' ')
        {
            words++;
        }
    }
    return letters;
    return sentences;
    return words;
}

// The Coleman-Liau index

int findIndex(void)
{
    float L = (float) letters / (float) words * 100;   // The average number of letters per 100 words in the text
    float S = (float) sentences / (float) words * 100; // The average number of sentences per 100 words in the text.
    index = round(0.0588 * L - 0.296 * S - 15.8);      // Calculation the Coleman-Liau index
    return index;
}

//  Grades
int getGrade(void)
{

    if (index >= 16)
    {
        printf("Grade 16+\n");
        return true;
    }
    else if (index <= 1)
    {

        printf("Before Grade 1\n");
        return true;
    }
    else
    {
        printf("Grade %i\n", index);
        return true;
    }
}

int main(void)
{
    collectData();
    findIndex();
    getGrade();
}
