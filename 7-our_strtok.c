#include "shell.h"

/**
 *our_strtok - tokenizes a given string
 *@str: string to be tokenized
 *@delimiters: delimiters used for tokenization of the string
 *Return: tokenized string
 */

char *our_strtok(char *str, const char *delimiters)
{
	char *last_token = NULL;
	char *token_start = last_token;

	if (str != NULL)
	{
		last_token = str;
	} else if (last_token == NULL)
	{
		return (NULL);
	}

	while (*last_token != '\0' && strchr(delimiters, *last_token) != NULL)
	{
		last_token++;
	}

	if (*last_token == '\0')
	{
		return (NULL);
	}


	while (*last_token != '\0' && strchr(delimiters, *last_token) == NULL)
	{
		last_token++;
	}

	if (*last_token != '\0')
	{
		*last_token = '\0';
		last_token++;
	}

	return (token_start);
}
