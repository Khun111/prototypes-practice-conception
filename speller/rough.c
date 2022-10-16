// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int count = 0;
    int j = 0;
    while (j < strlen(word) + 1)
    {
        count += tolower(word[j]) * 26;
        j++;
    }
    return count % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    node *n = NULL;
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(dic, "%s", word) != EOF)
    {
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;
        int i = hash(word);
        if (table[i] == NULL)
        {
            table[i] = n;
        }
        else
        {
            n->next = table[i];
            table[i] = n;
        }
        total++;
    }
    fclose(dic);
    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashV = hash(word);
    node *cursor = table[hashV];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
        return total;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while ( cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}