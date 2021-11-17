// Implements a dictionary's functionality

#include <stdbool.h>
// Add library
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Dictionary size counter
unsigned int dict_size;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    int check_index = hash(word);

    // Acess linked list at the index in the hash table
    node *check_cursor = table[check_index];

    // Traverse linked list, looking for the word
    while (check_cursor != NULL)
    {
        if (strcasecmp(word, check_cursor->word) == 0)
        {
            return true;
        }
        check_cursor = check_cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hash by adding up ACSII values of all characters in a word
    // Reference: https://research.cs.vt.edu/AVresearch/hashing/strings.php
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file != NULL)
    {
        //Read strings from file one at a time
        char word[LENGTH + 1];
        while (fscanf(file, "%s", word) != EOF)
        {
            // Create a new node for each word
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
            }
            strcpy(n->word, word);

            // Hash word to obtain a hash value
            int load_index = hash(n->word);

            // Insert node into hash table at the location
            n->next = table[load_index];
            table[load_index] = n;
            dict_size++;
        }
        fclose(file);
        return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over hash table
    for (int i = 0; i < N; i++)
    {
        node *unload_cursor = table[i];

        // Loop through linked list
        while (unload_cursor != NULL)
        {
            node *temp = unload_cursor;
            unload_cursor = unload_cursor->next;
            free(temp);
        }
        // check if all the node is freed
        if (unload_cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
