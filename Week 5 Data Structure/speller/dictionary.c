// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function prototypes
bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
#include <ctype.h>

// Custom case-insensitive strcmp
int my_strcasecmp(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        char c1 = tolower((unsigned char) *s1);
        char c2 = tolower((unsigned char) *s2);

        if (c1 != c2)
        {
            return c1 - c2;
        }
        s1++;
        s2++;
    }
    return tolower((unsigned char) *s1) - tolower((unsigned char) *s2);
}

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int word_counter = 0;

// Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);

    node *cursor = table[hash_value];
    while (cursor != NULL)
    {
        if (my_strcasecmp(cursor->word, word) == 0)
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
    // Simple hash: first letter
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initialize table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    FILE *dict_file = fopen(dictionary, "r");
    if (dict_file == NULL)
    {
        printf("Error while opening dictionary file\n");
        return false;
    }

    char buffer[LENGTH + 1];
    while (fscanf(dict_file, "%s", buffer) != EOF)
    {
        node *new_word = malloc(sizeof(node));
        if (new_word == NULL)
        {
            fclose(dict_file);
            return false;
        }

        strcpy(new_word->word, buffer);
        int hash_value = hash(buffer);

        new_word->next = table[hash_value];
        table[hash_value] = new_word;

        word_counter++;
    }

    fclose(dict_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
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
    }
    return true;
}

