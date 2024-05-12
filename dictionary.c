 // Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets
const unsigned int TABLE_SIZE = 50000;


node *table[TABLE_SIZE];

// Return
bool check(const char *word)
{

    int index = hash(word);
    node *cursor = table[index];
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
      if (strcasecmp(temp->word,word) == 0)
        {
            return true;
        }
    }
    return false;
}

unsigned int hash(const char *word)
{

    unsigned int hashvalue = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashvalue += tolower(word[i]);
        hashvalue = (hashvalue * tolower(word[i])) % TABLE_SIZE;
    }
    return hashvalue;
}

int counter = 0;
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // Open Dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "There has been an error");
        return false;
    }


    char wordlist[LENGTH + 1];

    while (fscanf(file, "%s", wordlist) != EOF)
    {

        counter++;
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return 1;
        }

        strcpy(newNode->word, wordlist);
        newNode->next = NULL;
        int index = hash(wordlist);
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }

        else
        {

            newNode->next = table[index];
            table[index] = newNode;
        }
    }
    fclose(file);
    return true;
}


// Returns number
unsigned int size(void)
{

    return counter;
}

// Unloads dictionary
bool unload(void)
{

    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
           tmp = cursor;
            cursor = cursor->next;
           free(tmp);
        }
    }
    return true;
}
