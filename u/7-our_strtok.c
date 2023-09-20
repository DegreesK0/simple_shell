#include "shell.h"

/**
 *our_strtok - tokenizes a given string
 *@str: string to be tokenized
 *@delimiters: delimiters used for tokenization of the string
 *Return: tokenized string
 */

char *our_strtok(char *str, const char *delimiters)
{
	char *last_tok_pos = NULL;  /* Stores the last token position */
	const char *delim_char;
	char *start_tok;
	int is_delim;


	if (str != NULL)
		last_tok_pos = str;
	else if (last_tok_pos == NULL)
		return (NULL);  /* No more tokens to extract */

	/*Find the beginning of the token (skip leading delimiters)*/
	for (; *last_tok_pos != '\0'; last_tok_pos++)
	{
		is_delim = 0;
		for (delim_char = delimiters; *delim_char != '\0'; delim_char++)
		{
		if (*last_tok_pos == *delim_char)
		{
			is_delim = 1;
			break;
		}
		}
		if (!is_delim)
		{
			break;
		}
		/* last_tok_pos++; */
	}

	if (*last_tok_pos == '\0')
	{
		return (NULL);  /* No more tokens to extract */
	}

	/* Find the end of the token */
	start_tok = last_tok_pos;
	for (; *last_tok_pos != '\0'; last_tok_pos++)
	{
		is_delim = 0;
		for (delim_char = delimiters; *delim_char != '\0'; delim_char++)
		{
			if (*last_tok_pos == *delim_char)
			{
			    is_delim = 1;
			    break;
			}
		}
		if (is_delim)
		{
			break;
		}
		/* last_tok_pos++; */
	}

	if (*last_tok_pos != '\0')
	{
		*last_tok_pos = '\0';  /* Null-terminate the token */
		last_tok_pos++;
	}

	return (start_tok);
}


