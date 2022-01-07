#include <stdbool.h>
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
const unsigned int N = 45 * 27;

// Hash table

node *table[N];

// Number of words on dictionary
int counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    int wordIndex = hash(word);
    
    node *checker = malloc(sizeof(node));
    checker = table[wordIndex];

    while (checker != NULL)
    {
        if (strcasecmp(checker->word, word) == 0)
        {
            checker = checker->next;
        }
        return true;
    }
    
    return false;
    
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int wordSum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Lower case words
        wordSum += tolower(word[i]);
    }
    return wordSum % N;
    
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open file dictionary where dict points
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return 1;
    }

    char word[46];
    while (fscanf(dict, "%s", word) != EOF)
    {
        int wordIndex = hash(word);
        
        // New node
        node *newNode = malloc(sizeof(node));
        
        if (newNode == NULL) 
        {
            return 1;
        }

        // Copy word to pointer location
        strcpy(newNode->word, word);
        newNode->next = NULL;
        free(newNode);
        if (table[wordIndex] == NULL)
        {
            table[wordIndex] = newNode;
        }
        else
        {
            newNode->next = table[wordIndex];
            table[wordIndex] = newNode;
        }

        counter++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
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
            free(cursor);
            return true;
        }

        // clean the hashtable
        table[i] = NULL;
    }
    
    return false;
}
