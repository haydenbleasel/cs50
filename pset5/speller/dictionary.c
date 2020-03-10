// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

unsigned int words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    // hash the word
    int index = hash(word);

    // access the linked list at that index in the hash table
    node *cursor = table[index];

    // traverse linked list, looking for the word
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // dictionary is a string, a reference to a file -> open the file?
    // store in hash table: an array of linked lists.
    // determine which array to insert into with a hash function: hash()
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    while (1)
    {
        char *word = malloc(LENGTH + 1);

        if (word == NULL)
        {
            break;
        }

        char end = fscanf(file, "%s", word);

        if (end == EOF)
        {
            free(word);
            break;
        }

        int index = hash(word);

        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            free(word);
            break;
        }

        strcpy(n->word, word);

        n->next = table[index];
        table[index] = n;

        free(word);

        words++;

    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for (int i = 0; i < N; i++)
    {

        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        free(cursor);

        if (i == N - 1)
        {
            return true;
        }
    }

    return false;
}
