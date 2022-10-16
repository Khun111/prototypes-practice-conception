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
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 6760;

// Hash table
node *table[N];
int total = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //Open dictionary file for reading
    FILE *dic = fopen(dictionary, "r");
    //Check if return value is null and return false if unsuccessful
    if (dic == NULL)
    {
        return false;
    }
    //declare string to read into
    char search[LENGTH + 1];
    //read dictionary one word at a time till end
    while (fscanf(dic, "%s", search) != EOF)
    {
        //for each word, create a new node
        node *n = malloc(sizeof(node));
        //check if it's a valid node
        if (n == NULL)
        {
            return false;
        }
        //copy words read into relevant node section
        strcpy(n->word, search);
        //set pointer to null
        n->next = NULL;
        //pass each word into the hash function to know hash index value
        int i = hash(search);
        //Insert the nodes into hash table at relevant locations, checking if bucket is empty and acting accordingly xithout cutting off relevant connections(orphaning)
        if (table[i] == NULL)
        {
            table[i] = n;
        }
        else
        {
            n->next = table[i];
            table[i] = n;
        }
        //note load times to be used later
        total++;
    }
    //close dictionary and return true if all goes welll
    fclose(dic);
    return true;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //declare relevant variabes
    int count = 0;
    int j = 0;
    //iterate through each letter per word, while making provisions for \n
    while (j < strlen(word) + 1)
    {
        //assign a number for each letter and sum it up, while forcing to lower case to preserve consistency
        count += tolower(word[j]) * 26;
        j++;
    }
    //make your the returned sum stays within range
    return count % N;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //return load times for each word gotten from load function
    return total;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //get the hash index of the word via the hash function
    int hashV = hash(word);
    //traverse that linked list, one node at a time, looking for the word. Start with cursor set to the first node
    node *cursor = table[hashV];
    //Keep moving until null
    while (cursor != NULL)
    {
        //if a match is succcessfully found, return true. Enforce case insensitivity
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        //Move to the next
        cursor = cursor->next;
    }
    //else, return false if word isn't there after reaching the end
    return false;
}


// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //iterate over hash table, going over each linked list
    for (int i = 0; i < N; i++)
    {
        //set cursor to first node of table and use it to traverse through
        node *cursor = table[i];
        //keep moving till the last node; until cursor is null
        while (cursor != NULL)
        {
            //to prevent orphaning, create a new variable and make it point to same place as cursor so cursor can be point to the next node just before freeing previous(tmp)
            node *tmp = cursor;
            //set cursor to point to the next node
            cursor = cursor->next;
            //free nodes
            free(tmp);
        }
    }
//return true if successful
    return true;
}