#include "shell.h"

size_t words_count(const char *s, const char *delim)
{
	bool delim_found = true;
	size_t num_words = 0;
	size_t i;

	if (!s || !delim)
		return (0);

	while (*s != '\0')
	{
		/* Loop through s2 to find match */
		for (i = 0; delim[i] && *s != delim[i]; i++)
			;
		if (*s == delim[i])
			delim_found = true;
		else
		{
			if (delim_found)
				num_words++;
			delim_found = false;
		}
		s++;
	}
	return (num_words);
}

char **tokenizer(const char *str, const char *delim)
{
    char *tmp, **tokenized, *token;
    size_t numOfWords, i;

    numOfWords = words_count(str, delim);
    if (numOfWords == 0)
        return (NULL);
    tmp = strdup(str);
    
    /* Allocate space for tokens array */
    tokenized = malloc(sizeof(char *) * (numOfWords + 1));
    if (tokenized == NULL)
        return (NULL);
    
    /* Copy tokens into array */
    token = strtok(tmp, delim);
    for (i = 0; token != NULL; i++)
    {
        tokenized[i] = strdup(token);
        token = strtok(NULL, delim);
    }
    tokenized[i] = NULL;
    free(tmp);
    return (tokenized);
}