// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 500;

// Hash table
node *table[N];

unsigned int loadedWords = 0;

// Task 4:
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    // (1) Obtain a hash value
    int hashValue = hash(word);

    // (2) Set pointer
    node *cursor_ptr = table[hashValue];

    // (3)

    while (cursor_ptr != NULL)
    {
        if (strcasecmp(word, cursor_ptr->word) == 0)
        {
            return true;
        }
        cursor_ptr = cursor_ptr->next;
    }

    return false;
}

// Task 2: Hash function

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // the hash function will calculate the sum of ASCII values for the first 5 characters if the word has more than 15 characters,
    // and for all other words, it will calculate the sum for the first 3 characters

    int wordLength = strlen(word);
    unsigned long sumOfValues = 0;

    for (int i = 0; i < wordLength; i++)
    {
        if (i < (wordLength > 15 ? 5 : 3))
        {
            sumOfValues += tolower(word[i]);
        }
    }

    return sumOfValues % N;
}

//  Task 1: Load dictionary

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // (1) Open the file
    FILE *dict_file = fopen(dictionary, "r");

    // (2) Check if you can open the file successfully, if not - output a warning message

    if (dict_file == NULL)
    {
        printf("File couldn't open. Please, try again.. %s\n", dictionary);
        return 0;
    }

    // (3) Scan the dictionary file and read strings from it

    // Declare variable, that is an array of word's characters (including space at the end)
    char each_word[LENGTH + 1];

    // Scan document and read all data, until it reaches end of file (EOF)

    while (fscanf(dict_file, "%s", each_word) != EOF)
    {

        node *newNode = malloc(sizeof(node)); // Free up memory for new node

        if (newNode == NULL)
        {
            return 0; // If there isn't enough memory, return false
        }

        // Store each word into a node by copying them
        strcpy(newNode->word, each_word);

        // Determine the linked list index, which should be useed to insert new node
        // Use hash function to find an index
        int hash_indx = hash(each_word);

        // Add a new node to the linked list

        if (table[hash_indx] == NULL) // Sure, that pointers are correctly set
        {
            newNode->next = NULL;
            table[hash_indx] = newNode; // Update the pointer
        }
        else
        {
            newNode->next = table[hash_indx]; // Find correct list
            table[hash_indx] = newNode;       // Add the node
        }

        loadedWords++; // Count loaded words
    }

    fclose(dict_file); // Close the dictionary file
    return true;
}

// Task 3:
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (loadedWords > 0)
    {
        return loadedWords;
    }

    return 0;
}

// Task 5:
// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tempCursor = cursor;
            cursor = cursor->next;
            free(tempCursor);
        }
    }

    return true;
}
